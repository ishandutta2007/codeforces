#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N = 100000;
ll A[101010];
int mu[101010];

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
	int M; scanf("%d", &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		A[a] = b;
	}

	mu[1] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = i * 2; j <= N; j += i) mu[j] -= mu[i];
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ll s = 0, sq = 0;
		ll K = 0;
		for(int j = i; j <= N; j += i) {
			K += A[j];
			s = (s + A[j] * j) % MOD;
			sq = (sq + A[j] * j % MOD * j) % MOD;
		}

		if(K < 2) continue;

		ll t1 = sq * pw(2, K - 2) % MOD * ((K - 1) % MOD) % MOD;

		ll n2 = (s * s + MOD - sq) % MOD;
		ll t2 = pw(2, K - 2);
		if(K >= 3) t2 = (t2 + ((K - 2) % MOD) * pw(2, K - 3)) % MOD;
		t2 = t2 * n2 % MOD;
		ans = (ans + ((t1 + t2) % MOD * mu[i] + MOD)) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}