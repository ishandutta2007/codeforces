#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std; 
int lst[1000005], to[10000005], pre[10000005], tot; 
int son[1000005][30], cnt, dp[1000005][2]; 
char inp[1000005]; 
bool vis[1000005]; 
string str[1000005]; 
inline int new_node()
{
	for (int i = 0; i < 30; i++)
		son[cnt][i] = -1; 
	return cnt++; 
}
inline void add_edge(int u, int v)
{
	// cout << u << " " << v << endl; 
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	vis[u] = true; 
	dp[u][0] = 0; 
	dp[u][1] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == fa || vis[to[i]])
			continue; 
		dfs(to[i], u); 
		dp[u][0] += max(dp[to[i]][1], dp[to[i]][0]); 
		dp[u][1] += dp[to[i]][0]; 
	}
}
int main()
{
	// freopen("856B.in", "r", stdin); 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		int n; 
		scanf("%d", &n); 
		cnt = 1; 
		tot = 0; 
		memset(son[0], -1, sizeof(son[0])); 
		for (int i = 0; i < n; i++)
		{
			scanf("%s", inp); 
			str[i] = inp; 
			int len = strlen(inp), cur = 0; 
			for (int j = 0; j < len; j++)
			{
				if (son[cur][inp[j] - 'a'] == -1)
					son[cur][inp[j] - 'a'] = new_node(); 
				cur = son[cur][inp[j] - 'a']; 
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			lst[i] = -1; 
			vis[i] = false; 
		}
		for (int i = 0; i < n; i++)
		{
			int len = str[i].size(); 
			int u = 0, v = 0; 
			for (int j = 0; j < len; j++)
			{
				u = son[u][str[i][j] - 'a']; 
				if (j)
				{
					v = son[v][str[i][j] - 'a']; 
					if (v == -1)
						break; 
					add_edge(v, u); 
					add_edge(u, v); 
				}
			}
		}
		int ans = 0; 
		for (int i = 1; i < cnt; i++)
		{
			if (!vis[i])
			{
				dfs(i); 
				ans += max(dp[i][0], dp[i][1]); 
			}
		}
		printf("%d\n", ans);
	}
	return 0; 
}