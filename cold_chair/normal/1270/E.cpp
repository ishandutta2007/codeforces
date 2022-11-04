#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1005;

int n, a[N], b[N], c[N], c0, cnt[2][2];

void dg() {
	memset(cnt, 0, sizeof cnt);
	fo(i, 1, n) cnt[a[i] & 1][b[i] & 1] ++;
	fo(i, 0, 1) fo(j, 0, 1) if(cnt[i][j] == n) {
		fo(k, 1, n) a[k] += i, b[k] += j, a[k] /= 2, b[k] /= 2;
		dg(); return;		
	}
	if((cnt[0][0] + cnt[1][1]) && (cnt[0][1] + cnt[1][0])) {
		fo(i, 1, n) if((a[i] + b[i]) & 1)
			c[++ c0] = i;
		return;
	}
	fo(i, 1, n) if(a[i] & 1)
		c[++ c0] = i;
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld %lld", &a[i], &b[i]);
	dg();
	pp("%d\n", c0);
	fo(i, 1, c0) pp("%d ", c[i]); hh;
}