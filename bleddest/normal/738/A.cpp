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
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const long long INFLL = 1e18;
const int INF = 1e9;

bool change(string& s)
{
	if (s.find("ogo") == -1)
		return false;
	string t;
	int z = s.find("ogo");
	for (int i = 0; i < z; i++)
	{
		t.push_back(s[i]);
	}
	t += "***";
	z += 3;
	while (z + 1 < s.size() && s[z] == 'g' && s[z + 1] == 'o')
		z += 2;
	for (int i = z; i < s.size(); i++)
		t.push_back(s[i]);
	s = t;
	return true;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	string s;
	cin >> n >> s;
	while (change(s)) {};
	cout << s;
	return 0;
}