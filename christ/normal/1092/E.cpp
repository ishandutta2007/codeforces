#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

vector<int> par(MAXN), dist(MAXN);
vector<vector<int>> adj(MAXN);

int far = 0;
void dfs(int x, int p, int d)
{
	if (d >= dist[far])
		far = x;
	dist[x] = d;
	par[x] = p;
	for (auto &y : adj[x])
		if (p != y)
			dfs(y, x, d + 1);
}

vector<pair<int, int>> trees;

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);
	for (int x = 0; x < m; x++)
	{
		int a, b;
		scanf("%i%i", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int x = 1; x <= n; x++)
	{
		if (par[x] == 0)
		{
			far = 0;
			dfs(x, x, 0);
			int y = far;
			far = 0;
			dfs(y, y, 0);
			y = far;
			int dy = dist[y], hdy = dist[y] / 2;
			for (int z = 0; z < hdy; z++)
				y = par[y];
			trees.push_back({dy, y});
		}
	}
	sort(trees.begin(), trees.end());
	if (trees.size() == 1)
	{
		printf("%i\n", dist[far]);
		return 0;
	}
	int x = trees.size() - 1;
	int lena = trees[x].first, lenb = trees[x - 1].first;
	int len = max(lena, max(lena - lena / 2, lena / 2) + 1 + max(lenb - lenb / 2, lenb / 2));
	if (trees.size() > 2)
		len = max(lena, max(trees[x - 2].first / 2, trees[x - 2].first - trees[x - 2].first / 2) + 2 + max(lenb - lenb / 2, lenb / 2));
	for (int y = 0; y < x; y++)
	{
		adj[trees[x].second].push_back(trees[y].second);
		adj[trees[y].second].push_back(trees[x].second);
	}
	far = 0;
	dfs(1, 0, 0);
	int y = far;
	far = 0;
	dfs(y, 0, 0);
	len = dist[far];
	printf("%i\n", len);
	for (int y = 0; y < x; y++)
		printf("%i %i\n", trees[x].second, trees[y].second);
}