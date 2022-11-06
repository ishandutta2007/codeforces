#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
ll dp[5005][5005][2]; 
int c[5005], d[5005], sz[5005];
int lst[5005], to[5005], pre[5005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	sz[u] = 1; 
	dp[u][0][0] = 0; 
	dp[u][1][0] = c[u]; 
	dp[u][1][1] = c[u] - d[u]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		int v = to[i]; 
		dfs(v); 
		for (int j = sz[u]; j >= 0; j--)
		{
			for (int k = 0; k <= sz[v]; k++)
			{
				dp[u][j + k][0] = min(dp[u][j + k][0], dp[u][j][0] + dp[v][k][0]); 
				if (j)
					dp[u][j + k][1] = min(dp[u][j + k][1], dp[u][j][1] + min(dp[v][k][0], dp[v][k][1])); 
			}
		}
		sz[u] += sz[v]; 
	}
}
int main()
{
	// freopen("C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, b; 
	scanf("%d%d", &n, &b); 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d%d", c + i, d + i); 
		if (i)
		{
			scanf("%d", &x); 
			add_edge(--x, i); 
		}
	}
	memset(dp, 0x3f, sizeof(dp)); 
	dfs(0); 
	int ans = 0; 
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 		printf("%d-%d%c", dp[i][j][0], dp[i][j][1], " \n"[j == n]);
	// }
	for (int i = 0; i <= n; i++)
	{
		if (min(dp[0][i][0], dp[0][i][1]) <= b)
			ans = i; 
	}
	printf("%d\n", ans);
	return 0; 
}