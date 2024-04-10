#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int tot, n, son[3000005][26], sz[3000005], dep[3000005], ans[300005]; 
int merge(int x, int y)
{
	if (x == -1 || y == -1)
		return x + y + 1; 
	int new_node = tot++; 
	sz[new_node] = 1; 
	for (int i = 0; i < 26; i++)
	{
		son[new_node][i] = merge(son[x][i], son[y][i]); 
		sz[new_node] += sz[son[new_node][i]]; 
	}
	return new_node; 
}
void dfs(int u)
{
	sz[u] = 1; 
	for (int i = 0; i < 26; i++)
	{
		if (son[u][i] == -1)
			continue; 
		dep[son[u][i]] = dep[u] + 1;
		dfs(son[u][i]); 
		sz[u] += sz[son[u][i]]; 
	}
	ans[dep[u]] += sz[u]; 
	tot = n; 
	int cur = -1; 
	for (int i = 0; i < 26; i++)
		cur = merge(cur, son[u][i]); 
	ans[dep[u]] -= max(sz[cur], 1); 
}
int main()
{
	// freopen("778C.in", "r", stdin); 
	memset(son, -1, sizeof(son)); 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		char c; 
		scanf("%d%d %c", &u, &v, &c); 
		son[--u][c - 'a'] = --v; 
	}
	dfs(0); 
	int mx = 0, pos; 
	for (int i = 0; i < n; i++)
	{
		if (ans[i] > mx)
		{
			mx = ans[i]; 
			pos = i; 
		}
	}
	printf("%d\n%d\n", n - mx, pos + 1);
	return 0; 
}