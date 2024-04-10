#include <bits/stdc++.h>

const int MAXN = 100010;

typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, m;
LL val[MAXN], ansl[MAXN];
int dep[MAXN], fa[MAXN], fae[MAXN];
int ex, ey, eid;
void dfs(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (dep[to[i]] == -1) {
			dep[to[i]] = dep[u] ^ 1;
			fa[to[i]] = u, fae[to[i]] = i >> 1;
			dfs(to[i]);
			ansl[i >> 1] = val[to[i]];
			val[u] -= val[to[i]];
		} else if (!eid) {
			if (dep[u] == dep[to[i]]) {
				ex = u, ey = to[i], eid = i >> 1;
			}
		}
}
void add(int u, int d, int v) {
	while (d != u) {
		ansl[fae[d]] += v;
		v = -v;
		d = fa[d];
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> val[i];
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e);
	memset(dep, -1, sizeof dep);
	dep[1] = 0; dfs(1);
	if ((val[1] & 1) || (!ex && val[1])) {
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::cout << "YES" << std::endl;
	if (eid) {
		int up = dep[ey] ? 1 : -1, vx = val[1] / 2;
		add(1, ey, up * vx * 2);
		add(ey, ex, up * vx);
		ansl[eid] = -up * vx;
	}
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}