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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, M = N << 1, INF = 0x3f3f3f3f;

int n, a[N], ecnt, nxt[M], adj[N], go[M], f[N][2];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu, int mid)
{
	f[u][0] = f[u][1] = INF;
	if (a[u]) f[u][a[u] - 1] = 0; else f[u][0] = f[u][1] = 0;
	int c0 = 0, c1 = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u, mid);
			if (a[u] != 2)
			{
				int t = Min(f[v][0], f[v][1] + 1);
				if (t > f[u][0]) c0 = f[u][0], f[u][0] = t;
				else if (t > c0) c0 = t;
			}
			if (a[u] != 1)
			{
				int t = Min(f[v][0] + 1, f[v][1]);
				if (t > f[u][1]) c1 = f[u][1], f[u][1] = t;
				else if (t > c1) c1 = t;
			}
		}
	if (a[u] != 2 && f[u][0] + c0 > mid) f[u][0] = INF;
	if (a[u] != 1 && f[u][1] + c1 > mid) f[u][1] = INF;
}

void work()
{
	int x, y;
	read(n); ecnt = 0;
	for (int i = 1; i <= n; i++) read(a[i]), adj[i] = 0;
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	int l = 0, r = n;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (dfs(1, 0, mid), Min(f[1][0], f[1][1]) < INF) r = mid - 1;
		else l = mid + 1;
	}
	std::cout << (l + 3 >> 1) << std::endl;
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}