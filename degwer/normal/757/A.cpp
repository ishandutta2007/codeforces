#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int d[1000];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)d[s[i]]++;
	int ans = 1000000000;
	ans = min(ans, d['B']);
	ans = min(ans, d['u'] / 2);
	ans = min(ans, d['l']);
	ans = min(ans, d['b']);
	ans = min(ans, d['a'] / 2);
	ans = min(ans, d['s']);
	ans = min(ans, d['r']);
	printf("%d\n", ans);
}