#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define loop(k,a) for (int k=(a); ~k; k=link[k])
#define Next(x) ((x++)%maxn)
using namespace std;

const int maxn = 10009, maxm = 500009, INF = 1e9;
struct edge { int u, v, w, f, c; };
struct flows {
	int n, s, t, a[maxn], d[maxn], inq[maxn], q[maxn];
	int m, head[maxn], link[maxm], p[maxn];
	edge e[maxm];
	void init() { memset(head, -1, sizeof head); }
	void addEdge(int u, int v, int c, int w) {
		e[m].u = u; e[m].v = v; e[m].f = 0; e[m].c = c; e[m].w = w;
		link[m] = head[u]; head[u] = m++;
		e[m].u = v; e[m].v = u; e[m].f = 0; e[m].c = 0; e[m].w = -w;
		link[m] = head[v]; head[v] = m++;
	}
	bool spfa(int s, int t, int &flow, int &cost) {
		int l = 0, r = 0, u;
		memset(d, 0x3f, sizeof d);
		memset(inq, 0, sizeof inq);
		q[r++] = s; d[s] = 0; a[s] = INF;
		while (l < r) {
			u = q[Next(l)]; inq[u] = 0;
			loop (k, head[u])
				if (e[k].f < e[k].c && d[u] + e[k].w < d[e[k].v]) {
					d[e[k].v] = d[u] + e[k].w;
					a[e[k].v] = min(e[k].c - e[k].f, a[u]);
					p[e[k].v] = k;
					if (!inq[e[k].v])
						q[Next(r)] = e[k].v, inq[e[k].v] = 1; 
				}
		}
		if (d[t] >= INF) return 0;
		flow += a[t]; cost += a[t] * d[t]; u = t;
		while (u != s) {
			e[p[u]].f += a[t]; e[p[u]^1].f -= a[t];
			u = e[p[u]].u;
		}
		return 1;
	}
	int MinCost(int s, int t) {
		int flow = 0, cost = 0;
		while (spfa(s, t, flow, cost));
		return cost;
	}
} G;
int a[maxn], b[maxn], ans[maxn], flag[maxn];
int n, m, S, T, tmp, L, C, cnt;

void dfs(int u) {
	int v;
	for (int k=G.head[u]; ~k; k=G.link[k])
		if (n + 1 <= G.e[k].v && G.e[k].v <= 2 * n && G.e[k].f) {
			v = G.e[k].v - n;
			ans[v] = (!u ? cnt++ : ans[u]); L++;
			L += (flag[v] = (a[u] != a[v]));
			dfs(v);
		}
}

int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, n) {
		scanf("%d", &a[i]); tmp = a[i];
		while (tmp) b[i] += tmp&1, tmp >>= 1;
	}
	G.init(); S = 2 * n + 1; T = S + 1;
	G.addEdge(S, 0, m, 0);
	rep (i, 1, n) {
		G.addEdge(S, i, 1, 0);
		G.addEdge(n+i, T, 1, 0);
		G.addEdge(0, n+i, 1, b[i]);
	}
	rep (i, 1, n) rep (j, i+1, n)
		G.addEdge(i, j+n, 1, (a[i] != a[j]) * b[j]);
	C = G.MinCost(S, T); dfs(0);
	printf("%d %d\n", L, C);
	rep (i, 1, n) {
		if (flag[i]) printf("%c=%d\n", 'a' + ans[i], a[i]);
		printf("print(%c)\n", 'a' + ans[i]);
	}
	return 0;
}