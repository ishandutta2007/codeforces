#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define loop(k,a) for (int k=(a); ~k; k=link[k])
#define Next(x) ((x++)%maxn)
using namespace std;
 
const int maxn = 10009, maxm = 300009, INF = 1e9;
struct edge { int u, v, f, c; double w; };
struct flows {
	int n, s, t, limit, a[maxn], inq[maxn], q[maxn];
	int m, head[maxn], link[maxm], p[maxn];
	edge e[maxm]; double d[maxn];
	void init(int _n, int _limit = 0) {
		n = _n; m = 0; limit = _limit;
		memset(head, -1, sizeof head);
	}
	void addEdge(int u, int v, int c, double w) {
		e[m].u = u; e[m].v = v; e[m].f = 0; e[m].c = c; e[m].w = w;
		link[m] = head[u]; head[u] = m++;
		e[m].u = v; e[m].v = u; e[m].f = 0; e[m].c = 0; e[m].w = -w;
		link[m] = head[v]; head[v] = m++;
	}
	bool SPFA(int s, int t, int &flow, double &cost) {
		int l = 0, r = 0, u;
		memset(d, 99, sizeof d);
		memset(inq, 0, sizeof inq);
		d[s] = 0; q[Next(r)] = s; a[s] = INF;
		while (l < r) {
			u = q[Next(l)]; inq[u] = 0;
			loop (k, head[u])
				if (e[k].f < e[k].c && d[u] + e[k].w < d[e[k].v]) {
					d[e[k].v] = d[u] + e[k].w;
					a[e[k].v] = min(a[u], e[k].c - e[k].f);
					p[e[k].v] = k;
					if (!inq[e[k].v]) {
						q[Next(r)] = e[k].v; inq[e[k].v] = 1;
					}
				}
		}
		if (d[t] >= INF) return false;
		flow += a[t]; cost += a[t] * d[t]; u = t;
		while (u != s) {
			e[p[u]].f += a[t]; e[p[u]^1].f -= a[t];
			u = e[p[u]].u;
		}
		return true;
	}
	double MinCost(int s, int t) {
		int flow = 0; double cost = 0;
		while (SPFA(s, t, flow, cost));
		//printf("%d %lf\n", flow, cost);
		if (flow < limit) return -1;
		return cost;
	}
} G;
int x[maxn], y[maxn];
int n, S, T;
 
int main() {
	scanf("%d", &n);
	S = 2 * n + 1; T = S + 1;
	G.init(T, n-1);
	rep (i, 1, n) scanf("%d%d", &x[i], &y[i]);
	rep (i, 1, n) rep (j, 1, n)
		if (y[i] > y[j]) 
			G.addEdge(i, n+j, 1, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	rep (i, 1, n) {
		G.addEdge(S, i, 2, 0);
		G.addEdge(n+i, T, 1, 0);
	}
	double ans = G.MinCost(S, T);
	if (ans < 0) puts("-1");
	else printf("%.8lf\n", ans);
	return 0;
}