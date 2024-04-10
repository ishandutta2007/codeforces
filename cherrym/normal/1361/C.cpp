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

const int N = 5e5 + 5, M = 1050000;

int n, a[N], b[N], res = 20, fa[M], cnt[M], ecnt = 1, nxt[M], adj[M], go[M],
len, ans[M];
bool vis[M];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	while (adj[u])
	{
		int e = adj[u]; adj[u] = nxt[e];
		if (vis[e]) continue; vis[e] = vis[e ^ 1] = 1;
		dfs(go[e]);
		ans[++len] = e & 1 ? e - 2 : e;
		ans[++len] = e - 1;
	}
}

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	if ((x = cx(x)) != (y = cx(y))) fa[y] = x;
}

int get(int x, int T) {return (x & (1 << T) - 1) + 1;}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	for (int T = 1; T <= 20; T++)
	{
		for (int i = 1; i <= (1 << T); i++) fa[i] = i;
		memset(vis, 0, sizeof(vis)); memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) zm(get(a[i], T), get(b[i], T)),
			vis[get(a[i], T)] = vis[get(b[i], T)] = 1,
			cnt[get(a[i], T)]++, cnt[get(b[i], T)]++;
		int rt; bool is = 1;
		for (int i = 1; i <= (1 << T); i++)
			if (vis[i]) rt = i;
		for (int i = 1; i <= (1 << T); i++)
			if (vis[i] && cx(i) != cx(rt)) is = 0;
		for (int i = 1; i <= (1 << T); i++) if (cnt[i] & 1) is = 0;
		if (!is) {res = T - 1; break;}
	}
	std::cout << res << std::endl;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) vis[get(a[i], res)] = vis[get(b[i], res)] = 1,
		add_edge(get(a[i], res), get(b[i], res));
	int rt;
	for (int i = 1; i <= (1 << res); i++) if (vis[i]) rt = i;
	memset(vis, 0, sizeof(vis));
	dfs(rt);
	for (int i = len; i >= 1; i--) printf("%d ", ans[i]);
	return puts(""), 0;
}