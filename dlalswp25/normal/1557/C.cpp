#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 200000;
const ll MOD = 1000000007;

int N, K;
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

ll ncr(int n, int r) {
	if(n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		ll x = 0;
		for(int i = 0; i < N; i += 2) x = (x + ncr(N, i)) % MOD;
		ll ans = 0;
		ll now = 1;
		for(int i = 1; i <= K; i++) {
			ll t = 0;
			if(~N & 1) {
				ans = (ans + now * pw(2, (ll)N * (K - i))) % MOD;
			}
			else t = 1;
			now = now * (x + t) % MOD;
		}
		printf("%lld\n", (ans + now) % MOD);
	}
	return 0;
}