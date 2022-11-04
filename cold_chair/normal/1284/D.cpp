#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 4e5 + 5;

int n;
struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};

P a[N], b[N];

int d[N], d0;
map<int, int> bd;

void ls() {
	fo(i, 1, n) {
		d[++ d0] = a[i].x;
		d[++ d0] = a[i].y;
		d[++ d0] = b[i].x; 
		d[++ d0] = b[i].y;
	}
	sort(d + 1, d + d0 + 1);
	d0 = unique(d + 1, d + d0 + 1) - (d + 1);
	fo(i, 1, d0) bd[d[i]] = i;
	fo(i, 1, n) {
		a[i].x = bd[a[i].x];
		a[i].y = bd[a[i].y];
		b[i].x = bd[b[i].x];
		b[i].y = bd[b[i].y];
	}
}

void rev() {
	fo(i, 1, n) {
		a[i].x = d0 - a[i].x + 1;
		a[i].y = d0 - a[i].y + 1;
		b[i].x = d0 - b[i].x + 1;
		b[i].y = d0 - b[i].y + 1;
		swap(a[i].x, a[i].y);
		swap(b[i].x, b[i].y);
	}
}

ll t[N * 4], lz[N * 4];

int p[N], q[N];

int cmpp(int x, int y) {
	return a[x].y < a[y].y;
}

int cmpq(int x, int y) {
	return a[x].x < a[y].x;
}

int pl, pr;
#define i0 i + i
#define i1 i + i + 1
void down(int i) {
	if(lz[i]) {
		t[i0] = t[i1] = lz[i0] = lz[i1] = 1;
		lz[i] = 0;
	}
}
void fz(int i) {
	t[i] = lz[i] = 1;
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) {
		return;
	}
	if(x >= pl && y <= pr) {
		fz(i); return;
	}
	int m = x + y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
}
void ft(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		if(t[i]) {
			pp("NO\n"); exit(0);
		}
		return;
	}
	int m = x + y >> 1; down(i);
	ft(i0, x, m); ft(i1, m + 1, y);
}
void work() {
	fo(i, 1, d0 * 4) t[i] = lz[i] = 0;
	fo(i, 1, n)	p[i] = q[i] = i;
	sort(p + 1, p + n + 1, cmpp);
	sort(q + 1, q + n + 1, cmpq);
	int l = 1;
//	pp("%d\n", d0);
//	fo(i, 1, n) pp("%d %d %d %d\n", a[i].x, a[i].y, b[i].x, b[i].y);
//	fo(i, 1, n) pp("%d\n", a[p[i]].y);
	fo(i, 1, n) {
		int x = q[i];
		while(l <= n && a[p[l]].y < a[x].x) {
			int y = p[l ++];
			pl = b[y].x, pr = b[y].y;
//			pp("%d %d\n", pl, pr);
			add(1, 1, d0);
		}
		pl = b[x].x, pr = b[x].y;
//		pp("%d %d\n", pl, pr);
		ft(1, 1, d0);
	}
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d %d", &a[i].x, &a[i].y);
		scanf("%d %d", &b[i].x, &b[i].y);
	}
	ls();
	work();
	rev();
	work();
	fo(i, 1, n) swap(a[i], b[i]);
	work();
	rev();
	work();
	pp("YES\n");
}