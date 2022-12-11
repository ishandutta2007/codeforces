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

const int N = 2e5 + 5, M = N << 1;

int n, k, d[N], cnt[N], ecnt, nxt[M], adj[N], go[M], tot[N], ans;
bool is[N];

struct elem
{
	int u, c, t;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.c < b.c;
	}
};

std::priority_queue<elem> pq;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void work()
{
	int x, y;
	read(n); read(k); ecnt = ans = 0;
	for (int i = 1; i <= n; i++) d[i] = adj[i] = tot[i] = cnt[i] = 0, is[i] = 0;
	for (int i = 1; i < n; i++) read(x), read(y), d[x]++, d[y]++, add_edge(x, y);
	if (k == 1) return (void) printf("%d\n", n - 1);
	for (int u = 1; u <= n; u++) if (d[u] == 1)
	{
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			cnt[v]++;
		is[u] = 1;
	}
	while (!pq.empty()) pq.pop();
	for (int u = 1; u <= n; u++) if (cnt[u]) pq.push((elem) {u, cnt[u], ++tot[u]});
	while (!pq.empty() && pq.top().c >= k)
	{
		elem x = pq.top(); pq.pop(); if (x.t < tot[x.u]) continue;
		x.c -= k; cnt[x.u] -= k; d[x.u] -= k; ans++;
		pq.push(x); if (d[x.u] == 1)
		{
			is[x.u] = 1;
			for (int e = adj[x.u], v = go[e]; e; e = nxt[e], v = go[e])
				if (!is[v]) cnt[v]++, pq.push((elem) {v, cnt[v], ++tot[v]});
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}