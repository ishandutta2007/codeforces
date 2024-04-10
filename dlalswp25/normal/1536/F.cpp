#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MX = 2000000;

ll F[2020202];
ll I[2020202];

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
	if(r < 0 || n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int N; scanf("%d", &N);
	ll ans = 0;

	for(int i = 1; 2 * i - 1 <= N - 1; i++) {
		int b = N - 1 - (2 * i - 1);
		ans = (ans + ncr(2 * i, b) * F[2 * i - 1]) % MOD;
	}
	printf("%lld\n", ans * 2 * N % MOD);

	return 0;
}