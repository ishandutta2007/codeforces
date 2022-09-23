#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll I2 = 500000004;

ll N, M, K;

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

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &K);
		ll ans = 0;
		ll ncr = 1;
		ll sum = 1;
		for(int i = 1; i <= M; i++) {
			ans = (ans + sum) % MOD;
			ncr = ncr * (N - i + 1) % MOD * inv(i) % MOD;
			sum = (sum + ncr) % MOD;
		}
		for(int i = 1; i < N; i++) ans = ans * I2 % MOD;
		printf("%lld\n", ans * K % MOD);
	}
	return 0;
}