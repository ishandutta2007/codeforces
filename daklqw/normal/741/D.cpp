#include <bits/stdc++.h>

const int MAXN = 500010;
int head[MAXN], nxt[MAXN];
int val[MAXN], fa[MAXN];
int n, ansl[MAXN];
int top[MAXN], son[MAXN], sz[MAXN], dep[MAXN];
void dfs(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		dfs(i), sz[u] += sz[i];
		if (sz[i] > sz[son[u]]) son[u] = i;
	}
}
void hld(int u) {
	if (son[u]) top[son[u]] = top[u], hld(son[u]);
	for (int i = head[u]; i; i = nxt[i])
		if (i != son[u])
			top[i] = i, hld(i);
}
int buc[1 << 22];
int li[MAXN], bak;
void gma(int & x, int y) { x < y ? x = y : 0; }
int ans;
void addeff(int u) {
	gma(buc[val[u]], dep[u]); li[++bak] = val[u];
}
void mkqry(int u) {
	gma(ans, buc[val[u]] + dep[u]);
	for (int i = 0; i != 22; ++i)
		gma(ans, buc[val[u] ^ (1 << i)] + dep[u]);
}
void add(int u) {
	addeff(u);
	for (int i = head[u]; i; i = nxt[i]) add(i);
}
void qry(int u) {
	mkqry(u);
	for (int i = head[u]; i; i = nxt[i]) qry(i);
}
void dsu(int u) {
	for (int i = head[u]; i; i = nxt[i])
		if (i != son[u]) dsu(i);
	if (son[u]) dsu(son[u]);
	ans = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (i != son[u])
			qry(i), add(i);
	mkqry(u), addeff(u);
	gma(ansl[u], ans - dep[u] * 2);
	if (u == top[u]) {
		for (int i = 1; i <= bak; ++i) buc[li[i]] = 0xcfcfcfcf;
		bak = 0;
	}
}
int main() {
	memset(buc, 0xcf, sizeof buc);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; dep[1] = 1;
	for (int i = 2; i <= n; ++i) {
		static char buf[10];
		std::cin >> fa[i] >> buf;
		val[i] = val[fa[i]] ^ (1 << (*buf - 'a'));
		nxt[i] = head[fa[i]], head[fa[i]] = i;
		dep[i] = dep[fa[i]] + 1;
	}
	dfs(1); top[1] = 1; hld(1); dsu(1);
	for (int i = n; i; --i) gma(ansl[fa[i]], ansl[i]);
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << ' ';
	return 0;
}