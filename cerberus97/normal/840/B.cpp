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

const int N = 3e5 + 10;

int d[N], deg[N] = {0}, parent[N];
bool seen[N] = {0};
vector <pii> g[N], g2[N];
vector <int> edge_set;

void bfs(int root);
void solve(int cur, int par_edge);

int main()
{
	int n, m, root = 0, odd = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
		if (d[i] == 1)
			++odd;

		else if (d[i] == -1)
			root = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}

	if (!root and odd % 2)
	{
		cout << -1;
		return 0;
	}

	if (!root)
		root = 1;

	bfs(root);
	solve(root, -1);
	sort(edge_set.begin(), edge_set.end());
	cout << edge_set.size() << endl;
	for (auto &i : edge_set)
		cout << i << endl;
}

void bfs(int root)
{
	seen[root] = true;
	parent[root] = -1;
	queue <int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto &i : g[cur])
		{
			if (!seen[i.first])
			{
				seen[i.first] = true;
				parent[i.first] = cur;
				g2[cur].pb(i);
				q.push(i.first);
			}
		}
	}
}

void solve(int cur, int par_edge)
{
	for (auto &i : g2[cur])
		solve(i.first, i.second);

	if (d[cur] == -1 or deg[cur] % 2 == d[cur])
		return;

	++deg[cur];
	edge_set.pb(par_edge);
	++deg[parent[cur]];
}