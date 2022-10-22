#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

long long dp[MAXN][2];
vector<int> arr(MAXN);
vector<vector<int>> adj(MAXN);

void dfs1(int x, int p)
{
	for (auto &y : adj[x])
	{
		if (y != p)
		{
			dfs1(y, x);
			dp[x][0] += dp[y][0];
			dp[x][1] += dp[y][1];
		}
	}
	dp[x][1] += dp[x][0];
	dp[x][0] += arr[x];
}

void dpmod(int x, int y, int d)
{
	dp[x][0] += d * dp[y][0];
	dp[x][1] += d * (dp[y][0] + dp[y][1]);
}

long long ans = 0;
void dfs2(int x, int p)
{
	dpmod(x, p, 1);
	ans = max(ans, dp[x][1]);
	for (auto &y : adj[x])
	{
		if (y != p)
		{
			dpmod(x, y, -1);
			dfs2(y, x);
			dpmod(x, y, 1);
		}
	}
	dpmod(x, p, -1);
}

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 1; x <= n; x++)
		scanf("%i", &arr[x]);
	for (int x = 1; x < n; x++)
	{
		int a, b;
		scanf("%i%i", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lli\n", ans);
}