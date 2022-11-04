#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 750005;

int n, x, y;
vector<int> e1[N];
int b[N][2];

#define pb push_back
#define si size()
#define re resize

int r[N], us[N], d[N], d0;

namespace lct {
	int t[N][2], fa[N], pf[N], rev[N];
	int z[N], siz[N];
	int lr(int x) { return t[fa[x]][1] == x;}
	#define x0 t[x][0]
	#define x1 t[x][1]
	void upd(int x) {
		siz[x] = siz[x0] + siz[x1] + z[x];
	}
	void ro(int x) {
		int y = fa[x], k = lr(x);
		t[y][k] = t[x][!k]; if(t[x][!k]) fa[t[x][!k]] = y;
		fa[x] = fa[y]; if(fa[y]) t[fa[y]][lr(y)] = x;
		t[x][!k] = y, fa[y] = x, pf[x] = pf[y];
		upd(y); upd(x);
	}
	void fan(int x) {
		swap(x0, x1), rev[x] ^= 1;
	}
	void down(int x) {
		if(rev[x]) fan(x0), fan(x1), rev[x] = 0;
	}
	int d[N], d0;
	void xc(int x) {
		for(; x; x = fa[x]) d[++ d0] = x;
		while(d0) down(d[d0 --]);
	}
	void sp(int x, int y) {
		xc(x);
		for(; fa[x] != y; ro(x)) if(fa[fa[x]] != y)
			ro(lr(x) == lr(fa[x]) ? fa[x] : x);
	}
	void ac(int x) {
		for(int y = 0; x; ) {
			sp(x, 0), fa[x1] = 0, pf[x1] = x;
			x1 = y, fa[y] = x, pf[y] = 0;
			upd(x), y = x, x = pf[x];
		}
	}
	void mr(int x) {
		ac(x); sp(x, 0); fan(x);
	}
	void link(int x, int y) {
		mr(x); pf[x] = y; ac(x);
	}
	void cut(int x, int y) {
		mr(x); ac(y); sp(x, 0);
		x1 = fa[y] = pf[y] = 0;
	}
	int fl(int x) {
		down(x);
		if(siz[x0]) return fl(x0);
		return z[x] ? x : fl(x1);
	}
}

int fa[N];

void dg(int x) {
	ff(j, 0, e1[x].si) if(fa[x] != e1[x][j])
		fa[e1[x][j]] = x, dg(e1[x][j]);
}

int td;

int main() {
	scanf("%d", &n);
	td = n;
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		e1[x].pb(y); e1[y].pb(x);
	}
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		td ++;
		lct :: z[td] = lct :: siz[td] = 1;
		b[td][0] = x; b[td][1] = y;
		lct :: link(x, td);
		lct :: link(td, y);
	}
	dg(1);
	fo(i, 1, n) r[fa[i]] ++;
	fo(i, 1, n) if(!r[i]) d[++ d0] = i;
	pp("%d\n", n - 1);
	fo(i, 1, n - 1) {
		int x = d[i];
		if(!(-- r[fa[x]])) d[++ d0] = fa[x];
		lct :: mr(x);
		lct :: ac(fa[x]);
		lct :: sp(x, 0);
		int z = lct :: fl(lct :: t[x][1]);
		lct :: sp(z, 0);
		
		pp("%d %d %d %d\n", x, fa[x], b[z][0], b[z][1]);
		
		lct :: cut(b[z][0], z);
		lct :: cut(b[z][1], z);
		
		td ++;
		lct :: link(x, td);
		lct :: link(fa[x], td);
	}
}