#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int n, Q;
typedef std::pair<int, int> pi;
pi diameter(int u, int fa = 0) {
	pi res(0, u);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)  {
			pi t = diameter(to[i], u); t.first += val[i];
			res = std::max(res, t);
		}
	return res;
}
struct TTT {
	int fa[MAXN], son[MAXN], top[MAXN], dep[MAXN], sonmax[MAXN];
	int dis[MAXN];
	int up[18][MAXN];
	void dfs1(int u) {
		for (int i = 1; i < 18; ++i)
			up[i][u] = up[i - 1][up[i - 1][u]];
		for (int i = head[u]; i; i = nxt[i])
			if (to[i] != fa[u]) {
				fa[to[i]] = u;
				dep[to[i]] = dep[u] + 1;
				dis[to[i]] = dis[u] + val[i];
				up[0][to[i]] = u;
				dfs1(to[i]); sonmax[to[i]] += val[i];
				if (sonmax[to[i]] > sonmax[son[u]]) son[u] = to[i];
			}
		sonmax[u] = sonmax[son[u]];
	}
	int down[MAXN];
	void dfs2(int u) {
		down[top[u]] = u;
		if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
		for (int i = head[u]; i; i = nxt[i])
			if (to[i] != fa[u] && to[i] != son[u])
				top[to[i]] = to[i], dfs2(to[i]);
	}
	int chv[MAXN], li[MAXN], rk[MAXN], bak, pre[MAXN];
	void init(int rt) {
		dep[rt] = 1, top[rt] = rt;
		dfs1(rt); dfs2(rt);
		for (int i = 1; i <= n; ++i) if (i == top[i])
			li[++bak] = i, chv[i] = dis[down[i]] - dis[fa[i]];
		std::sort(li + 1, li + 1 + bak, [this] (int a, int b) {
			return chv[a] > chv[b];
		});
		for (int i = 1; i <= bak; ++i)
			rk[li[i]] = i, pre[i] = pre[i - 1] + chv[li[i]];
	}
	int solve(int u, int v) {
		int lans = 0;
		v = std::min(bak, v * 2 - 1);
		if (rk[top[u]] <= v) lans = pre[v];
		else {
			lans = pre[v - 1] + chv[top[u]];
			int now = u;
			for (int i = 17; ~i; --i)
				if (up[i][now] && rk[top[up[i][now]]] > v)
					now = up[i][now];
			now = fa[now];
			int tv = pre[v] - dis[down[top[now]]] + dis[down[top[u]]];
			tv = std::max(tv, pre[v - 1] - dis[now] + dis[down[top[u]]]);
			lans = std::max(lans, tv);
		}
		return lans;
	}
} t1, t2;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1, t1, t2, t3; i < n; ++i) {
		std::cin >> t1 >> t2 >> t3;
		addedge(t1, t2, t3);
	}
	int rt1 = diameter(1).second, rt2 = diameter(rt1).second;
	t1.init(rt1), t2.init(rt2);
	int lans = 0;
	while (Q --> 0) {
		int u, v; std::cin >> u >> v;
		u = (u + lans - 1) % n + 1;
		v = (v + lans - 1) % n + 1;
		lans = std::max(t1.solve(u, v), t2.solve(u, v));
		std::cout << lans << '\n';
	}
	return 0;
}