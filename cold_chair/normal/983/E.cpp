//#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
#define i0 i << 1
#define i1 i << 1 | 1
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 2e5 + 5;

int n, fa[N], x, y, m;
int fi[N], to[N], nt[N], tot;
int dep[N], siz[N], son[N], top[N];
int p[N], q[N], tp;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

void dg(int x) {
	p[x] = ++ tp;
	siz[x] = 1;
	for(int i = fi[x]; i; i = nt[i]) {
		dep[to[i]] = dep[x] + 1;
		dg(to[i]);
		siz[x] += siz[to[i]];
		son[x] = siz[to[i]] > siz[son[x]] ? to[i] : son[x];
	}
	q[x] = tp;
}

void dfs(int x) {
	if(son[x]) top[son[x]] = top[x], dfs(son[x]);
	for(int i = fi[x]; i; i = nt[i]) if(to[i] != son[x])
		top[to[i]] = to[i], dfs(to[i]);
}

int lca(int x, int y) {
	while(top[x] != top[y])
		if(dep[top[x]] > dep[top[y]])
			 x = fa[top[x]]; else y = fa[top[y]];
	return dep[x] < dep[y] ? x : y;
}

int f[20][N];

struct nod {
	int x, y;
} b[N * 2];
int cmp(nod a, nod b) { return a.x < b.x;}

struct tree {
	int l, r, x;
} a[N * 40];
int g[N], tt, pl, pr, px;
void ad(int &i, int x, int y) {
	if(y < pl || x > pr) return;
	a[++ tt] = a[i]; i = tt;
	if(x == y) {a[i].x ++; return;}
	int m = x + y >> 1;
	ad(a[i].l, x, m); ad(a[i].r, m + 1, y);
	a[i].x = a[a[i].l].x + a[a[i].r].x;
}
void ff(int i, int x, int y) {
	if(y < pl || x > pr || !i) return;
	if(x >= pl && y <= pr) { px += a[i].x; return;}
	int m = x + y >> 1; ff(a[i].l, x, m); ff(a[i].r, m + 1, y);
}

int sum(int x1, int y1, int x2, int y2) {
	pl = x2, pr = y2; px = 0;
	ff(g[x1 - 1], 1, n);
	int y = px; px = 0;
	ff(g[y1], 1, n);
	return px - y;
}

int main() {
//	freopen("car.in", "r", stdin);
//	freopen("car.out", "w", stdout);
	scanf("%d", &n);
	fo(i, 2, n) scanf("%d", &fa[i]), link(fa[i], i);
	dep[1] = 1; dg(1); top[1] = 1; dfs(1);
	scanf("%d", &m);
	fo(i, 1, n) f[0][i] = i;
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		int z = lca(x, y);
		if(dep[z] < dep[f[0][x]]) f[0][x] = z;
		if(dep[z] < dep[f[0][y]]) f[0][y] = z;
		b[i].x = p[x]; b[i].y = p[y];
		b[i + m].x = p[y]; b[i + m].y = p[x];
	}
	fd(i, n, 1) for(int j = fi[i]; j; j = nt[j])
		if(dep[f[0][to[j]]] < dep[f[0][i]]) f[0][i] = f[0][to[j]];
	sort(b + 1, b + 2 * m + 1, cmp); int l = 0;
	fo(i, 1, n) {
		g[i] = ++ tt;
		a[g[i]] = a[g[i - 1]];
		while(l < 2 * m && b[l + 1].x == i) l ++, pl = pr = b[l].y, ad(g[i], 1, n);
	}
	fo(j, 1, 17) fo(i, 1, n) f[j][i] = f[j - 1][f[j - 1][i]];
	scanf("%d", &m);
	fo(ii, 1, m) {
		scanf("%d %d", &x, &y);
		if(dep[x] > dep[y]) swap(x, y);
		if(x == y) { printf("0\n"); continue;} 
		int z = lca(x, y);
		int ans = 2e9;
		if(x == z) {
			int s = 0;
			fd(i, 17, 0)
				if(f[i][y] != y && dep[f[i][y]] > dep[z]) y = f[i][y], s += 1 << i;
			if(dep[f[0][y]] <= dep[z]) printf("%d\n", s + 1); else printf("-1\n");
			continue;
		}
		int u = x, v = y, s = 0;
		fd(i, 17, 0) {
			if(f[i][u] != u && dep[f[i][u]] > dep[z]) u = f[i][u], s += 1 << i;
			if(f[i][v] != v && dep[f[i][v]] > dep[z]) v = f[i][v], s += 1 << i;
		}
		if(sum(p[u], q[u], p[v], q[v])) ans = min(ans, s + 1);
		if(dep[f[0][u]] <= dep[z] && dep[f[0][v]] <= dep[z]) ans = min(ans, s + 2);
		printf("%d\n", ans == 2e9 ? -1 : ans);
	}
}