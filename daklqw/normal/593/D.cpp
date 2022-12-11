#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
typedef long long LL;

int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
int et[MAXN];
LL val[MAXN << 1];
void adde(int b, int e, LL v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int fa[MAXN], dep[MAXN], up[MAXN];
LL vt[MAXN];
int find(int x) {
	return x == up[x] ? x : up[x] = find(up[x]);
}
void dfs(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dep[to[i]] = dep[u] + 1;
			fa[to[i]] = u;
			vt[to[i]] = val[i];
			et[i >> 1] = to[i];
			dfs(to[i]);
		}
}
int n, m;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int b, e; LL v;
		std::cin >> b >> e >> v;
		adde(b, e, v);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		up[i] = vt[i] == 1 ? fa[i] : i;
	vt[1] = 1;
	while (m --> 0) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int x, y; LL v;
			std::cin >> x >> y >> v;
			do {
				int _x = find(x), _y = find(y);
				if (_x == _y) {
					break;
				} else {
					if (dep[_x] > dep[_y]) {
						x = fa[_x];
						v /= vt[_x];
					} else {
						y = fa[_y];
						v /= vt[_y];
					}
				}
			} while (v);
			std::cout << v << '\n';
		} else {
			int x; LL v;
			std::cin >> x >> v;
			if (vt[x = et[x]] != 1 && v == 1)
				up[x] = fa[x];
			vt[x] = v;
		}
	}
	return 0;
}