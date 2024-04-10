#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<bool> col(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> dp(MAXN), ans(MAXN);

int dfs1(int x, int p)
{
	dp[x] = col[x] ? 1 : -1;
	for(auto &y : adj[x])
		if(y != p)
			dp[x] += max(0, dfs1(y, x));
	return dp[x];
}

void dfs2(int x, int p)
{
	dp[x] += max(0, dp[p]);
	ans[x] = dp[x];
	for(auto &y : adj[x])
	{
		if(y != p)
		{
			dp[x] -= max(0, dp[y]);
			dfs2(y, x);
			dp[x] += max(0, dp[y]);
		}
	}
	dp[x] -= max(0, dp[p]);
}

int main()
{
	int n;
	scanf("%i", &n);
	for(int x = 1; x <= n; x++)
	{
		int b;
		scanf("%i", &b);
		col[x] = b;
	}
	for(int x = 1; x < n; x++)
	{
		int a, b;
		scanf("%i%i", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int x = 1; x <= n; x++)
		printf("%i ", ans[x]);
	printf("\n");
}