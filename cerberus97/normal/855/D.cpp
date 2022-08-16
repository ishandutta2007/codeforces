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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, LOG2_N = log2(N) + 10;

vector <int> parts[N], sc[N];
bool seen[N] = {0};
int in_degree[N] = {0}, level_parts[N], level_sc[N], parent_parts[N][LOG2_N], parent_sc[N][LOG2_N];

void dfs(vector <int> *tree, int parent[N][LOG2_N], int *level, int v, int l, int p);
int find_lca(int parent[N][LOG2_N], int *level, int u, int v);
bool part_of(int u, int v, int parent[N][LOG2_N], int* level);
int largest_parent(int v, int parent[N][LOG2_N]);

int main()
{
	fast_cin();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int par, typ;
		cin >> par >> typ;
		if (typ == 1)
		{
			// cout << par << ' ' << i << endl;
			parts[par].pb(i);
		}
		else if (typ == 0)
		{
			// cout << i << ' ' << par << endl;
			sc[par].pb(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
			dfs(sc, parent_sc, level_sc, i, 0, -1);
	}

	memset(seen, 0, sizeof(seen));
	for (int i = 1; i <= n; ++i)
	{
		// cout << in_degree[i] << ' ';
		if (!seen[i])
			dfs(parts, parent_parts, level_parts, i, 0, -1);		
	}

	// cout << parent_sc[2][0] << endl;

	int q;
	cin >> q;
	while (q--)
	{
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1)
		{
			if (part_of(u, v, parent_sc, level_sc))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			// cout << u << ' ' << v << ' ' << largest_parent(u, parent_sc) << endl;
			if (part_of(u, v, parent_parts, level_parts))
				cout << "YES\n";

			else if (part_of(v, u, parent_sc, level_sc))
				cout << "NO\n";

			else if (part_of(largest_parent(u, parent_sc), v, parent_parts, level_parts))
				cout << "YES\n";

			else if (part_of(largest_parent(v, parent_parts), u, parent_sc, level_sc))
				cout << "YES\n";

			else
				cout << "NO\n";
		}
	}
}

void dfs(vector <int> *tree, int parent[N][LOG2_N], int *level, int v, int l, int p)
{
	seen[v] = true;
	level[v] = l;
	parent[v][0] = p;
	for (int j = 1; j < LOG2_N; ++j)
		parent[v][j] = ((parent[v][j - 1] == -1) ? -1 : parent[parent[v][j - 1]][j - 1]);

	for (auto &i : tree[v])
		if (!seen[i])
			dfs(tree, parent, level, i, l + 1, v);
}

int find_lca(int parent[N][LOG2_N], int *level, int u, int v)
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

bool part_of(int u, int v, int parent[N][LOG2_N], int* level)
{
	return (u != v) and (find_lca(parent, level, u, v) == u);
}

int largest_parent(int v, int parent[N][LOG2_N])
{
	for (int i = LOG2_N - 1; i >= 0; --i)
		if (parent[v][i] != -1)
			v = parent[v][i];

	return v;
}