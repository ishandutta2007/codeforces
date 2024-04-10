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

const int N = 3e5 + 5, M = N << 1, djq = 998244353;

int n, ecnt, nxt[M], adj[N], go[M], f[N][2][2];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++)
		f[u][a][b] = 1;
	int delta = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u);
			f[u][0][0] = 1ll * f[u][0][0] * (1ll * f[v][0][0] + f[v][0][1]
				+ f[v][1][0] + f[v][1][1]) % djq;
			f[u][1][0] = 1ll * f[u][1][0] * (1ll * f[v][0][0] + f[v][0][1]
				+ f[v][1][0] + f[v][1][1]) % djq;
			f[u][0][1] = 1ll * f[u][0][1] * (1ll * f[v][0][0] + f[v][0][1]
				+ f[v][1][0]) % djq;
			f[u][1][1] = 1ll * f[u][1][1] * (1ll * f[v][0][0] + f[v][0][1]
				+ f[v][1][0]) % djq;
			delta = 1ll * delta * (f[v][0][0] + f[v][0][1]) % djq;
		}
	f[u][0][1] = (f[u][0][1] - delta + djq) % djq;
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	return std::cout << (1ll * f[1][0][0] + f[1][0][1] + djq - 1) % djq << std::endl, 0;
}