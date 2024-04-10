#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
int n, k, lst[105], to[205], pre[205], tot;
ll dp[105][45], tmp[45]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	dp[u][0] = 1; 
	dp[u][k + 1] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		int v = to[i]; 
		if (v == fa)
			continue; 
		dfs(v, u); 
		memset(tmp, 0, sizeof(tmp)); 
		for (int j = 0; j <= k * 2 + 1; j++)
		{
			for (int x = 0; x <= k * 2; x++)
			{
				if (j + x <= k * 2)
					(tmp[min(j, x + 1)] += dp[u][j] * dp[v][x]) %= MOD; 
				else
					(tmp[max(j, x + 1)] += dp[u][j] * dp[v][x]) %= MOD; 
			}
		}
		memcpy(dp[u], tmp, sizeof(tmp)); 
	}
}
int main()
{
	// freopen("C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	scanf("%d%d", &n, &k); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	dfs(0); 
	ll ans = 0; 
	for (int i = 0; i <= k; i++)
		(ans += dp[0][i]) %= MOD; 
	printf("%lld\n", ans);
	return 0; 
}