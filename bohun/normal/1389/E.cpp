#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

ll m, d, w;

ll po2(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%lld%lld%lld", &m, &d, &w);
		ll limit = min(m, d);
		ll mod = w / __gcd(w, d - 1);
		
		ll a = limit / mod;
		ll b = limit % mod;
		
		//printf ("--> %lld %lld %lld %lld\n", limit, a, b, mod);
		
		ll out = b * po2(a + 1) + (mod - b) * po2(a);
		printf ("%lld\n", out);
	}
	return 0;
}