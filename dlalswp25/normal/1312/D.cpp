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

ll ncr(ll n, ll r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }

int main() {
	int N, M; scanf("%d%d", &N, &M);
	if(N == 2) { puts("0"); return 0; }

	F[0] = 1;
	for(int i = 1; i <= 200000; i++) F[i] = F[i - 1] * i % MOD;
	I[200000] = inv(F[200000]);
	for(int i = 199999; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	ll ans = 0;
	for(int k = N - 1; k <= M; k++) {
		ll t = (k - 1) * ncr(k - 2, N - 3) % MOD;
		t = t * pw(2, N - 3) % MOD;
		ans = (ans + t) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}