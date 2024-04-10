#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;
 
const int N = 150005;
 
int n, m, p;
int a[N];
int op, l, r, id;
int pl, pr, px;
int w;

 
struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};
 
P t[N * 4][6];
int lz[N * 4], lz2[N * 4];
#define i0 i + i
#define i1 i + i + 1
void xiu(int i, int x, int y, int px) {
	lz[i] = px;
	fo(j, 2, w) t[i][j] = P(0, 0);
	t[i][1] = P(px, y - x + 1);
}
void jia(int i, int px) {
	lz2[i] += px;
	fo(j, 1, w) if(t[i][j].x)
		t[i][j].x += px;
}
void down(int i, int x, int y) {
	if(lz[i]) {
		int m = x + y >> 1;
		xiu(i0, x, m, lz[i]);
		xiu(i1, m + 1, y, lz[i]);
		lz[i] = 0;
	}
	if(lz2[i]) {
		jia(i0, lz2[i]);
		jia(i1, lz2[i]);
		lz2[i] = 0;
	}
}
void upd(P *a, P *b, P *c) {
	fo(j, 1, w) a[j] = b[j];
	fo(j, 1, w) if(c[j].x != 0) {
		int ky = 0;
		fo(k, 1, w) if(a[k].x == c[j].x) {
			a[k].y += c[j].y;
			ky = 1; break;
		}
		if(!ky) {
			int mi = 1;
			fo(k, 1, w) if(a[k].y < a[mi].y)
				mi = k;
			if(a[mi].y <= c[j].y) {
				int t = a[mi].y;
				a[mi] = c[j];
				fo(k, 1, w) a[k].y -= t;
			} else {
				fo(k, 1, w) a[k].y -= c[j].y;
			}
		}
	}
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		if(op == 1) xiu(i, x, y, px); else jia(i, px);
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	add(i0, x, m); add(i1, m + 1, y);
	upd(t[i], t[i0], t[i1]);
}
 
P py[6];
 
void ft(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		upd(py, py, t[i]);
		return;
	}
	int m = x + y >> 1; down(i, x, y);
	ft(i0, x, m); ft(i1, m + 1, y);
}
 
int main() {
	scanf("%d %d %d", &n, &m, &p);
	w = 100 / p;
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n) op = 1, pl = pr = i, px = a[i], add(1, 1, n);
	fo(ii, 1, m) {
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1) {
			scanf("%d", &id);
			pl = l, pr = r, px = id;
			add(1, 1, n);
		} else
		if(op == 2) {
			pl = l, pr = r;
			fo(j, 1, w) py[j].x = 0, py[j].y = 0;
			ft(1, 1, n);
			int cnt = 0;
			fo(j, 1, w) cnt += py[j].x != 0;
			pp("%d ", cnt);
			fo(j, 1, w) if(py[j].x > 0)
				pp("%d ", py[j].x);
			hh;
		}
	}
}