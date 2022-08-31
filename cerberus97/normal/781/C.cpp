/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "cassert"
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

vector <int> order, g[N];
bool seen[N] = {0};

void dfs(int cur);
int ceil_div(int x, int y);

int main()
{
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	order.pb(1);
	dfs(1);
	memset(seen, 0, sizeof(seen));
	int total = 0, ctr = 0;
	while (ctr < n)
	{
		if (!seen[order[total]])
		{
			seen[order[total]] = true;
			++ctr;
		}

		++total;
	}

	int allowed = ceil_div(2*n, k);
	assert(k * allowed >= total);

	int x = 0;
	for (int i = 1; i <= k; ++i)
	{
		if (x == total)
			cout << "1 1\n";

		else
		{
			int y = min(x + allowed - 1, total - 1);
			cout << y - x + 1 << ' ';
			for (int j = x; j <= y; ++j)
				cout << order[j] << ' ';

			cout << endl;
			x = y + 1;
		}
	}
}

void dfs(int cur)
{
	seen[cur] = true;
	for (auto &i : g[cur])
	{
		if (!seen[i])
		{
			order.pb(i);
			dfs(i);
			order.pb(cur);
		}
	}
}

int ceil_div(int x, int y)
{
	if (x % y)
		return x/y + 1;

	return x/y;
}