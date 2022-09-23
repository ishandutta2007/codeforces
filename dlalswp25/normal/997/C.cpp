#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll N;
ll ans;

ll F[1010101];
ll I[1010101];

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

ll ncr(int n, int r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }

int main() {
	scanf("%lld", &N);
	F[0] = 1; for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 0; i <= N - 1; i++) {
		ll i3 = pw(3, i);
		ll t = (pw((MOD + 1 - i3) % MOD, N) + MOD - pw((MOD - i3) % MOD, N)) % MOD;
		if(!(i & 1)) t = (MOD - t) % MOD;
		ans = (ans + 3LL * ncr(N, i) * t) % MOD;
	}

	for(int i = 1; i <= N; i++) {
		ll t = pw(3, N * (N - i) + i);
		if(!(i & 1)) t = (MOD - t) % MOD;
		ans = (ans + 2LL * ncr(N, i) * t) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}