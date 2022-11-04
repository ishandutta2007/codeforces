#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int n, p[N], q[N], ip[N];

#define i0 i + i
#define i1 i + i + 1
int t[N * 4], g[N * 4];

int b1[N], b2[N];

int pl, pr;

void upd(int i) {
	if(g[i0] <= t[i1]) {
		t[i] = t[i0] + t[i1] - g[i0];
		g[i] = g[i1];
	} else {
		t[i] = t[i0];
		g[i] = g[i0] - t[i1] + g[i1];
	}
}

void add(int i, int x, int y) {
	if(x == y) {
		if(b1[x]) {
			if(b2[x]) {
				t[i] = 0; g[i] = 0;
			} else {
				t[i] = 0; g[i] = 1;
			}
		} else {
			if(b2[x]) {
				t[i] = 1; g[i] = 0;
			} else {
				t[i] = 0; g[i] = 0;
			}
		}
		return;
	}
	int m = x + y >> 1;
	if(pl <= m) add(i0, x, m); else add(i1, m + 1, y);
	upd(i);
}

int a[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &p[i]), ip[p[i]] = i;
	fo(i, 1, n) scanf("%d", &q[i]);
	fo(i, 1, n) {
		pl = pr = i;
		add(1, 1, n);
	}
	int ans = n;
	pl = pr = ip[ans];
	b1[pl] = 1; add(1, 1, n);
	a[0] = ans;
	fo(i, 1, n - 1) {
		b2[q[i]] = 1;
		pl = pr = q[i];
		add(1, 1, n);
		while(g[1] <= 0) {
			ans --;
			pl = pr = ip[ans];
			b1[pl] = 1;
			add(1, 1, n);
		}
		a[i] = ans;
	}
	fo(i, 0, n - 1) pp("%d ", a[i]); hh;
}