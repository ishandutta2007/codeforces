/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, C = 30;

bool is_good[C] = {0};
string s;

bool match(string t, int n);

int main()
{
	string good;
	cin >> good >> s;
	for (auto &i : good)
		is_good[i - 'a'] = true;

	int n = s.length(), q;
	cin >> q;
	while (q--)
	{
		string t;
		cin >> t;
		if (match(t, n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

bool match(string t, int n)
{
	int m = t.length();
	int i = 0, j = 0;
	while (i < n and j < m)
	{
		if (s[i] == '*')
		{
			while (n - 1 - i <= m - 1 - j and j < m and !is_good[t[j] - 'a'])
				++j;

			++i;
		}

		else if (s[i] == '?')
		{
			if (!is_good[t[j] - 'a'])
				return false;

			++i;
			++j;
		}

		else
		{
			if (s[i] != t[j])
				return false;

			++i;
			++j;
		}
	}

	if (i < n and s[i] == '*')
		++i;

	if (i == n and j == m)
		return true;

	return false;
}