#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 5e5 + 5, M = N << 1;

int n, m, ecnt, nxt[M], adj[N], go[M], cur[N], ans[N];
bool vis[N];

struct elem
{
	int id, x;
} a[N];

inline bool comp(elem a, elem b)
{
	return a.x < b.x;
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

int main()
{
	int x, y;
	read(n); read(m);
	while (m--) read(x), read(y), add_edge(x, y);
	for (int i = 1; i <= n; i++) read(x), a[i] = (elem) {i, x};
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		int u = a[i].id, oc = 0;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (cur[v])
			{
				if (cur[v] == a[i].x) return puts("-1"), 0;
				if (!vis[cur[v]]) vis[cur[v]] = 1, oc++;
			}
		if (oc < a[i].x - 1) return puts("-1"), 0;
		ans[i] = u; cur[u] = a[i].x;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			vis[cur[v]] = 0;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return puts(""), 0;
}