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

const int N = 1e5 + 10, M = 2e6 + 10;

char s[M];
bool seen[M] = {0};
string t[N];
int k[N], m[N], st[M];

int main()
{
	fast_cin();
	int n, len = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> k[i];
		m[i] = t[i].size();
		for (int j = 0; j < k[i]; ++j)
		{
			int x;
			cin >> x;
			--x;
			len = max(len, x + m[i]);
			if (!seen[x] or m[st[x]] < m[i])
			{
				seen[x] = true;
				st[x] = i;
			}
		}
	}

	int cur = -1, pos = 0;
	for (int i = 0; i < len; ++i)
	{
		if (seen[i])
		{
			if (cur == -1 or m[st[i]] > m[cur] - pos)
			{
				cur = st[i];
				pos = 0;
			}
		}

		if (cur == -1)
			s[i] = 'a';

		else
			s[i] = t[cur][pos++];

		if (pos >= m[cur])
			cur = -1;
	}

	s[len] = 0;
	cout << s;
}