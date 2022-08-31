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

const int N = 1e5 + 10, LOG2_N = log2(N) + 10;

vector <int> tree[N];
int level[N], parent[N][LOG2_N];
bool seen[N] = {0};

int solve(int s, int t, int f);
void dfs(int v, int l, int p);
int find_lca(int u, int v);

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		tree[i].pb(p);
		tree[p].pb(i);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < LOG2_N; ++j)
			parent[i][j] = -1;

	dfs(1, 0, -1);
	while (q--)
	{
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		ans = max(ans, solve(a, b, c));
		ans = max(ans, solve(a, c, b));
		ans = max(ans, solve(b, a, c));
		ans = max(ans, solve(b, c, a));
		ans = max(ans, solve(c, b, a));
		ans = max(ans, solve(c, a, b));
		cout << ans + 1 << '\n';
	}
}

int solve(int s, int t, int f)
{
	int l1 = find_lca(s, f), l2 = find_lca(t, f), l3 = find_lca(s, t);
	if (l1 == l2)
	{
		if (level[l1] < level[f] and level[l2] < level[f])
			return level[f] - level[l1] + level[l3] - level[l1];

		if (level[l1] == level[f] and level[l2] == level[f])
			return level[l3] - level[f];

		return 0;
	}

	if (level[l1] < level[f] and level[l2] < level[f])
		return level[f] - max(level[l1], level[l2]);

	return 0;
}

void dfs(int v, int l, int p)
{
	seen[v] = true;
	level[v] = l;
	parent[v][0] = p;
	for (int j = 1; parent[v][j - 1] != -1; ++j)
		parent[v][j] = parent[parent[v][j - 1]][j - 1];

	for (auto &i : tree[v])
		if (!seen[i])
			dfs(i, l + 1, v);
}

int find_lca(int u, int v)
{
	if (level[u] > level[v])
		swap(u, v);

	for (int j = LOG2_N - 1; j >= 0; --j)
		if (level[v] - level[u] >= (1 << j))
			v = parent[v][j];

	if (u == v)
		return u;

	for (int j = LOG2_N - 1; j >= 0; --j)
	{
		if (parent[u][j] != parent[v][j] and parent[u][j] != -1)
		{
			u = parent[u][j];
			v = parent[v][j];
		}
	}

	return parent[u][0];
}