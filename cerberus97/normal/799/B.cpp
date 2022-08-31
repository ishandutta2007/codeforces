/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int p[N], a[N], b[N];
set <pii> s[4];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 1; i <= n; ++i)
	{
		s[a[i]].insert({p[i], i});
		s[b[i]].insert({p[i], i});
	}

	int m;
	cin >> m;
	while (m--)
	{
		int x;
		cin >> x;
		if (s[x].empty())
			cout << "-1 ";

		else
		{
			cout << s[x].begin()->first << ' ';
			int i = s[x].begin()->second;
			s[a[i]].erase({p[i], i});
			s[b[i]].erase({p[i], i});
		}
	}
}