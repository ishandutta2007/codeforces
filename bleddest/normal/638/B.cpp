#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int succ[26];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < 26; i++)
		succ[i] = -1;
	int n;
	cin >> n;
	vector<bool> used(26);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
			used[s[i] - 'a'] = 1;
		for (int i = 1; i < s.size(); i++)
			succ[s[i - 1] - 'a'] = s[i] - 'a';
	}
	set<int> begin;
	for (int i = 0; i < 26; i++)
		if (used[i])
			begin.insert(i);
	for (int i = 0; i < 26; i++)
		begin.erase(succ[i]);
	for (auto i = begin.begin(); i != begin.end(); i++)
	{
		int k = *i;
		while (succ[k] != -1)
		{
			cout << char('a' + k);
			k = succ[k];
		}
		cout << char('a' + k);
	}
}