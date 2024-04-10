#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16, MAXM = 10005;

int arr[MAXM][MAXN];
int adj[MAXN][MAXN];
int aux[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
bool vis[1 << MAXN][MAXN];

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			scanf("%i", &arr[y][x]);
	for (int x = 0; x < n; x++)
	{
		for (int y = x + 1; y < n; y++)
		{
			adj[x][y] = abs(arr[0][x] - arr[0][y]);
			for (int z = 1; z < m; z++)
				adj[x][y] = min(adj[x][y], abs(arr[z][x] - arr[z][y]));
			adj[y][x] = adj[x][y];
		}
	}
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			aux[x][y] = INT_MAX;
			for (int z = 1; z < m; z++)
				aux[x][y] = min(aux[x][y], abs(arr[z][x] - arr[z - 1][y]));
		}
	}
	int ans = 0;
	queue<pair<int, int>> buf;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < 1 << n; y++)
			for (int z = 0; z < n; z++)
				dp[y][z] = 0;
		dp[1 << x][x] = INT_MAX;
		buf.push({1 << x, x});
		while (!buf.empty())
		{
			int t = buf.front().first, x = buf.front().second;
			buf.pop();
			for (int y = 0; y < n; y++)
			{
				int s = (1 << y) | t;
				if (s != t && dp[s][y] < min(dp[t][x], adj[x][y]))
				{
					dp[s][y] = min(dp[t][x], adj[x][y]);
					if (!vis[s][y])
					{
						buf.push({s, y});
						vis[s][y] = true;
					}
				}
			}
			vis[t][x] = false;
		}
		for (int y = 0; y < n; y++)
			ans = max(ans, min(dp[(1 << n) - 1][y], aux[x][y]));
	}
	printf("%i\n", ans);
}