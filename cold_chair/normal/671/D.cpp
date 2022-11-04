#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int n, m, x, y, z;
int fi[N], nt[N * 2], to[N * 2], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

const ll inf = 1e18;

struct nod {
	int x, y, z;
} b[N];

typedef vector<int> V;
#define pb push_back
#define si size()
#define re resize()

struct tree {
	int l, r;
	ll x, lz;
} t[N * 20]; int tt;
int pl, pr; ll px;
#define i0 t[i].l
#define i1 t[i].r
void ad(int i, ll x) {
	if(i) t[i].x += x, t[i].lz += x;
}
void down(int i) {
	if(t[i].lz) {
		ad(i0, t[i].lz);
		ad(i1, t[i].lz);
		t[i].lz = 0;
	}
}
void add(int &i, int x, int y) {
	if(!i) t[++ tt] = t[0], i = tt;
	if(x == y) {
		t[i].x = px;
		return;
	}
	int m = x + y >> 1; down(i);
	if(pl <= m) add(i0, x, m); else add(i1, m + 1, y);
	t[i].x = min(t[i0].x, t[i1].x);
}
void mer(int &i, int j) {
	if(!i || !j) {
		i = i + j;
		return;
	}
	down(i); down(j);
	mer(t[i].l, t[j].l);
	mer(t[i].r, t[j].r);
	t[i].x = min(t[i0].x, t[i1].x);
}

V e[N];

int fa[N], g[N];

ll ans;

void dg(int x) {
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(y == fa[x]) continue;
		fa[y] = x; dg(y);
	}
	ll sum = 0;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(y == fa[x]) continue;
		sum += t[g[y]].x;
		if(sum >= inf) {
			pp("-1\n"); exit(0);
		}
	}
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i]; if(y == fa[x]) continue;
		ad(g[y], sum - t[g[y]].x);
		mer(g[x], g[y]);
	}
	if(x == 1) ans = t[g[1]].x;
	ff(j, 0, e[x].si) {
		int t = e[x][j];
		pl = pr = t;
		if(x == b[t].x) {
			px = b[t].z + sum;
		} else {
			px = inf;
		}
		add(g[x], 1, m);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	fo(i, 1, m) {
		scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].z);
		if(b[i].x != b[i].y) {
			e[b[i].x].pb(i);
			e[b[i].y].pb(i);
		}
	}
	if(n == 1) {
		pp("0\n"); return 0;
	}
	t[0].x = inf;
	dg(1);
	pp("%lld\n", ans);
}