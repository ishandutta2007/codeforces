#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;
typedef long long ll;

ll F[1000005];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) {
	return pw(x, MOD - 2);
}

int main() {
	int N; scanf("%d", &N); F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;

	ll ans = F[N];

	for(int k = 1; k < N; k++) {
		ll t = F[N] * inv(F[N - k]) % MOD;
		t = t * (F[N - k] + MOD - 1) % MOD;
		ans = (ans + t) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}