#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

int n, q;
int a[N], b[N][2];
int d[N], d0;

map<int, int> bd;

#define i0 i + i
#define i1 i + i + 1
struct P {
	int x, y;
} t[N * 4];

P operator + (P a, P b) {
	if(a.x != b.x) return a.x < b.x ? a : b;
	return (P) {a.x, a.y + b.y};
}

int lz[N * 4];
int pl, pr, px;
void jia(int i, int v) {
	t[i].x += v, lz[i] += v;
}
void down(int i) {
	if(lz[i]) {
		jia(i0, lz[i]);
		jia(i1, lz[i]);
		lz[i] = 0;
	}
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		jia(i, px); return;
	}
	int m = x + y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
	t[i] = t[i0] + t[i1];
}
void xiu(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x == y) {
		t[i].y += px; return;
	}
	int m = x + y >> 1; down(i);
	xiu(i0, x, m); xiu(i1, m + 1, y);
	t[i] = t[i0] + t[i1];
}

void Init() {
	scanf("%d %d", &n, &q);
	fo(i, 1, n) scanf("%d", &a[i]), d[++ d0] = a[i];
	fo(i, 1, q) {
		scanf("%d %d", &b[i][0], &b[i][1]);
		d[++ d0] = b[i][1];
	}
	sort(d + 1, d + d0 + 1);
	d0 = unique(d + 1, d + d0 + 1) - (d + 1);
	fo(i, 1, d0) bd[d[i]] = i;
}

void gai(int x, int xs) {
	if(x == 0) {
		pl = a[x + 1], pr = d0, px = xs;
		add(1, 1, d0);
	} else
	if(x == n) {
		pl = 1, pr = a[x] - 1; px = xs;
		add(1, 1, d0);
	} else {
		if(a[x] != a[x + 1]) {
			pl = a[x], pr = a[x + 1];
			if(pl > pr) swap(pl, pr);
			pr --; px = xs;
			add(1, 1, d0);
		}
	}
}

int cnt[N];

void add_cnt(int x, int xs) {
	if(xs == 1) {
		if(++ cnt[x] == 1) {
			pl = pr = x; px = 1;
			xiu(1, 1, d0);
		}
	} else {
		if(-- cnt[x] == 0) {
			pl = pr = x; px = -1;
			xiu(1, 1, d0);
		}
	}
}

void build() {
	fo(i, 1, n) {
		a[i] = bd[a[i]];
		add_cnt(a[i], 1);
	}
	fo(i, 0, n) gai(i, 1);
}

void work() {
	fo(i, 1, q) {
		int x, y;
		x = b[i][0], y = b[i][1];
		y = bd[y];
		
		add_cnt(a[x], -1);
		gai(x - 1, -1); gai(x, -1);
		
		a[x] = y;
		add_cnt(a[x], 1);
		gai(x - 1, 1); gai(x, 1);
		
		pp("%d\n", t[1].x == 1 ? t[1].y : 0);
	}
}

int main() {
	Init();
	build();
	work();
}