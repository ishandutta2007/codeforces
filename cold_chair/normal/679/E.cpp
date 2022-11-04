#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int n, Q;
int tp, u, v, x;
ll a[N], a42[N];

struct P {
	ll x, y;
};
bool operator < (P a, P b) {
	return a.x < b.x;
}

#define i0 i + i
#define i1 i + i + 1
P t[N * 4]; ll g[N * 4];
ll lz[N * 4], lzf[N * 4], lzg[N * 4], bz[N * 4];
int pl, pr;
ll px, py;

ll up(ll x) {
	fo(i, 1, 10) if(a42[i] > x) return a42[i];
}

void ad(int i, ll px) {
	lz[i] += px;
	g[i] += px;
	t[i].x -= px;
}
void gx(int i, ll px, ll py) {
	lz[i] = 0; bz[i] = 1;
	t[i].x = px, g[i] = py;
	lzf[i] = px, lzg[i] = py;
}
void down(int i) {
	if(lzg[i]) {
		gx(i0, lzf[i], lzg[i]);
		gx(i1, lzf[i], lzg[i]);
		lzf[i] = lzg[i] = 0;
	}
	if(lz[i]) {
		ad(i0, lz[i]);
		ad(i1, lz[i]);
		lz[i] = 0;
	}
}
void bt(int i, int x, int y) {
	if(x == y) {
		bz[i] = 1;
		lzg[i] = a[x];
		t[i].x = up(a[x]) - a[x];
		t[i].y = x;
		g[i] = a[x];
		return;
	}
	int m = x + y >> 1;
	bt(i0, x, m); bt(i1, m + 1, y);
	t[i] = min(t[i0], t[i1]);
	g[i] = g[i0];
	bz[i] = bz[i0] & bz[i1] & (g[i0] == g[i1]);
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		ad(i, px);
		return;
	}
	int m = x + y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
	t[i] = min(t[i0], t[i1]);
	g[i] = g[i0];
	bz[i] = bz[i0] & bz[i1] & (g[i0] == g[i1]);
}
void fz(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		gx(i, px, py);
		return;
	}
	int m = x + y >> 1; down(i);
	fz(i0, x, m); fz(i1, m + 1, y);
	t[i] = min(t[i0], t[i1]);
	g[i] = g[i0];
	bz[i] = bz[i0] & bz[i1] & (g[i0] == g[i1]);
}
void qu(int i, int x, int y) {
	if(x == y) {
		px = g[i];
		return;
	}
	int m = x + y >> 1; down(i);
	if(pl <= m) qu(i0, x, m); else qu(i1, m + 1, y);
}

int ky;

void dg(int i, int x, int y) {
	if(y < pl || x > pr || t[i].x > 0) return;
	if(x >= pl && y <= pr && bz[i]) {
		ll v = g[i];
		fo(j, 1, 10) if(v == a42[j]) ky = 1;
		t[i].x = lzf[i] = up(v) - v; lzg[i] = v; lz[i] = 0;
		return;
	}
	int m = x + y >> 1; down(i);
	dg(i0, x, m); dg(i1, m + 1, y);
	t[i] = min(t[i0], t[i1]);
	g[i] = g[i0];
	bz[i] = bz[i0] & bz[i1] & (g[i0] == g[i1]);
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	a42[0] = 1; fo(i, 1, 10) a42[i] = a42[i - 1] * 42;
	scanf("%d %d", &n, &Q);
	fo(i, 1, n) scanf("%d", &a[i]);
	bt(1, 1, n);
	fo(i, 1, Q) {
		scanf("%d", &tp);
		if(tp == 1) {
			scanf("%d", &u); 
			pl = pr = u;
			qu(1, 1, n);
			pp("%I64d\n", px);
		} else
		if(tp == 2) {
			scanf("%d %d %d", &u, &v, &x);
			py = x, px = up(x) - x;
			pl = u, pr = v;
			fz(1, 1, n);
		} else {
			scanf("%d %d %d", &u, &v, &x);
			while(1) {
				ky = 0;
				pl = u, pr = v; px = x;
				add(1, 1, n);
				dg(1, 1, n);
				/*
				if(!ky) {
					fo(j, 1, n) {
						pl = pr = j;
						qu(1, 1, n);
						fo(k, 1, 10) if(px == a42[k])
							pp("SB\n");
					}
				}
				*/
				if(!ky) break;
			}
		}
	}
}