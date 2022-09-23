#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll F[505050];
ll I[505050];

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
	if(n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	int N, K; scanf("%d%d", &N, &K);
	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);

	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = ans + ncr(N / i - 1, K - 1);
		ans %= MOD;
	}
	printf("%lld\n", ans);

	return 0;
}