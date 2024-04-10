#include <bits/stdc++.h>

const int MAXN = 500010;
typedef long long LL;

int head[MAXN], nxt[MAXN], rt, n, fa[MAXN];
int dep[MAXN], son[MAXN], sz[MAXN];
std::vector<int> hav[MAXN];
void dfs(int u) {
	hav[dep[u]].push_back(u);
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		dep[i] = dep[u] + 1;
		dfs(i);
		sz[u] += sz[i];
		if (sz[i] > sz[son[u]]) son[u] = i;
	}
}
int top[MAXN], dfn[MAXN], idx;
void hld(int u) {
	dfn[u] = ++idx;
	if (son[u]) top[son[u]] = top[u], hld(son[u]);
	for (int i = head[u]; i; i = nxt[i])
		if (i != son[u]) top[i] = i, hld(i);
}
LL ansl[MAXN];
int tr1[MAXN]; LL tr2[MAXN];
void _add(int x, int v) {
	for (int v2 = v * (x - 1); x <= n; x += x & -x)
		tr1[x] += v, tr2[x] += v2;
}
void add(int l, int r) {
	_add(l, 1), _add(r + 1, -1);
}
LL qry(int a) {
	LL res = 0; int ra = 0;
	for (int x = a; x; x &= x - 1)
		res += tr2[x], ra += tr1[x];
	return (LL) a * ra - res;
}
LL qry(int l, int r) { return qry(r) - qry(l - 1); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> fa[i];
		if (fa[i]) nxt[i] = head[fa[i]], head[fa[i]] = i;
		else rt = i;
	}
	dep[top[rt] = rt] = 1, dfs(rt), hld(rt);
	for (int i = 1; i <= n; ++i) {
		for (auto x : hav[i])
			while (x) add(dfn[top[x]], dfn[x]), x = fa[top[x]];
		for (auto x : hav[i]) {
			int t = x;
			while (x) ansl[t] += qry(dfn[top[x]], dfn[x]), x = fa[top[x]];
		}
	}
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] - dep[i] << (" \n" [i == n]);
	return 0;
}