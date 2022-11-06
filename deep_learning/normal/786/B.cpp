#include <iostream>
#include <utility>
#include <cstring>
#include <cstdio>
#include <queue>
#define mp make_pair
using namespace std; 
int to[10000005], pre[10000005], lst[1000005], w[10000005], tot;
void add_edge(int u, int v, int _w)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	w[tot] = _w; 
	lst[u] = tot++; 
}
void modify(int u, int l, int r, int L, int R, int st, int off, int w)
{
	if (L <= l && r <= R)
	{
		if (off < 0)
			add_edge(st, u - off, w); 
		else
			add_edge(u + off, st, w); 
		return; 
	}
	int m = l + r >> 1; 
	if (L <= m)
		modify(u << 1, l, m, L, R, st, off, w); 
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R, st, off, w); 
}
void build(int u, int l, int r, int off)
{
	for (int i = l; i <= r; i++)
	{
		if (off < 0)
			add_edge(u - off, i, 0); 
		else
			add_edge(i, u + off, 0); 
	}
	if (l >= r)
		return; 
	int m = l + r >> 1; 
	build(u << 1, l, m, off); 
	build(u << 1 | 1, m + 1, r, off); 
}
typedef long long ll; 
ll dis[1000005]; 
void dij(int st)
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, st)); 
	memset(dis, 0x3F, sizeof(dis)); 
	dis[st] = 0; 
	while (!que.empty())
	{
		int u = que.top().second; 
		ll d = -que.top().first; 
		que.pop(); 
		if (dis[u] != d)
			continue;
		for (int i = lst[u]; ~i; i = pre[i])
		{
			if (dis[to[i]] > dis[u] + w[i])
			{
				dis[to[i]] = dis[u] + w[i]; 
				que.push(mp(-dis[to[i]], to[i])); 
			}
		}
	}
}
int main()
{
	int n, q, st; 
	scanf("%d%d%d", &n, &q, &st); 
	st--;
	memset(lst, -1, sizeof(lst)); 
	build(1, 0, n - 1, -n); 
	build(1, 0, n - 1, n + 400005); 
	while (q--)
	{
		int tp; 
		scanf("%d", &tp); 
		if (tp == 1)
		{
			int u, v, w; 
			scanf("%d%d%d", &u, &v, &w); 
			add_edge(--u, --v, w); 
		}
		else if (tp == 2)
		{
			int u, l, r, w; 
			scanf("%d%d%d%d", &u, &l, &r, &w); 
			modify(1, 0, n - 1, --l, --r, --u, -n, w); 
		}
		else
		{
			int v, l, r, w; 
			scanf("%d%d%d%d", &v, &l, &r, &w); 
			modify(1, 0, n - 1, --l, --r, --v, n + 400005, w); 
		}
	}
	dij(st); 
	for (int i = 0; i < n; i++)
		printf("%lld%c", dis[i] == 0x3F3F3F3F3F3F3F3Fll ? -1 : dis[i], " \n"[i + 1 == n]); 
	return 0; 
}