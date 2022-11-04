#include<cstdio>
#include<iostream>
#include<iomanip>
#define ll long long
#define ld long double
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e5 + 5;

int n, m, q, C, x, y;
int final[N], next[N], to[N], tot;
int f[N], c[N];
int fa[N], dep[N], w[N], tw, siz[N], son[N], top[N];

void link(int x, int y) {
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
}

void dg(int x) {
	siz[x] = 1;
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i];
		dg(y);
		siz[x] += siz[y];
		son[x] = siz[y] > siz[son[x]] ? y : son[x];
	}
}

void dfs(int x) {
	w[x] = ++ tw;
	if(son[x]) top[son[x]] = top[x], dfs(son[x]);
	for(int i = final[x]; i; i = next[i]) {
		int y = to[i]; if(y == son[x]) continue;
		top[y] = y; dfs(y);
	}
}

struct tree {
	int l, r, bz; ll a[2];
} t[N * 105], px;

int g[N], pl, pr, td, pc; 

void xiu(int i, int x, int y, int c) {
	t[i].bz += c;
	t[i].a[1] += (ll) 2 * t[i].a[0] * c + (ll) (y - x + 1) * c * c;
	t[i].a[0] += (y - x + 1) * c;
}

void down(int &i, int x, int y) {
	if(t[i].bz) {
		int m = x + y >> 1;
		if(!t[i].l) t[i].l = ++ td;
		if(!t[i].r) t[i].r = ++ td;
		xiu(t[i].l, x, m, t[i].bz);
		xiu(t[i].r, m + 1, y, t[i].bz);
		t[i].bz = 0;
	}
}

void fi(int &i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		fo(j, 0, 2) px.a[j] += t[i].a[j];
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	fi(t[i].l, x, m); fi(t[i].r, m + 1, y);
}


void add(int &i, int x, int y) {
	if(y < pl || x > pr) return;
	if(!i) i = ++ td;
	if(x >= pl && y <= pr) {
		xiu(i, x, y, pc);
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	add(t[i].l, x, m); add(t[i].r, m + 1, y);
	fo(j, 0, 1) t[i].a[j] = t[t[i].l].a[j] + t[t[i].r].a[j];
}

void add(int x, int c) {
	int y = f[x];
	while(x) {
		fo(j, 0, 1) px.a[j] = 0;
		pl = w[top[x]], pr = w[x], pc = c;
		add(g[y], 1, n);
		x = fa[top[x]];
	}
}

int tp;

int main() {
//	freopen("h.in", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &q, &C);
	fo(i, 1, n) scanf("%d", &f[i]);
	fo(i, 2, n) {
		scanf("%d", &fa[i]);
		link(fa[i], i);
	}
	dep[1] = 1; dg(1);
	top[1] = 1; dfs(1);
	fo(i, 1, m) scanf("%d", &c[i]);
	fo(i, 1, n) add(i, 1);
	fo(ii, 1, q) {
		scanf("%d", &tp);
		if(tp == 1) {
			scanf("%d %d", &x, &y);
			add(x, -1);
			f[x] = y;
			add(x, 1);
		} else {
			scanf("%d", &x);
			px = t[g[x]];
			ld ans = (ld) ((ll) px.a[1] * c[x] * c[x] - (ll) 2 * px.a[0] * c[x] * C + (ll) n * C * C) / n;
			cout << setprecision(20) << ans << endl;
		}
	}
}