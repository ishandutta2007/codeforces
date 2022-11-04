#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int bz[N], p[N], p0, mi[N];

int sq;

void sieve(int n) {
	fo(i, 2, n) {
		if(!bz[i]) p[++ p0] = i;
		for(int j = 1; i * p[j] <= n; j ++) {
			int k = i * p[j]; bz[k] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

int n, a[N];

int f[N][2], cnt[N];

void fen(int x) {
	fo(i, 1, p0) {
		if(p[i] > sq) break;
		int v = p[i], s = 0;
		while(x % p[i] == 0) x /= p[i], s ++;
		if(s < f[v][0]) f[v][1] = f[v][0], f[v][0] = s; else
			if(s < f[v][1]) f[v][1] = s;
	}
	if(x > 1) {
		cnt[x] ++;
	}
}

ll ans = 1;

int main() {
	sieve(2e5); sq = sqrt(2e5);
	scanf("%d", &n);
	fo(i, 2, 2e5) f[i][0] = f[i][1] = 1e9;
	fo(i, 1, n) scanf("%d", &a[i]), fen(a[i]);
	fo(i, 2, 2e5) if(!bz[i]) {
		if(i <= sq) {
			fo(j, 1, f[i][1]) ans *= i;
		} else {
			if(cnt[i] > n - 2) {
				ans *= i;
			}
		}
	}
	pp("%lld\n", ans);
}