// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;
char input;

//Input Check is used to collect the input and ensure that it is either y or n. It will loop until either y or n are inputed
void input_check(char in) {
	std::cout << "Do You Wish to Lock the Application(Y for Yes, N for No)";
	char yesOrNo;
	cin >> yesOrNo;
	yesOrNo = toupper(yesOrNo);
	while (yesOrNo != 'Y' && yesOrNo != 'N')
	{
		cout << "Error invalid input please try again " << std::endl;
		cout << "Please enter [Y/N]: ";
		cin >> yesOrNo;
		yesOrNo = toupper(yesOrNo);
	}
		cout << "You entered " << yesOrNo << std::endl;
		input = yesOrNo;
}

//If the input selected was "y" then the function will lock, or keep locked, the window and prevent any changes in the application
//If the input select was "n" then the function will unlock, or keep unlocked, the window and allow chanes in the application
void lock_screen(char y_or_n) {
	if (y_or_n == 'Y' || y_or_n == 'y') {
		HWND parent = FindWindow(NULL, TEXT("iC-MHL200 12 Bit Hall Linear Encoder"));
		if (parent == NULL) {
			cout << "Window not Open" << endl;
		}
		else {
			cout << "Window Open" << endl;
			EnableWindow(parent, FALSE);//Locking Window
		}

		HWND child = FindWindowEx(parent, NULL, NULL, TEXT("Write RAM"));
		if (child == NULL) {
			cout << "Write RAM Button Not Found." << endl;
		}
		else {
			cout << "RAM Button Found" << endl;
			EnableWindow(child, TRUE);
		}
	}

	if (y_or_n == 'N' || y_or_n == 'n') {
		HWND parent = FindWindow(NULL, TEXT("iC-MHL200 12 Bit Hall Linear Encoder"));
		if (parent == NULL) {
			cout << "Window not Open" << endl;
		}
		else {
			cout << "Window Open" << endl;
			EnableWindow(parent, TRUE);//Unlocking Window
		}
	}

}
int main()
{
	input_check(input);	
	lock_screen(input);		
	
	return 0;
	}
//hWndsChild = FindWindowEx(IntPtr)hWnd, Intptr.Zero, "Button", "Analog/ Test")
	//EnableWindow("iC-MHL200 12 Bit Hall Linear Encoder", FALSE);



