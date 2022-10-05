#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 500005;
const int inf = 1e9 + 99;
struct edge { 
	int u, v, w;
	bool operator < (const edge &e) const {
		return w < e.w;
	}
} g[maxn<<1];
int son[maxn], top[maxn], dep[maxn], size[maxn], fa[maxn];
int pa[maxn], id[maxn], T[maxn<<2], Flag[maxn], rid[maxn];
int n, K, m, tot, clk, a, b, c, flag;
vector<int> e[maxn], E[maxn];
ll ans;

inline int getpa(int x) {
	return pa[x] == x ? x : pa[x] = getpa(pa[x]);
}

void dfs1(int u, int f) {
	int cur = 0;
	fa[u] = f;
	size[u] = 1;
	for (auto v : e[u])
		if (v != f) {
			dep[v] = dep[u] + 1;
			if (E[u][cur++]) {
				Flag[v] = 1;
				// printf("%d\n", v);
			}
			dfs1(v, u);
			size[u] += size[v];
			if (size[v] > size[son[u]])
				son[u] = v;
		}
		else cur++;
}

void dfs2(int u, int anc) {
	id[u] = ++clk; rid[clk] = u;
	top[u] = anc;
	if (son[u]) dfs2(son[u], anc);
	for (auto v : e[u])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

/***************************************/

inline int lca(int a, int b) {
	if (a == 1 || b == 1) return 1;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])
			swap(a, b);
		a = fa[top[a]];
	}
	if (dep[a] < dep[b]) return a;
	return b;
}

#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
void update(int o, int l, int r, int x, int y, int z) {
	if (T[o]) return;
	if (l == x && y == r) {
		// printf("@ %d %d\n", l, r);
		T[o] = z; return;
	}
	if (x <= mid) update(lc, l, mid, x, min(y, mid), z);
	if (mid < y) update(rc, mid+1, r, max(mid+1, x), y, z);
	if (T[lc] && T[rc])
		T[o] = max(T[lc], T[rc]);
}

void change(int a, int b, int val) {
	// printf("Change: %d %d %d\n", a, b, val);
	while (dep[top[a]] > dep[b]) {
		// printf("# %d %d\n", top[a], a);
		update(1, 1, n, id[top[a]], id[a], val);
		a = fa[top[a]];
	}
	if (dep[a] > dep[b]) {
		// printf("%d %d\n", a, ask(a, b));
		update(1, 1, n, id[b]+1, id[a], val);
	}
}

/*****************************************/

void solve(int o, int l, int r, int base) {
	if (T[o]) {
		if (!base) base = T[o];
		else base = min(base, T[o]);
	}
	if (l == r) {
		if (!Flag[rid[l]]) return;
		if (!base) flag = 1;
		else ans += base;
		return;
	}
	solve(lc, l, mid, base);
	solve(rc, mid+1, r, base);
}

int main() {
	scanf("%d%d%d", &n, &K, &m);
	rep (i, 1, K) 
		scanf("%d%d", &g[i].u, &g[i].v);
	tot = K;
	rep (i, 1, m) {
		tot++;
		scanf("%d%d%d", &g[tot].u, &g[tot].v, &g[tot].w);
	}
	sort(g + 1, g + tot + 1);
	rep (i, 1, n) pa[i] = i;
	rep (i, 1, tot)
		if (getpa(g[i].u) != getpa(g[i].v)) {
			pa[getpa(g[i].u)] = getpa(g[i].v);
			e[g[i].u].push_back(g[i].v);
			e[g[i].v].push_back(g[i].u);
			if (g[i].w == 0) {
				E[g[i].u].push_back(1);
				E[g[i].v].push_back(1);
			}
			else {
				E[g[i].u].push_back(0);
				E[g[i].v].push_back(0);
			}
			g[i].w = -inf;
			// printf("Edge: %d %d\n", g[i].u, g[i].v);
		}
	dep[0] = -1; dfs1(1, 0); dfs2(1, 1);
	rep (i, 1, tot) if (g[i].w >= 0) {
		a = g[i].u; b = g[i].v; c = lca(a, b);
		if (a != c) change(a, c, g[i].w);
		if (b != c) change(b, c, g[i].w);
	}
	solve(1, 1, n, 0);
	if (flag) puts("-1");
	else cout << ans;
	return 0;
}