#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;

int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int fa[MAXN], bel[MAXN], hav[MAXN], dep[MAXN], siz[MAXN];
LL out[MAXN];
int n, Q;
LL pw(int x) { return (LL) x * x; }
int dfs(int u) {
	int & sz = siz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u, dep[to[i]] = dep[u] + 1;
			int v = dfs(to[i]);
			out[u] += pw(v), sz += v;
		}
	out[u] += pw(n - sz);
	return sz;
}
LL ans = 0;
LL calc(int u) {
	const LL S = hav[u];
	LL res = S * (pw(n - S) - out[u]) + S * (S - 1) * (n - S) * 2 + S * (S - 1) * (S - 2);
	return res;
}
int find(int x) { return bel[x] == x ? x : bel[x] = find(bel[x]); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) bel[i] = i, hav[i] = 1;
	dfs(1);
	for (int i = 1; i <= n; ++i) ans += calc(i);
	std::cout << ans << '\n';
	std::cin >> Q;
	while (Q --> 0) {
		int x, y; std::cin >> x >> y;
		x = find(x), y = find(y);
		int nh = 0; LL no = 0;
		while (x != y) {
			if (dep[x] < dep[y]) std::swap(x, y);
			ans -= calc(x);
			nh += hav[x], no += out[x];
			no -= pw(n - siz[x]) + pw(siz[x]);
			x = find(bel[x] = fa[x]);
		}
		ans -= calc(x);
		hav[x] += nh, out[x] += no;
		ans += calc(x);
		std::cout << ans << '\n';
	}
	return 0;
}