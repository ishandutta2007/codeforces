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

const int N = 1e6 + 5;

int n, m, t[N], x[N], y[N], ecnt, nxt[N], adj[N], go[N], d[N], H, T, Q[N], top[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; d[v]++;
}

void work()
{
	read(n); read(m); ecnt = H = T = 0;
	for (int i = 1; i <= n; i++) adj[i] = 0, d[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		read(t[i]); read(x[i]); read(y[i]);
		if (t[i]) add_edge(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++) if (!d[i]) Q[++T] = i;
	while (H < T)
	{
		int u = Q[++H]; top[u] = H;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (!(--d[v])) Q[++T] = v;
	}
	if (T < n) return (void) puts("NO");
	puts("YES");
	for (int i = 1; i <= m; i++)
		if (t[i] || top[x[i]] < top[y[i]]) printf("%d %d\n", x[i], y[i]);
		else printf("%d %d\n", y[i], x[i]);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}