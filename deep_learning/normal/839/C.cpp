#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int lst[100005], to[200005], pre[200005], dep[100005], deg[100005], tot; 
double dp[100005];  
inline void add_edge(int u, int v)
{
	deg[u]++; 
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		dp[to[i]] = dp[u] / deg[u]; 
		dep[to[i]] = dep[u] + 1; 
		dfs(to[i], u); 
	}
}
int main()
{
	// freopen("839C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v);
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	for (int i = 1; i < n; i++)
		deg[i]--; 
	dp[0] = 1; 
	dfs(0); 
	double ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if (!deg[i])
			ans += dp[i] * dep[i]; 
	}
	printf("%.8lf\n", ans);
	return 0; 
}