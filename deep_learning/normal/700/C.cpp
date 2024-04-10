#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define mp make_pair
using namespace std; 
struct graph
{
	int lst[2005], to[60005], pre[60005], idx[60005], tot; 
	graph()
	{
		memset(lst, -1, sizeof(lst)); 
		tot = 0; 
	}
	inline void add_edge(int u, int v, int _idx)
	{
		to[tot] = v; 
		pre[tot] = lst[u]; 
		idx[tot] = _idx; 
		lst[u] = tot++; 
	}
} g; 
bool vis[2005]; 
int ou[30005], ov[30005], ow[30005], cnt[2005][2005], w[2005][2005], idx[2005][2005]; 
int pree[2005], st[2005], en[2005], s, t, pos, seq[2005]; 
pair<pair<int, int>, pair<int, int> > ans = mp(mp(2e9, 3), mp(0, 0)); 
inline void bfs(int s)
{
	queue<int> que; 
	que.push(s); 
	while (!que.empty())
	{
		int u = que.front(); 
		que.pop(); 
		for (int i = g.lst[u]; ~i; i = g.pre[i])
		{
			if (!vis[g.to[i]])
			{
				que.push(g.to[i]); 
				vis[g.to[i]] = true; 
				pree[g.to[i]] = g.idx[i]; 
			}
		}
	}
}
bool work(int u, int fa = -1)
{
	st[u] = en[u]; 
	bool res = u == t; 
	for (int i = g.lst[u]; ~i; i = g.pre[i])
	{
		if (g.idx[i] == pos || g.to[i] == fa)
			continue; 
		if (!en[g.to[i]])
		{
			en[g.to[i]] = en[u] + 1; 
			if (work(g.to[i], u))
			{
				res = true; 
				pree[g.to[i]] = g.idx[i]; 
			}
			st[u] = min(st[u], st[g.to[i]]); 
		}
		else
			st[u] = min(st[u], en[g.to[i]]); 
	}
	return res; 
}
inline void calc()
{
	memset(en, 0, sizeof(en)); 
	en[s] = 1; 
	work(s); 
	if (!en[t])
	{
		ans = min(ans, mp(mp(ow[pos], 1), mp(pos, 0))); 
		return; 
	}
	int u, v; 
	for (int i = t; i != s; i = u + v - i)
	{
		u = ou[pree[i]];
		v = ov[pree[i]]; 
		if (cnt[u][v] > 1)
			continue; 
		if (st[u] <= en[v] && st[v] <= en[u])
			continue; 
		ans = min(ans, mp(mp(ow[pos] + ow[pree[i]], 2), mp(pos, pree[i]))); 
	}
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int n, m; 
	scanf("%d%d%d%d", &n, &m, &s, &t); 
	s--; 
	t--; 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", ou + i, ov + i, ow + i); 
		g.add_edge(--ou[i], --ov[i], i); 
		g.add_edge(ov[i], ou[i], i); 
		idx[ou[i]][ov[i]] = i; 
		idx[ov[i]][ou[i]] = i;
		cnt[ou[i]][ov[i]]++; 
		cnt[ov[i]][ou[i]]++;  
	}
	bfs(s); 
	if (!vis[t])
	{
		printf("0\n0\n");
		return 0; 
	}
	memcpy(seq, pree, sizeof(pree)); 
	for (int x = t; x != s;)
	{
		int u = ou[seq[x]], v = ov[seq[x]]; 
		pos = idx[u][v];
		cnt[u][v]--; 
		cnt[v][u]--; 
		calc(); 
		cnt[u][v]++; 
		cnt[v][u]++;
		x = u + v - x; 
	}
	if (ans.first.second >= 3)
	{
		printf("-1\n");
		return 0; 
	}
	printf("%d\n%d\n", ans.first.first, ans.first.second);
	if (ans.first.second == 1)
		printf("%d\n", ans.second.first + 1);
	else
		printf("%d %d\n", ans.second.first + 1, ans.second.second + 1);
	return 0; 
}