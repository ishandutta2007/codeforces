#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define loop(k,a) for (int k=(a); ~k; k=link[k])
using namespace std;
 
const int maxn = 100009, maxm = 1000009, INF = 1e9;
struct edge { int u, v, f, c; };
struct ISAP {
	int n, m, s, t, head[maxn], link[maxm];
	int d[maxn], p[maxn], cur[maxn], num[maxn];
	edge e[maxm];
	void init(int _n) {
		n = _n; m = 0;
		memset(head, -1, sizeof head);
		memset(cur, -1, sizeof cur);
	}
	void addEdge(int u, int v, int w) {
		e[m].u = u; e[m].v = v; e[m].f = 0; e[m].c = w;
		link[m] = head[u]; cur[u] = head[u] = m++;
		e[m].u = v; e[m].v = u; e[m].f = 0; e[m].c = 0;
		link[m] = head[v]; cur[v] = head[v] = m++;
	}
	int augment() {
		int mn = INF, u = t;
		while (u != s) {
			mn = min(mn, e[p[u]].c - e[p[u]].f);
			u = e[p[u]].u;
		}
		u = t;
		while (u != s) {
			e[p[u]].f += mn; e[p[u]^1].f -= mn;
			u = e[p[u]].u;
		}
		return mn;
	}
	int Maxflow(int _s, int _t) {
		int res = 0, u = _s, flag;
		memset(d, 0, sizeof d);
		memset(num, 0, sizeof num);
		s = _s; t = _t; num[0] = 0;
		while (d[s] < n) {
			if (u == t) { res += augment(); u = s; }
			flag = 0;
			loop (k, cur[u])
				if (e[k].f < e[k].c && d[u] == d[e[k].v] + 1) {
					p[e[k].v] = cur[u] = k;
					u = e[k].v; flag = 1;
					break;
				}
			if (flag) continue;
			int mn = n;
			loop (k, head[u])
				if (e[k].f < e[k].c) 
					mn = min(mn, d[e[k].v] + 1);
			if (--num[d[u]] == 0) return res;
			num[d[u] = mn]++; cur[u] = head[u];
			if (u != s) u = e[p[u]].u;
		}
		return res;
	}
} G;
int n, m, g, v, S, T, need, w, k, t, flag, ans;
int dog[maxn];
 
int main() {
	scanf("%d%d%d", &n, &m, &g);
	rep (i, 1, n) scanf("%d", &dog[i]);
	S = n + m + 1; T = S + 1;
	G.init(T + 1);
	rep (i, 1, n) {
		scanf("%d", &v);
		if (dog[i]) G.addEdge(S, i, v);
		else G.addEdge(i, T, v);
	}
	rep (i, 1, m) {
		scanf("%d%d%d", &need, &w, &k);
		rep (j, 1, k) {
			scanf("%d", &t);
			if (need) G.addEdge(n+i, t, INF);
			else G.addEdge(t, n+i, INF);
		}
		scanf("%d", &flag);
		if (need) G.addEdge(S, n+i, w + flag * g);
		else G.addEdge(n+i, T, w + flag * g);
		ans += w;
	}
	printf("%d\n", ans - G.Maxflow(S, T));
	return 0;
}