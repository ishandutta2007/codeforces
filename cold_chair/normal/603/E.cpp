#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 4e5 + 5;

int n, m;

#define x0 t[x][0]
#define x1 t[x][1]
int fa[N], t[N][2], pf[N], rev[N], dd[N];
int siz[N], mx[N], z[N], g[N], f[N];

void upd(int x) {
	if(x) {
//		siz[x] = siz[x0] + siz[x1];
		mx[x] = x;
		if(z[mx[x0]] > z[mx[x]]) mx[x] = mx[x0];
		if(z[mx[x1]] > z[mx[x]]) mx[x] = mx[x1];
		f[x] = g[x] + f[x0] + f[x1] + (x <= n);
	}
}
void fan(int x) { if(x) swap(x0, x1), rev[x] ^= 1;}
void down(int x) { if(rev[x]) fan(x0), fan(x1), rev[x] = 0;}
//void dfs(int x) {
//	if(!x) return;
//	down(x);
//	dfs(x0); dd[++ dd[0]] = x; dfs(x1);
//}
//void push() {
//	fo(i, 1, 10) if(!fa[i]) {
//		dfs(i);
//		fo(j, 1, dd[0] - 1) pp("%d %d\n", dd[j], dd[j + 1]);
//		if(pf[i]) pp("%d %d\n", dd[1], pf[i]);
//		dd[0] = 0;
//	}
//}
int lr(int x) { return t[fa[x]][1] == x;}
void ro(int x) {
	int y = fa[x], k = lr(x);
	t[y][k] = t[x][!k]; if(t[x][!k]) fa[t[x][!k]] = y;
	fa[x] = fa[y]; if(fa[y]) t[fa[y]][lr(y)] = x;
	fa[y] = x; t[x][!k] = y; pf[x] = pf[y];
	upd(y); upd(x);
}
void xc(int x) {
	for(; x; x = fa[x]) dd[++ dd[0]] = x;
	while(dd[0]) down(dd[dd[0] --]);
}
void sp(int x, int y) {
	xc(x);
	for(; fa[x] != y; ro(x)) if(fa[fa[x]] != y)
		ro(lr(x) == lr(fa[x]) ? fa[x] : x);
}
void ac(int x) {
	for(int y = 0; x; ) {
		sp(x, 0), fa[x1] = 0, pf[x1] = x;
		g[x] += f[x1];
		x1 = y, fa[y] = x, pf[y] = 0;
		g[x] -= f[x1];
		y = x, upd(x), x = pf[x];
	}
}
void mr(int x) {
	ac(x); sp(x, 0); fan(x);
}
void link(int x, int y) {
	mr(x); mr(y); 
	pf[x] = y; g[y] += f[x];
	ac(x);
}
void cut(int x, int y) {
	mr(x); ac(y); sp(y, 0);
	fa[x] = pf[x] = t[y][0] = 0;
	upd(y);
}
int fl(int x) {
	down(x);
	return x0 ? fl(x0) : x;
}

struct edge {
	int x, y, z;
} e[N];
int td;

struct P {
	int v, x;
	P(int _v = 0, int _x = 0) {
		v = _v, x = _x;
	}
};
bool operator < (P a, P b) {
	if(a.v == b.v) return a.x < b.x;
	return a.v < b.v;
}
multiset<P> s;
int cntj;

void work(int w) {
	int x = e[w].x, y = e[w].y;
	mr(x); ac(y); sp(y, 0);
	int x2 = fl(y);
	if(x == x2) {
		sp(x, 0);
		int t = mx[x];
		if(z[w] < z[t]) {
			cut(e[t].x, t); cut(e[t].y, t);
			s.erase(P(z[t], t));
			link(x, w);
			link(w, y);
			s.insert(P(z[w], w));
		}
	} else {
		mr(x); mr(y);
		cntj -= f[x] & 1;
		cntj -= f[y] & 1;
		cntj += (f[x] + f[y]) & 1;
		link(x, w); link(w, y);
		s.insert(P(z[w], w));
	}
}

int era(int w) {
	int x = e[w].x, y = e[w].y;
	mr(x); ac(w); sp(x, 0);
	int sy = f[w], sx = f[x] - f[w];
//	pp("%d %d %d %d %d %d\n", w, z[w], x, y, sx, sy);
//	fo(i, 1, td) pp("i = %d %d %d\n", i, fa[i], pf[i]);
	if(sx % 2 == 0 && sy % 2 == 0) {
		cut(x, w); cut(y, w);
		s.erase(P(z[w], w));
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	td = n; cntj = n;
	fo(i, 1, n) f[i] = 1;
	fo(ii, 1, m) {
		td ++;
		scanf("%d %d %d", &e[td].x, &e[td].y, &e[td].z);
		z[td] = e[td].z;
		work(td);
		if(cntj == 0) {
			while(!s.empty()) {
				P a = *(--s.end());
				if(!era(a.x)) break;
			}
		}
		if(cntj > 0) {
			pp("-1\n");
		} else {
			pp("%d\n", (*s.rbegin()).v);
		}
	}
}