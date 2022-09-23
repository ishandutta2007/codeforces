#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll F[202020];
ll I[202020];

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

ll ncr(ll n, ll r) {
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	ll N, K; scanf("%lld%lld", &N, &K);
	if(K >= N) { puts("0"); return 0; }

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	if(K == 0) { printf("%lld\n", F[N]); return 0; }

	int r = N - K;
	ll ans = 0;
	for(int i = 0; i < r; i++) {
		ll t =  pw(r - i, N) * ncr(r, i) % MOD;
		if(i & 1) t = MOD - t;
		ans = (ans + t) % MOD;
	}
	printf("%lld\n", 2 * ans * ncr(N, r) % MOD);

	return 0;
}