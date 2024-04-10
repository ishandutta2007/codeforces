#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	string s, t;
	cin >> a >> b >> s >> t;
	int r = -1;
	for (int i = 0; i < s.size(); i++)if (s[i] == '*')r = i;
	if (r == -1)
	{
		printf(s == t ? "YES\n" : "NO\n");
	}
	else
	{
		bool f = true;
		f &= a <= b + 1;
		for (int i = 0; i < r; i++)f &= s[i] == t[i];
		for (int i = r + 1; i < s.size(); i++)f &= s[i] == t[i + b - a];
		printf(f ? "YES\n" : "NO\n");
	}
}