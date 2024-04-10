#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, K;
ll F[404];
ll I[404];
ll D[404][202];

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
	ll ret = 1;
	for(int i = n; i >= n - r + 1; i--) ret = ret * i % MOD;
	return ret * I[r] % MOD;
}

ll ncr2(int n, int r) {
	return F[n] * I[n - r] % MOD * I[r] % MOD;
}

int main() {
	scanf("%d%d", &N, &K);
	F[0] = 1;
	for(int i = 1; i <= 2 * K; i++) F[i] = F[i - 1] * i % MOD;
	I[2 * K] = inv(F[2 * K]);
	for(int i = 2 * K - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 0; i <= K; i += 2) {
		D[0][i] = 1;
	}

	for(int i = 2; i <= 2 * K; i++) {
		for(int j = 0; j <= K; j++) {
			for(int k = 2; k <= min(i, j + 1); k++) {
				D[i][j] = (D[i][j] + F[k - 1] * ncr2(i - 1, k - 1) % MOD * D[i - k][j - k + 1]) % MOD;
				// printf("%d %d %d %lld\n", i, j, k, D[i][j]);
			}
		}
	}

	for(int i = 1; i <= K; i++) {
		ll ans = 0;
		for(int j = 0; j <= min(2 * i, N); j++) {
			ans = (ans + ncr(N, j) * D[j][i]) % MOD;
			// printf("\n%d %d %lld\n", j, i, D[j][i]);
		}
		printf("%lld ", ans);
	}
	puts("");

	return 0;
}