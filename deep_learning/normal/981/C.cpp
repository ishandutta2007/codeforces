#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
int lst[100005], to[200005], pre[200005], deg[100005], tot; 
int ans[100005], len; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	deg[u]++; 
	lst[u] = tot++; 
}
int dfs(int u, int fa = -1)
{
	if (deg[u] > 2)
	{
		puts("No"); 
		exit(0); 
	}
	int res = u; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa)
			continue; 
		res = dfs(to[i], u); 
	}
	return res; 
}
int main()
{
	// freopen("981C.in", "r", stdin); 
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
	int u = std::max_element(deg, deg + n) - deg; 
	for (int i = lst[u]; ~i; i = pre[i])
		ans[len++] = dfs(to[i], u); 
	puts("Yes"); 
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
		printf("%d %d\n", u + 1, ans[i] + 1);
	return 0; 
}