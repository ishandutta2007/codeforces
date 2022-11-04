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

const int N = 3e5 + 5;

int n, a[N], m;
ll g[N];

ll t0[N], t1[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]), m += a[i];
	fo(i, 0, m - 1) {
		ll v1 = ksm(m, mo - 2) * i % mo;
		ll v2 = ksm((ll) (n - 1) * m % mo, mo - 2) * (m - i) % mo;
		ll k = 1;
		t0[i] = 1;
		t1[i] = v2;
		k = (k - (1 - v1 - v2)) % mo;
		if(i > 0) {
			k = (k - t1[i - 1] * v1) % mo;
			t0[i] = (t0[i] + t0[i - 1] * v1) % mo;
		}
		k = ksm(k, mo - 2);
		t0[i] = t0[i] * k % mo;
		t1[i] = t1[i] * k % mo;
	}
	fd(i, m - 1, 0) g[i] = (g[i + 1] * t1[i] + t0[i]) % mo;
	fo(i ,0, m) g[i] = (g[i] % mo + mo) % mo;
	ll ans = 0;
	fo(i, 1, n)  ans = (ans + g[a[i]]) % mo;
	ans = (ans - g[0] * (n - 1)) % mo * ksm(n, mo - 2);
	ans = (ans % mo + mo) % mo;
	pp("%lld\n", ans);
}