#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 4e6 + 5;

int fi[N], to[N], nt[N], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
	nt[++ tot] = fi[y], to[tot] = x, fi[y] = tot;
}

int n, m, x, y;

int du[N];

int cur[N], bz[N];

int ans[N][2], ans0;

int d[N], d0;

void dg(int x, int fr) {
	for(; cur[x]; ) {
		int i = cur[x];
		cur[x] = nt[cur[x]];
		if(bz[i]) continue;
		bz[i] = bz[i ^ 1] = 1;
		dg(to[i], i);
	}
	if(fr) d[++ d0] = fr;
}

void work() {
	int la = 0;
	fo(i, 1, d0 + 1) {
		if(i > d0 || d[i] > 2 * m + 1) {
			for(int j = la + 1; j < i; j += 2) {
				ans[++ ans0][0] = to[d[j]];
				ans[ans0][1] = to[d[j] ^ 1];
			}
			if((i - la) % 2 == 1 && la + 1 < i) {
				ans[++ ans0][0] = to[d[i - 1]];
				ans[ans0][1] = to[d[i - 1] ^ 1];
			}
			la = i;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		link(x, y);
		du[x] ++; du[y] ++;
	}
	fo(i, 1, n) if(du[i] & 1) {
		link(n + 1, i);
	}
	fo(i, 1, n + 1) {
		cur[i] = fi[i];
	}
	fo(i, 1, n + 1) {
		d0 = 0;
		dg(i, 0);
		work();
	}
	pp("%d\n", ans0);
	fo(i ,1, ans0) pp("%d %d\n", ans[i][0], ans[i][1]);
}