#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std; 
int ans = 1, col[300005]; 
vector<int> vec[300005]; 
int lst[300005], to[600005], pre[600005], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
inline bool comp(int x, int y)
{
	return col[x] < col[y]; 
}
void dfs(int u, int fa = -1)
{
	sort(vec[u].begin(), vec[u].end(), comp); 
	int cur = ans, pos = (int)vec[u].size() - 1; 
	for (int i = 0; i < vec[u].size() && !col[vec[u][i]]; i++)
	{
		while (pos >= 0 && cur == col[vec[u][pos]])
		{
			pos--; 
			cur--; 
		}
		col[vec[u][i]] = cur--; 
	}
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] != fa)
			dfs(to[i], u); 
	}
}
int main()
{
	// freopen("804C.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		int cnt; 
		scanf("%d", &cnt); 
		ans = max(ans, cnt); 
		for (int j = 0; j < cnt; j++)
		{
			int x; 
			scanf("%d", &x); 
			vec[i].pb(--x); 
		}
	}
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	dfs(0); 
	printf("%d\n", ans);
	for (int i = 0; i < m; i++)
		printf("%d%c", max(col[i], 1), " \n"[i + 1 == m]);
	return 0; 
}