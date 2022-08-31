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

const int N = 5e5 + 5;

vector <int> a[N], g[N];
int s[N], sz[N], parent[N], col[N] = {0}, next_col[N], ans = 1;
bool seen[N] = {0};

// void init_dsu(int n);
// int find_dsu(int i);
// void union_dsu(int i, int j);
void dfs(int i);

int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < s[i]; ++j)
		{
			int x;
			cin >> x;
			a[i].pb(x);
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1);

	// init_dsu(m);
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (s[i] < 2)
	// 		continue;

	// 	int temp = a[i][0];
	// 	for (auto &j : a[i])
	// 		union_dsu(j, temp);
	// }

	// for (int i = 1; i <= m; ++i)
	// 	next_col[i] = 1;

	// int ans = 0;
	// for (int i = 1; i <= m; ++i)
	// {
	// 	if (parent[i] == i)
	// 		ans = max(ans, sz[i]);

	// 	int j = find_dsu(i);
	// 	col[i] = next_col[j];
	// 	next_col[j]++;
	// }

	cout << ans << '\n';
	for (int i = 1; i <= m; ++i)
		cout << max(col[i], 1) << ' ';
}

void dfs(int i)
{
	seen[i] = true;
	set <int> used;
	for (auto &j : a[i])
		if (col[j])
			used.insert(col[j]);

	int temp = 1;
	for (auto &j : a[i])
	{
		if (!col[j])
		{
			while (used.find(temp) != used.end())
				++temp;

			col[j] = temp;
			ans = max(ans, temp);
			++temp;
		}
	}

	for (auto &j : g[i])
		if (!seen[j])
			dfs(j);
}

// void init_dsu(int n)
// {
// 	for (int i = 1; i <= n; ++i)
// 	{
// 		parent[i] = i;
// 		sz[i] = 1;
// 	}
// }

// int find_dsu(int i)
// {
// 	if (parent[i] == i)
// 		return i;

// 	parent[i] = find_dsu(parent[i]);
// 	return parent[i];
// }

// void union_dsu(int i, int j)
// {
// 	int pi = find_dsu(i), pj = find_dsu(j);
// 	if (pi == pj)
// 		return;

// 	if (sz[pi] <= sz[pj])
// 	{
// 		parent[pi] = pj;
// 		sz[pj] += sz[pi];
// 	}

// 	else
// 	{
// 		parent[pj] = pi;
// 		sz[pi] += sz[pj];
// 	}
// }