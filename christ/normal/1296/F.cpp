#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

vector<pair<int, int>> adj[MAXN];
vector<int> h(MAXN), par(MAXN), scen(MAXN), idx(MAXN), ans(MAXN);
vector<pair<int, pair<int, int>>> path;

void dfs(int u, int p, int i)
{
	par[u] = p;
	h[u] = h[p]+1;
	idx[u] = i;
	for (auto &x : adj[u])
		if (x.first != p)
			dfs(x.first, u, x.second);
}

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 0; x < n - 1; x++)
	{
		int u, v;
		scanf("%i%i", &u, &v);
		adj[u].push_back(make_pair(v, x));
		adj[v].push_back(make_pair(u, x));
	}
	dfs(1, 1, -1);
	int m;
	scanf("%i", &m);
	for (int x = 0; x < m; x++)
	{
		int a, b, g;
		scanf("%i%i%i", &a, &b, &g);
		path.push_back(make_pair(g, make_pair(a, b)));
	}
	sort(path.begin(), path.end());
	for (int x = m - 1; x >= 0; x--)
	{
		int g = path[x].first, a = path[x].second.first, b = path[x].second.second;
		int cnt = 0;
		while (a != b)
		{
			if (h[a] < h[b])
				swap(a, b);
			if (scen[a] <= g)
			{
				scen[a] = g;
				cnt++;
			}
			a = par[a];
		}
		if (cnt == 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int x = 2; x <= n; x++)
		ans[idx[x]] = scen[x] == 0 ? 1000000 : scen[x];
	for (int x = 0; x < n - 1; x++)
		printf("%i ", ans[x]);
	printf("\n");
}