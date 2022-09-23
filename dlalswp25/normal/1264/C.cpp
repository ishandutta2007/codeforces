#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

set<int> S;
ll P[202020];
ll A[202020];
ll B[202020];

int N, Q;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll query(int l, int r) {
	return (B[r] + MOD - A[r] * inv(A[l - 1]) % MOD * B[l - 1] % MOD) % MOD;
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &P[i]);
		P[i] = 100 * inv(P[i]) % MOD;
	}

	A[0] = 1;
	for(int i = 1; i <= N; i++) A[i] = A[i - 1] * P[i] % MOD;

	B[1] = P[1];
	for(int i = 2; i <= N; i++) B[i] = P[i] * (B[i - 1] + 1) % MOD;

	ll ans = B[N];
	S.insert(1); S.insert(N + 1);

	// for(int i = 1; i <= N; i++) printf("%lld ", P[i]);
	// for(int i = 1; i <= N; i++) printf("%lld ", A[i]);
	// for(int i = 1; i <= N; i++) printf("%lld ", B[i]);

	while(Q--) {
		int x; scanf("%d", &x);
		auto it = S.find(x);

		int l, r;
		bool fg = true;
		ll t = 0;

		if(it == S.end()) {
			fg = false;
			it = S.lower_bound(x); r = *it;
			it--; l = *it;
			S.insert(x);
		}
		else {
			it++; r = *it;
			it--; it--; l = *it;
			S.erase(x);
		}

		t = (t + MOD - query(l, r - 1)) % MOD;
		t = (t + query(l, x - 1)) % MOD;
		t = (t + query(x, r - 1)) % MOD;

		if(fg) ans = (ans + MOD - t) % MOD;
		else ans = (ans + t) % MOD;
		printf("%lld\n", ans);
	}

	return 0;
}