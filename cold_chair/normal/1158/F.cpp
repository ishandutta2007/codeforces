#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 998244353;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int N = 3005;

int n, c, a[N];

ll ans[N];

namespace sub1 {
	ll a2[N], inv[N];
	ll g[N][N], h[N][N], sh[N];
	ll cnt[N], sum, c0;
	void cl() {
		fo(i, 1, c) cnt[i] = 0;
		sum = 1; c0 = c;
	}
	void add(int x) {
		if(!cnt[x]) {
			cnt[x] ++;
			c0 --;
		} else {
			sum = sum * inv[cnt[x]] % mo;
			cnt[x] ++;
			sum = sum * (a2[cnt[x]] - 1) % mo;
		}
	}
	ll f[N][N];
	void work() {
		a2[0] = 1; fo(i, 1, n) a2[i] = a2[i - 1] * 2 % mo;
		fo(i, 0, n) inv[i] = ksm(a2[i] - 1, mo - 2);
		fo(j, 1, n) {
			cl();
			fd(i, j, 1) {
				add(a[i]);
				if(c0) {
					g[i][j] = 0;
					h[i][j] = a2[j - i];
				} else {
					ll v = sum * inv[cnt[a[j]]] % mo;
					g[i][j] = v;
					h[i][j] = (a2[j - i] - v * a2[cnt[a[j]] - 1] % mo + mo) % mo;
				}
			}
		}
		f[0][0] = 1;
		fo(i, 0, n - 1) fo(j, 0, n / c) if(f[i][j]) {
			fo(k, i + 1, n) f[k][j + 1] = (f[k][j + 1] + f[i][j] * g[i + 1][k]) % mo;
		}
		fo(i, 0, n) fo(j, i, n) sh[i] = (sh[i] + h[i][j]) % mo;
		fo(i, 0, n) fo(j, 0, n / c) {
			if(i > 0) ans[j] = (ans[j] + f[i][j]) % mo;
			ans[j] = (ans[j] + f[i][j] * sh[i + 1]) % mo;
		}
	}
}

namespace sub2 {
	int m;
	ll f[2][N][1 << 10]; int o;
	void work() {
		m = (1 << c) - 1;
		f[o][0][0] = 1;
		fo(i, 1, n) {
			fo(j, 0, i / c) fo(s, 0, m) f[!o][j][s] = f[o][j][s];
			fo(j, 0, (i - 1) / c) {
				fo(s, 0, m - 1) if(f[o][j][s]) {
					int ns = s | (1 << (a[i] - 1));
					int nj = j;
					if(ns == m) ns = 0, nj ++;
					f[!o][nj][ns] = (f[!o][nj][ns] + f[o][j][s]) % mo;
				}
			}
			o = !o;
		}
		fo(j, 0, n / c) fo(s, 0, m)
			ans[j] = (ans[j] + f[o][j][s]) % mo;
		ans[0] = (ans[0] - 1 + mo) % mo;
	}
}

int main() {
	scanf("%d %d", &n, &c);
	fo(i, 1, n) scanf("%d", &a[i]);
	if(c > 10)
		sub1 :: work();
	else
		sub2 :: work();
	fo(i, 0, n) pp("%lld ", ans[i]); hh;
}