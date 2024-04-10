#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[200005], from[400005], to[400005], pre[400005], idx[400005], deg[200005], tot; 
int ans[100005], l[100005], r[100005], app[200005], seq[200005], sz; 
bool del[400005], vis[200005]; 
inline void add_edge(int u, int v, int _idx)
{
	// cout << u << " " << v << " " << _idx << endl; 
	from[tot] = u; 
	to[tot] = v; 
	pre[tot] = lst[u]; 
	idx[tot] = _idx; 
	deg[v]++; 
	lst[u] = tot++;
}
void dfs(int u)
{
	vis[u] = true; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (del[i])
		{
			lst[u] = pre[i]; 
			continue; 
		}
		del[i] = del[i ^ 1] = true; 
		dfs(to[i]); 
		seq[sz++] = i; 
	}
}
int main()
{
	// freopen("429E.in", "r", stdin); 
	memset(lst, -1, sizeof(lst));
	int n, cnt = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", l + i, r + i); 
		app[cnt++] = l[i]; 
		app[cnt++] = r[i] + 1; 
	}
	sort(app, app + cnt); 
	cnt = unique(app, app + cnt) - app; 
	for (int i = 0; i < n; i++)
	{
		l[i] = lower_bound(app, app + cnt, l[i]) - app; 
		r[i] = lower_bound(app, app + cnt, r[i] + 1) - app; 
		add_edge(l[i], r[i], i); 
		add_edge(r[i], l[i], i); 
	}
	int v = -1, e_cnt = n; 
	for (int i = 0; i < cnt; i++)
	{
		if (deg[i] & 1 ^ 1)
			continue; 
		if (~v)
		{
			add_edge(v, i, e_cnt); 
			add_edge(i, v, e_cnt++); 
			v = -1; 
		}
		else
			v = i; 
	}
	for (int i = 0; i < cnt; i++)
	{
		if (!vis[i])
		{
			sz = 0; 
			dfs(i); 
			for (int j = 0; j < sz; j++)
				ans[idx[seq[j]]] = from[seq[j]] < to[seq[j]]; 
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	return 0; 
}