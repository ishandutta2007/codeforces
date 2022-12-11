#include <bits/stdc++.h>

const int MAXN = 500010;
const int mod = 1000000007;
typedef long long LL;
void bye() { std::cout << 0 << std::endl; exit(0); }
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }

int fac[MAXN];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int fa[19][MAXN], dep[MAXN];
void dfs(int u, int f = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f) {
			dep[to[i]] = dep[u] + 1;
			fa[0][to[i]] = u;
			dfs(to[i], u);
		}
}
int UP(int x, int d) {
	for (int t = dep[x] - d; t; t &= t - 1)
		x = fa[__builtin_ctz(t)][x];
	return x;
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	if ((x = UP(x, dep[y])) == y) return x;
	for (int i = 18; ~i; --i)
		if (fa[i][x] != fa[i][y])
			x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}
int ans = 1;

typedef std::vector<int> VI;
typedef VI arr[MAXN];
typedef std::pair<int, int> pi;
arr mi, ma, uptd, dotd;
arr upt, dot, udd, ddd;
std::vector<pi> nor[MAXN];

void sort(VI & x) { std::sort(x.begin(), x.end()); }
int lb(const VI & x, int y) {
	auto at = std::lower_bound(x.begin(), x.end(), y);
	if (at == x.end()) return false;
	return *at == y;
}

int bel[MAXN], bmi[MAXN];
int find(int x) { return x == bel[x] ? x : bel[x] = find(bel[x]); }
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) bye();
	bel[x] = y, bmi[y] = bmi[x];
}
void dfs2(int u, int f = 0) {
	sort(uptd[u]), sort(dotd[u]);
	for (int i = head[u]; i; i = nxt[i]) {
		const int v = to[i];
		if (v != f) {
			dfs2(v, u);
			if (!upt[v].empty() && !lb(uptd[u], upt[v][0])) {
				udd[u].push_back(v);
				upt[u].push_back(upt[v][0]);
			}
			if (!dot[v].empty() && !lb(dotd[u], dot[v][0])) {
				ddd[u].push_back(v);
				dot[u].push_back(dot[v][0]);
			}
		}
	}
	if (upt[u].size() > 1) bye();
	if (dot[u].size() > 1) bye();
	static int li[MAXN]; int bak = 0;
	for (int i = head[u]; i; i = nxt[i])
		bmi[to[i]] = bel[li[++bak] = to[i]] = to[i];
	for (auto t : nor[u]) merge(t.first, t.second);
	for (auto t : udd[u]) merge(t, f);
	for (auto t : ddd[u]) merge(f, t);
	int cld = 0, fir = 0, lst = 0;
	for (auto t : mi[u]) {
		if (fir && t != fir) bye();
		if (bmi[find(t)] != t) bye();
		fir |= t;
	}
	for (auto t : ma[u]) {
		if (lst && t != lst) bye();
		if (find(t) != t) bye();
		lst |= t;
	}
	for (int i = 1; i <= bak; ++i) if (find(li[i]) == li[i])
		if (li[i] != find(fir) && li[i] != lst)
			++cld;
	if (fir && lst && find(fir) == lst && cld) bye();
	ans = mul(ans, fac[cld]);
}
void addtag(int x, int y) {
	if (!x) return ;
	if (x == y) bye();
	int L = LCA(x, y);
	if (x == L || y == L) {
		if (x == L) {
			int yu = UP(y, dep[L] + 1);
			mi[x].push_back(yu);
			ma[y].push_back(fa[0][y]);
			if (dep[L] < dep[y] - 1) {
				dot[y].push_back(y);
				dotd[L].push_back(y);
			}
		} else {
			int xu = UP(x, dep[L] + 1);
			mi[x].push_back(fa[0][x]);
			ma[y].push_back(xu);
			if (dep[L] < dep[x] - 1) {
				upt[x].push_back(y);
				uptd[L].push_back(y);
			}
		}
		return ;
	}
	int xu = UP(x, dep[L] + 1), yu = UP(y, dep[L] + 1);
	mi[x].push_back(fa[0][x]);
	ma[y].push_back(fa[0][y]);
	nor[L].emplace_back(xu, yu);
	if (dep[L] < dep[x] - 1) {
		upt[x].push_back(y);
		uptd[L].push_back(y);
	}
	if (dep[L] < dep[y] - 1) {
		dot[y].push_back(y);
		dotd[L].push_back(y);
	}
}
int main() {
	for (int i = *fac = 1; i != MAXN; ++i)
		fac[i] = mul(fac[i - 1], i);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	dfs(1);
	for (int i = 1; i != 19; ++i)
		for (int j = 1; j <= n; ++j)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, addtag(t, i);
	dfs2(1);
	std::cout << ans << std::endl;
	return 0;
}