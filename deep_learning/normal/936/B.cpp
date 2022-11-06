#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int seq[1000005], lst[1000005], to[1000005], pre[1000005], tot; 
int que[2000005], nxt[1000005][2], in[1000005]; 
bool vis[1000005][2]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u)
{
	in[u] = 1; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (in[to[i]] == 1)
		{
			puts("Draw"); 
			exit(0); 
		}
		if (!in[to[i]])
			dfs(to[i]); 
	}
	in[u] = 2; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("936B.in", "r", stdin); 
#endif
	memset(lst, -1, sizeof(lst)); 
	int n, m;
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		int cnt; 
		scanf("%d", &cnt); 
		for (int j = 0; j < cnt; j++)
		{
			int u; 
			scanf("%d", &u); 
			add_edge(i, --u); 
		}
	}
	int s; 
	scanf("%d", &s); 
	int ans = -1, pos, he = 0, ta = 0; 
	que[ta++] = --s; 
	que[ta++] = 1; 
	vis[s][1] = true; 
	nxt[s][1] = -1; 
	while (he < ta)
	{
		int u = que[he++]; 
		int x = que[he++]; 
		if (!x && lst[u] == -1)
		{
			ans = 1; 
			pos = u; 
		}
		for (int i = lst[u]; ~i; i = pre[i])
		{
			if (vis[to[i]][x ^ 1])
				continue; 
			vis[to[i]][x ^ 1] = true; 
			que[ta++] = to[i]; 
			que[ta++] = x ^ 1; 
			nxt[to[i]][x ^ 1] = u; 
		}
	}
	if (ans > 0)
	{
		puts("Win"); 
		int cnt = 0, u = pos, x = 0; 
		while (~u)
		{
			seq[cnt++] = u; 
			u = nxt[u][x]; 
			x ^= 1; 
		}
		for (int i = cnt - 1; i >= 0; i--)
			printf("%d%c", seq[i] + 1, " \n"[!i]);
		return 0; 
	}
	dfs(s); 
	puts("Lose"); 
	return 0; 
}