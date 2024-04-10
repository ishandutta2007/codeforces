#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string z = "aiueo13579";
int main()
{
	string s;
	cin >> s;
	int r = 0;
	for (int i = 0; i < s.size(); i++)for (int j = 0; j < 10; j++)r += s[i] == z[j];
	printf("%d\n", r);
}