#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

ll M = 1e9+7;
vector<ll> lp;

ll pww(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return a * pww(a, b-1) % M;
	ll t = pww(a, b/2);
	return t * t % M;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll x, n;
	cin >> x >> n;
	for(ll i = 2; i*i <= x; ++i) {
		ll pw = 0;
		while(x%i == 0) {
			++pw;
			x /= i;
		}
		if(pw)
			lp.push_back(i);
	}
	if(x != 1) {
		lp.push_back(x);
	}
	ll ans = 1;
	for(ll p : lp) {
		ll xp = 0;
		ll pw = p;
		while(true) {
			if(pw > n) break;
			xp += n/pw;
			if(n/p >= pw)
				pw *= p;
			else break;
		}
		ans = (ans * pww(p, xp)) % M;
	}
	cout << ans << '\n';
}