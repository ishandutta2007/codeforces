#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int Q[11];
ll D[70][11][11];
int quan;
ll a, b, base;

ll f(ll p, ll val, int dig) {
	if (val > b) return 0;
	if (max(ld(val), ld(val) + ld(p)*ld(base) - 1.0) < ld(a)) return 0;
	if (val >= a and ld(val) + ld(p)*ld(base) - 1.0 <= ld(b)) {
		return D[dig][base][quan];
	}
	ll res = 0;
	for (ll i = 0; i < base; ++i) {
    if (ld(val) + ld(p)*ld(i) > ld(b)) break;
		if (val or i) {
			if (Q[i]) {
				--quan;
				Q[i] = 0;
			}
			else {
				++quan;
				Q[i] = 1;
			}
		}
		res += f(p/base, val + p*i, dig - 1);
		if (val or i) {
			if (Q[i]) {
				--quan;
				Q[i] = 0;
			}
			else {
				++quan;
				Q[i] = 1;
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 11; ++i) {
		D[0][i][0] = 1;
	}
	for (int i = 1; i < 70; ++i) {
		for (ll j = 2; j < 11; ++j) {
			for (ll k = 0; k <= j; ++k) {
				if (k) D[i][j][k] += k*D[i - 1][j][k - 1];
				if (j - k) D[i][j][k] += (j - k)*D[i - 1][j][k + 1];
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> base >> a >> b;
		quan = 0;
		memset(Q, 0 , sizeof(Q));
		ll e = 1e18;
		int dig = 0;
		while (1) {
			e /= base;
			++dig;
			if (e == 0) break;
		}
		ll pot = 1;
		for (int i = 1; i < dig; ++i) pot *= base;
		cout << f(pot, 0, dig) << '\n';
	}
}