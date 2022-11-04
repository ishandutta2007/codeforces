#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 6e5 + 5;

int n, m, x, y, r[N];
int fi[N], nt[N], to[N], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int bz[N], d[N], d0;

void dg(int x) {
	for(int i = fi[x]; i; i = fi[x]) {
		fi[x] = nt[fi[x]];
		if(bz[i]) continue;
		bz[i] = bz[i ^ 1] = 1;
		dg(to[i]);
	}
	d[++ d0] = x;
}

int ans[N][2], ans0;

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
		r[x] ++; r[y] ++;
	}
	int la = 0;
	fo(i, 1, n) if(r[i] & 1) {
		if(la) link(la, i), link(i, la), la = 0; else
			la = i;
	}
	if(la) link(la, la), link(la, la);
	fo(i, 1, n) if(fi[i]) {
		d0 = 0;
		dg(i);
		if(d0 % 2 == 0) {
			int x = d[d0];
			d[++ d0] = x;
		}
		fo(j, 1, d0 - 1) {
			ans[++ ans0][0] = d[j];
			ans[ans0][1] = d[j + 1];
			if(j & 1) swap(ans[ans0][0], ans[ans0][1]);
		}
	}
	pp("%d\n", ans0);
	fo(i, 1, ans0) pp("%d %d\n", ans[i][0], ans[i][1]);
}