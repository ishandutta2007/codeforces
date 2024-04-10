#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <queue>
#define mp make_pair
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
struct Graph
{
	int lst[1005], to[20005], pre[20005], w[20005], tot; 
	Graph()
	{
		memset(lst, -1, sizeof(lst)); 
		tot = 0; 
	}
	inline void add_edge(int u, int v, int _w = 0)
	{
		to[tot] = v; 
		pre[tot] = lst[u]; 
		w[tot] = _w; 
		lst[u] = tot++; 
	}
} ok, g; 
ll dis[1005], len[1005][1005]; 
int ou[10005], ov[10005], ow[10005], pre[1005]; 
inline void dij(int s)
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, s)); 
	memset(dis, 0x3f, sizeof(dis)); 
	dis[s] = 0; 
	while (!que.empty())
	{
		int u = que.top().second; 
		ll d = -que.top().first; 
		que.pop(); 
		if (d != dis[u])
			continue; 
		for (int i = ok.lst[u]; ~i; i = ok.pre[i])
		{
			int v = ok.to[i], w = ok.w[i]; 
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pre[v] = u; 
				que.push(mp(-dis[v], v)); 
			}
		}
	}
}
inline void dij2(int s)
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, s)); 
	memset(dis, 0x3f, sizeof(dis)); 
	dis[s] = 0; 
	while (!que.empty())
	{
		int u = que.top().second; 
		ll d = -que.top().first; 
		que.pop(); 
		if (d != dis[u])
			continue; 
		for (int i = g.lst[u]; ~i; i = g.pre[i])
		{
			int v = g.to[i];
			ll w = my_abs(len[u][v]); 
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pre[v] = u;
				que.push(mp(-dis[v], v)); 
			}
		}
	}
}
int main()
{
	// freopen("B.in", "r", stdin); 
	int n, m, l, s, t; 
	scanf("%d%d%d%d%d", &n, &m, &l, &s, &t); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", ou + i, ov + i, ow + i); 
		if (ow[i])
		{
			ok.add_edge(ou[i], ov[i], ow[i]); 
			ok.add_edge(ov[i], ou[i], ow[i]); 
		}
		g.add_edge(ou[i], ov[i]); 
		g.add_edge(ov[i], ou[i]); 
		len[ou[i]][ov[i]] = !ow[i] ? -1 : ow[i]; 
		len[ov[i]][ou[i]] = !ow[i] ? -1 : ow[i]; 
	}
	dij(s); 
	if (dis[t] < l)
	{
		printf("NO\n");
		return 0; 
	}
	if (dis[t] == l)
	{
		printf("YES\n");
		for (int i = 0; i < m; i++)
			printf("%d %d %d\n", ou[i], ov[i], (ow[i] ? ow[i] : 1000000000));
		return 0; 
	}
	dij2(s); 
	if (dis[t] > l)
	{
		printf("NO\n");
		return 0; 
	}
	int u = t; 
	while (u != s)
	{
		if (len[u][pre[u]] < 0)
		{
			len[u][pre[u]] = -2; 
			len[pre[u]][u] = -2; 
		}
		u = pre[u]; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (len[i][j] == -1)
				len[i][j] = 1e9; 
		}
	}
	u = t; 
	while (u != s)
	{
		if (len[u][pre[u]] == -2)
		{
			len[u][pre[u]] = -1; 
			len[pre[u]][u] = -1; 
		}
		u = pre[u]; 
	}
	while (true)
	{
		dij2(s); 
		if (dis[t] == l)
			break; 
		int u = t; 
		while (u != s)
		{
			if (len[pre[u]][u] < 0)
			{
				len[pre[u]][u] = -len[pre[u]][u] + l - dis[t]; 
				len[u][pre[u]] = -len[u][pre[u]] + l - dis[t]; 
				break; 
			}
			u = pre[u]; 
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; i++)
		printf("%d %d %lld\n", ou[i], ov[i], my_abs(len[ou[i]][ov[i]]));
	return 0; 
}