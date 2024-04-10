#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	map <string, int> a;
	a["monday"] = 0;
	a["tuesday"] = 1;
	a["wednesday"] = 2;
	a["thursday"] = 3;
	a["friday"] = 4;
	a["saturday"] = 5;
	a["sunday"] = 6;
	string s1, s2;
	cin >> s1 >> s2;
	int ans = (a[s2] - a[s1] + 7) % 7;
	if (ans == 0 || ans == 2 || ans == 3)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}