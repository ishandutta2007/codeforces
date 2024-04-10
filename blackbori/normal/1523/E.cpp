#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll F[202020], FI[202020];
ll n, k;

ll inv(ll x) { return x > 1? (mod - mod / x) * inv(mod % x) % mod : 1; }
ll C(ll n, ll k) { return F[n] * FI[n - k] % mod * FI[k] % mod; }
ll H(ll n, ll k) { return C(n + k - 1, k); }

void tc() {
	ll i, t, s;

	cin >> n >> k;
	for (i = F[0] = 1; i <= n + n; i++) {
		F[i] = F[i - 1] * i % mod;
	}
	FI[n + n] = inv(F[n + n]);
	for (i = n + n; i >= 1; i--) {
		FI[i - 1] = FI[i] * i % mod;
	}

	s = 1;
	for (i = 1; i <= n; i++) {
		t = (i - 1) * k + 1;
		if (t <= n) {
			s = (s + H(i + 1, n - t) * inv(C(n, i))) % mod;
		}
	}

	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}