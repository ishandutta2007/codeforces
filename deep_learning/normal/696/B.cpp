#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int fa[100005], lst[100005], pre[100005], to[100005], tot, sz[100005]; 
double dp[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	sz[u] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		dfs(to[i]); 
		sz[u] += sz[to[i]]; 
	}
}
int main()
{
	// freopen("B.in", "r", stdin);
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		scanf("%d", fa + i); 
		add_edge(--fa[i], i); 
	}
	dfs(0); 
	for (int i = 0; i < n; i++)
	{
		if (!i)
			dp[i] = 1; 
		else
			dp[i] = (double)(sz[fa[i]] - sz[i] - 1) / 2 + dp[fa[i]] + 1;
		printf("%.8lf%c", dp[i], " \n"[i + 1 == n]);
	}
	return 0; 
}