#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll A[1010101];
int C[1010101];

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
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int K; scanf("%d", &K);
		for(int j = 1; j <= K; j++) {
			int x; scanf("%d", &x);
			A[x] = (A[x] + inv(N) * inv(K)) % MOD;
			C[x]++;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= 1000000; i++) ans = (ans + A[i] * C[i] % MOD * inv(N)) % MOD;
	printf("%lld\n", ans); 

	return 0;
}