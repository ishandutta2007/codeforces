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

ll ncr(ll n, ll r) {
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

ll nhr(ll n, ll r) {
	return ncr(n + r - 1, r);
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		ll ans = 0;
		ll bef = 0;
		for(int i = 2; i <= N; i++) {
			ll lft = N - (i + (ll)(i - 1) * (K - 1));
			ll t;
			if(lft < 0) t = F[N];
			else t = (F[N] + MOD - nhr(i + 1, lft) * F[i] % MOD * F[N - i] % MOD) % MOD;
			ans = (ans + i * (t + MOD - bef)) % MOD;
			bef = t;
		}
		printf("%lld\n", ans * I[N] % MOD);
	}
	return 0;
}