#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll A[15], P[15][15], D[1 << 15];
ll n, a;

ll inv(ll x) { return x > 1 ? (mod - mod / x) * inv(mod % x) % mod : 1; }

ll calc(ll w, ll l) {
	ll x, y, t = 1;
	for (x = 0; x < n; x++) if (w & 1 << x) {
		for (y = 0; y < n; y++) if (l & 1 << y) {
			t = t * P[x][y] % mod;
		}
	}
	return t;
}

void tc() {
	ll i, j, x, y, s, c, t;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			P[i][j] = A[i] * inv(A[i] + A[j]) % mod;
		}
	}
	a = 0;
	for (i = 0; i < 1 << n; i++) {
		s = 1;
		for (j = i - 1 & i; j; j = j - 1 & i) {
			s = (s - D[i - j] * calc(i - j, j)) % mod;
		}
		if (s < 0) s += mod;
		D[i] = s;
		for (j = c = 0; j < n; j++) {
			if (i & 1 << j) c++;
		}
		a = (a + c * s % mod * calc(i, (1 << n) - 1 - i) % mod) % mod;
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}