#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;		

const int MOD = 998244353;
const int N = 2e5 + 5;

ll bin_pow(ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return c;
}

int n, m, d[N];
ll s[N];
 
int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) scanf ("%d", d + i);
	sort(d + 1, d + n + 1);
	rep(i, 1, n) s[i] = (s[i - 1] + d[i]) % MOD;
	rep(i, 1, m) {
		int a, b;
		scanf ("%d%d", &a, &b);
		int p = lower_bound(d + 1, d + n + 1, b) - d - 1;
		ll ans = 0;
		int r = n - p;
		ans += max(0, r - a) * bin_pow(r, MOD - 2) % MOD * (s[n] - s[p] + MOD) % MOD;
		ans += max(0, r + 1 - a) * bin_pow(r + 1, MOD - 2) % MOD * s[p] % MOD;
		printf ("%lld\n", ans % MOD); 
	}
	return 0;
}