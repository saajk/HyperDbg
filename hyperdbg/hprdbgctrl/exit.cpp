/**
 * @file exit.cpp
 * @author Sina Karvandi (sina@rayanfam.com)
 * @brief exit command
 * @details
 * @version 0.1
 * @date 2020-05-27
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#include "pch.h"

//
// Global Variables
//
extern bool g_IsConnectedToDebugger;
extern bool g_IsDebuggerModulesLoaded;

void CommandExitHelp() {
  ShowMessages(
      "exit : unload and uninstalls the drivers and closes the debugger.\n\n");
  ShowMessages("syntax : \texit\n");
}
void CommandExit(vector<string> SplittedCommand) {

  if (SplittedCommand.size() != 1) {
    ShowMessages("incorrect use of 'exit'\n\n");
    CommandExitHelp();
    return;
  }

  //
  // unload and exit
  //
  if (g_IsDebuggerModulesLoaded) {
    HyperdbgUnload();

    //
    // Installing Driver
    //
    if (HyperdbgUninstallDriver()) {
      ShowMessages("Failed to uninstall driver\n");
    }
  }

  exit(0);
}