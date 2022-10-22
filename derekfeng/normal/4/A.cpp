#include <bits/stdc++.h> 
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
using namespace std;
void cprintf(char* str, WORD color, ...);
int main(){
    int n;
    cin>>n;
    if(n>2 && n%2==0){
    	cprintf("Y",10);
    	cprintf("E",9);
    	cprintf("S",8);
	}else puts("NO");
}
void cprintf(char* str, WORD color, ...) {
	WORD colorOld;
	HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	colorOld = csbi.wAttributes;
	SetConsoleTextAttribute(handle, color);
	cout << str;
	SetConsoleTextAttribute(handle, colorOld);
}