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

int t;
ll a, b, c, d, inf = 1 << 23;

ll sum(ll n) {
	return n * (n + 1) / 2;
}

ll solve(ll x) {
	ll k = max(0LL, (x * d - c) / d);
	ll bil = -x * a + k * b * c;
	//~ cat(k);
	ll r = x - k;
	bil += (r * x * d - (sum(x) - sum(k)) * d) * b;
	return bil; 
}

int main() {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%lld%lld%lld%lld", &a, &b, &c, &d);
		//~ cat(solve(10));
		ll l = 1, r = inf;
		while (l < r) {
			ll m = (l + r) / 2;
			//~ cout << m << " " << solve(m + 1) << " " << solve(m) << endl;
			if (solve(m + 1) - solve(m) >= 0)
				r = m;
			else
				l = m + 1;
		}
		ll res = -solve(l);
		if (l == inf) res = -1;
		printf ("%lld\n", res);
	}
	
	return 0;
}