#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct node {
	LL a, b;
	node() { a = b = -INF; }
	void insert(LL x) {
		if (x >= a) b = a, a = x;
		else if (x >= b) b = x;
	}
} f1[MAXN];
LL dis[MAXN];
void dfs1(int u, int fa = 0) {
	bool vis = false;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			vis = true;
			dfs1(to[i], u);
			f1[u].insert(f1[to[i]].a + val[i]);
		}
	if (!vis) f1[u].insert(0);
}
void dfs2(int u, LL upv, int fa = 0) {
	dis[u] = std::max(upv, f1[u].a);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			LL tv = f1[to[i]].a + val[i] == f1[u].a ? f1[u].b : f1[u].a;
			dfs2(to[i], std::max(tv, upv) + val[i], u);
		}
}
int rk[MAXN], fa[MAXN], sz[MAXN];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int n;
int main() {
	std::cin >> n;
	for (int i = 1, t1, t2, t3; i != n; ++i) {
		std::cin >> t1 >> t2 >> t3;
		addedge(t1, t2, t3);
	}
	dfs1(1); dfs2(1, nxt[head[1]] ? -INF : 0);
	for (int i = 1; i <= n; ++i) rk[i] = i;
	std::sort(rk + 1, rk + 1 + n, [] (int a, int b) { return dis[a] < dis[b]; });
	int T; std::cin >> T;
	while (T --> 0) {
		LL L; std::cin >> L;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			fa[i] = i, sz[i] = 1;
		int rcur = n;
		static bool vis[MAXN];
		memset(vis, 0, n + 1);
		for (int i = n; i; --i) {
			const int u = rk[i];
			vis[u] = true;
			for (int j = head[u]; j; j = nxt[j])
				if (vis[to[j]]) {
					int x = find(to[j]), y = find(u);
					fa[x] = y;
					sz[y] += sz[x];
				}
			while (dis[rk[rcur]] - dis[u] > L) {
				const int v = rk[rcur];
				--sz[find(v)]; fa[v] = 0;
				vis[v] = false;
				--rcur;
			}
			ans = std::max(ans, sz[find(u)]);
		}
		std::cout << ans << '\n';
	}
	return 0;
}