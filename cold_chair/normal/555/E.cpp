#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n, m, q;
struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
} b[N], c[N];

int fi[N], nt[N * 2], to[N * 2], tot = 1;
void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int dfn[N], low[N], td, us[N * 2];
int z[N], z0, bz[N];
int bl[N], b0;

void dg(int x) {
	dfn[x] = low[x] = ++ td;
	z[++ z0] = x; bz[x] = 1;
	for(int i = fi[x]; i; i = nt[i]) if(!us[i]) {
		us[i] = us[i ^ 1] = 1;
		int y = to[i];
		if(!dfn[y]) {
			dg(y);
			low[x] = min(low[x], low[y]);
		} else if(bz[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] >= dfn[x]) {
		++ b0;
		do bl[z[z0]] = b0, bz[z[z0]] = 0; while(z[z0 --] != x);
	}
}

int f[N];
int F(int x) {
	return f[x] == x ? x : (f[x] = F(f[x]));
}
void bin(int x, int y) {
	if(F(x) != F(y)) {
		f[f[x]] = f[y];
	}
}

#define V vector<int>
#define pb push_back
#define si size()

V e[N];
int dep[N], fa[N];
void dfs(int x) {
	//pp("x = %d fa = %d\n", x, fa[x]);
	dep[x] = dep[fa[x]] + 1;
	bz[x] = 1;
	ff(j, 0, e[x].si) {
		int y = e[x][j];
		if(!bz[y]) fa[y] = x, dfs(y);
	}
}
int fq[18][N];

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	fd(i, 17, 0) if(dep[fq[i][x]] >= dep[y]) x = fq[i][x];
	if(x == y) return x;
	fd(i, 17, 0) if(fq[i][x]  != fq[i][y]) x = fq[i][x], y = fq[i][y];
	return fa[x];
}

int c1[N], c2[N];

int ans;

void dd(int x) {
	ff(j, 0, e[x].si) {
		int y = e[x][j];
		if(y != fa[x]) {
			dd(y);
			c1[x] += c1[y];
			c2[x] += c2[y];
		}
	}
	if(c1[x] && c2[x]) ans = 0;
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	fo(i, 1, m) scanf("%d %d", &b[i].x, &b[i].y);
	fo(i, 1, q) scanf("%d %d", &c[i].x, &c[i].y);
	fo(i, 1, m) {
		link(b[i].x, b[i].y);
		link(b[i].y, b[i].x);
		bin(b[i].x, b[i].y);
	}
	fo(i, 1, n) if(!dfn[i])
		dg(i);
	fo(i, 1, m) {
		int x = bl[b[i].x], y = bl[b[i].y];
		if(x != y) {
			e[x].pb(y);
			e[y].pb(x);
		}
	}
	fo(i, 1, b0) if(!bz[i])
		dfs(i);
	fo(i, 1, b0) fq[0][i] = fa[i];
	fo(j, 1, 17) fo(i, 1, b0)
		fq[j][i] = fq[j - 1][fq[j - 1][i]];
	fo(i, 1, q) {
		int x = c[i].x, y = c[i].y;
		if(F(x) != F(y)) {
			pp("No\n");
			return 0;
		} 
		x = bl[x], y = bl[y];
		int z = lca(x, y);
		c1[x] ++, c2[y] ++;
		c1[z] --, c2[z] --;
	}
	ans = 1;
	fo(i, 1, b0) if(!fa[i])
		dd(i);
	pp("%s\n", ans ? "Yes" : "No");
}