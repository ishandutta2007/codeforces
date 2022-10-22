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
// c0 3f
using ll = long long;
using ld = long double;
using namespace std;

int T;
ll p, q;
map <ll, ll> cnt;

ll qq(ll k) {
	ll P = p, res = 0;
	while (P % k == 0) {
		res++;
		P /= k;
	}
	return res;
}	

void mul(ll &a, int b, int c) {
	rep(i, 1, c)
		a *= b;
}

int main() {
	scanf ("%d", &T);
	while (T--) {
		cnt.clear();
		scanf ("%lld%lld", &p, &q);
		ll res = 1;
		for (ll i = 2; i * i <= q; ++i) {
			while (q % i == 0) {
				cnt[i]++;
				q /= i;
			}
		}
		if (q > 1) {
			cnt[q]++;
		}
		for (auto [x, y] : cnt) {
			ll cur = 1;
			for (auto [a, b] : cnt) {
				if (x != a) 
					mul(cur, a, qq(a));
				if (x == a)
					mul(cur, a, min(qq(a), b - 1));
			}
			res = max(res, cur);
		}	
		for (auto [x, y] : cnt)
			while (p % x == 0) p /= x;
		printf ("%lld\n", p * res);
	}		
}