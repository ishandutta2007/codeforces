#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int mod = 998244353 ;

ll pt(ll a, ll b) {
	if (!b) return 1;
	if (b % 2) return a * pt(a, b - 1) % mod;
	return pt(a * a % mod, b / 2);
}

const int nax = 1001;

ll d, a, b;
int q;
vector <ll> primes;
ll fac[nax];
ll rev[nax];

ll se(vector <int> x) {
	ll res=  1;
	ll s = 0;
	for (auto it : x) {
		s += it;
		res = res * rev[it] % mod;
	}
	res = res * fac[s] % mod;
	return res;
}
		 

void solve() {
	scanf ("%lld", &d);
	for (ll i = 2; i * i <= d; ++i) {
		if (d % i == 0) {
			primes.pb(i);
			while (d % i == 0) d /= i;
		}
	}
	if (d > 1) primes.pb(d);
	scanf ("%d", &q);
	while (q--) {
		scanf ("%lld%lld", &a, &b);
		map<ll, int> m;
		for (auto it : primes) {
			while (a % it == 0) {
				a /= it;
				m[it]++;
			}
			while (b % it == 0) {
				b /= it;
				m[it]--;
			}
		}
		vector <int> x, y;
		for (auto it : m) {
			if (it.se > 0) y.pb(it.se);
			if (it.se < 0) x.pb(-it.se);
		}
		
		printf ("%lld\n", (ll) se(x) * se(y) % mod);
	}
	
}	
		
 
int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, nax - 1) {
		fac[i] = (ll) fac[i - 1] * i % mod;
		rev[i]= pt(fac[i], mod - 2);
	}
	int T = 1;
	while (T--) solve();
	
    return 0;
}