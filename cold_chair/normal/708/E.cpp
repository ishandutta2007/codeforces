#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

ll fac[200005], nf[200005];

void build(int n) {
	fac[0] = 1; fo(i, 1, n) fac[i] = fac[i - 1] * i % mo;
	nf[n] = ksm(fac[n], mo - 2); fd(i, n, 1) nf[i - 1] = nf[i] * i % mo;
}

ll C(int n, int m) {
	return n < m ? 0 : fac[n] * nf[n - m] % mo * nf[m] % mo;
}

const int N = 1505;

int n, m, k;
ll va, vb, p;
ll v[N];

ll g[N], h[N];

int main() {
	build(2e5);
	scanf("%d %d", &n, &m);
	scanf("%lld %lld", &va, &vb);
	p = va * ksm(vb, mo - 2) % mo;
	scanf("%d", &k);
	fo(i, 0, min(m, k)) {
		v[i] = ksm(p, i) * ksm((1 - p + mo) % mo, k - i) % mo * C(k, i) % mo;
	}
	g[m] = 1;
	fo(ii, 1, n) {
		fo(i, 1, m) h[i] = (h[i - 1] + g[i]) % mo;
		ll s0 = 0, s1 = 0;
		fo(x, 1, m) {
			s0 = (s0 + v[x - 1]) % mo;
			s1 = (s1 - v[x - 1] * h[x - 1]) % mo;
			g[x] = (s0 * (h[m] - h[m - x]) + s1) % mo * v[m - x];
		}
	}
	ll ans = 0;
	fo(i, 0, m) ans = (ans + g[i]) % mo;
	ans = (ans % mo + mo) % mo;
	pp("%lld\n", ans);
}