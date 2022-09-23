#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll F[202020];
ll I[202020];
int N, K;
int A[202020];
int a, b;

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

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]); A[N + 1] = A[1];

	for(int i = 1; i <= N; i++) {
		if(A[i] == A[i + 1]) a++;
		else b++;
	}

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	ll t = 0;
	for(int i = 0; i < b; i++) {
		ll x = 0;
		if((b - i) & 1) {
			x = pw(2, b - i - 1);
		}
		else {
			x = (pw(2, b - i) + MOD - ncr(b - i, (b - i) / 2)) * inv(2) % MOD;
		}
		t = (t + x * pw(K - 2, i) % MOD * ncr(b, i)) % MOD;
		// printf("%d %lld\n", i, t);
	}

	printf("%lld\n", t * pw(K, a) % MOD);

	return 0;
}