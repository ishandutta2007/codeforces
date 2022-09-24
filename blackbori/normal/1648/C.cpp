#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

struct fenwick {
	ll T[202020];
	void add(ll i, ll x) { for (; i <= 2e5; i += i & -i) T[i] += x; }
	ll sum(ll i) { return i ? sum(i - (i & -i)) + T[i] : 0; }
} T;

ll A[202020], B[202020], S[202020], F[202020], IF[202020];
ll n, m, a;

ll inv(ll x) { return x > 1 ? (mod - mod / x) * inv(mod % x) % mod : 1; }

void tc() {
	ll i, s;
	cin >> n >> m;
	for (F[0] = i = 1; i <= n; i++) {
		F[i] = F[i - 1] * i % mod;
	}
	IF[n] = inv(F[n]);
	for (i = n; i >= 1; i--) {
		IF[i - 1] = IF[i] * i % mod;
	}

	for (i = 1; i <= n; i++) {
		cin >> A[i]; S[A[i]]++;
		T.add(A[i], 1);
	}
	s = 1;
	for (i = 1; i <= 2e5; i++) {
		s = s * IF[S[i]] % mod;
	}

	for (i = 1; i <= m; i++) {
		cin >> B[i];
		a = (a + s * F[n - i] % mod * T.sum(B[i] - 1)) % mod;
		if (!S[B[i]]) {
			if (i > n) a = (a + 1) % mod;
			break;
		}
		s = s * S[B[i]] % mod;
		S[B[i]]--; T.add(B[i], -1);
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