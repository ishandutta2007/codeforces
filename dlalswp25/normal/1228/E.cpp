#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, K;
ll ncr[252][252];

void init() {
	ncr[0][0] = 1;
	for(int i = 1; i <= 250; i++) {
		ncr[i][0] = 1;
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
	}
}

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	init();

	ll ans = 0;
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			ll t = ncr[N][i] * ncr[N][j] % MOD;
			int x = (N - i) * (N - j);
			t = t * pw(K, x) % MOD;
			t = t * pw(K - 1, N * N - x) % MOD;
			if(i + j & 1) t = (MOD - t) % MOD;
			ans = (ans + t) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}