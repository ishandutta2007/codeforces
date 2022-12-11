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

const int N = 1e5 + 5, M = N << 1;

int n, m, k, ecnt, nxt[M], adj[N], go[M], d[N], ans[N], tot;
bool vis[N], is_clique;

std::unordered_map<int, bool> eg[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

struct elem
{
	int u, d;

	friend inline bool operator < (elem a, elem b)
	{
		return a.d < b.d || (a.d == b.d && a.u < b.u);
	}
};

std::set<elem> orz;

void work()
{
	int x, y; is_clique = 0; ecnt = 0;
	read(n); read(m); read(k); orz.clear();
	for (int i = 1; i <= n; i++) adj[i] = 0;
	if (k > 450) return (void) puts("-1");
	for (int i = 1; i <= n; i++) d[i] = 0, vis[i] = 1;
	while (m--) read(x), read(y), d[x]++, d[y]++,
		eg[x][y] = eg[y][x] = 1, add_edge(x, y);
	for (int i = 1; i <= n; i++) orz.insert((elem) {i, d[i]});
	while (!orz.empty() && orz.begin()->d < k)
	{
		std::set<elem>::iterator it = orz.begin();
		int u = it->u, du = it->d; orz.erase(it); vis[u] = 0;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (vis[v])
			{
				orz.erase(orz.find((elem) {v, d[v]})); d[v]--;
				orz.insert((elem) {v, d[v]});
			}
		if (du == k - 1 && !is_clique)
		{
			ans[tot = 1] = u;
			for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
				if (vis[v]) ans[++tot] = v;
			bool otz = 1;
			for (int i = 1; i <= tot; i++)
				for (int j = i + 1; j <= tot; j++)
					if (!eg[ans[i]][ans[j]]) {otz = 0; break;}
			if (otz) is_clique = 1;
		}
	}
	for (int i = 1; i <= n; i++) eg[i].clear();
	if (!orz.empty())
	{
		int res = orz.size();
		printf("1 %d\n", res);
		for (std::set<elem>::iterator it = orz.begin(); it != orz.end(); it++)
			printf("%d ", it->u);
		puts(""); return;
	}
	if (is_clique)
	{
		puts("2");
		for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
		return (void) puts("");
	}
	puts("-1");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}