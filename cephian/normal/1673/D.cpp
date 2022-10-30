#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

inline ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}

vector<ll> divisors(ll x) {
	vector<ll> divisors;
	for(ll i = 1; i*i <= x; ++i) {
		if(x%i == 0) {
			divisors.push_back(i);
			if(i != x/i)
				divisors.push_back(x/i);
		}
	}
	return divisors;
}

void solve() {
	ll b, q, y;
	ll c, r, z;
	cin >> b >> q >> y;
	cin >> c >> r >> z;
	b -= c;
	c = 0;

	if(r % q != 0 || abs(b) % q != 0 || b > 0 || (b+q*(y-1)) < r*(z-1)) {
		cout << "0\n";
		return;
	}

	ll ans = 0;
	if(b > -r || b+q*(y-1) < r*z) {
		cout << "-1\n";
		return;
	}
	for(int p : divisors(r)) {
		if(lcm(p, q) != r) continue;
		ans += ll(r/p) * ll(r/p) % mod;
		ans %= mod;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}