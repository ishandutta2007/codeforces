#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> deg(MAXN), ans(MAXN);
vector<vector<pair<int, int>>> adj(MAXN);

int msz;

void dfs(int u, int p, int c)
{
	int n = adj[u].size();
	for (auto &x : adj[u])
	{
		int v = x.first, i = x.second;
		if(v != p)
		{
			if(n <= msz)
				c = (c + 1) % msz;
			dfs(v, u, c);
			ans[i] = c;
		}
	}
}

int main()
{
	int n, k;
	scanf("%i%i", &n, &k);
	for (int x = 1; x < n; x++)
	{
		int a, b;
		scanf("%i%i", &a, &b);
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	for (int x = 1; x <= n; x++)
		deg[x] = adj[x].size();
	deg[0] = deg[n];
	sort(deg.begin(), deg.begin() + n);
	deg[n] = deg[n - 1];
	int x = n - k;
	if(deg[x] != deg[x - 1])
		--x;
	msz = deg[x];
	printf("%i\n", msz);
	dfs(1, 1, msz - 1);
	for (int x = 1; x < n; x++)
		printf("%i ", ans[x] + 1);
	printf("\n");
}