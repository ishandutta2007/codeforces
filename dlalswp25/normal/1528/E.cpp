#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll D[1010101];
ll E[1010101];
ll F[1010101];
ll S[1010101];

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
	if(N == 1) { puts("5"); return 0; }
	D[0] = 1; D[1] = 2;
	S[0] = 1; S[1] = 3;

	E[0] = 0; E[1] = 1;
	F[0] = 1; F[1] = 3;

	for(int i = 2; i <= N; i++) {
		ll t = 0;
		ll a = D[i - 1], b = S[i - 2];
		t = (t + a * b) % MOD;
		t = (t + a * (a + 1) / 2) % MOD;
		E[i] = t;

		t = (t + a) % MOD;
		D[i] = t;

		t = (t + a * (b * (b + 1) / 2 % MOD)) % MOD;
		t = (t + a * (a + 1) / 2 % MOD * b) % MOD;
		t = (t + a * (a + 1) % MOD * (a + 2) % MOD * inv(6)) % MOD;
		F[i] = t;

		S[i] = (S[i - 1] + D[i]) % MOD;
	}

	ll ans = (F[N] + MOD - 1) % MOD;
	// printf("%lld\n", ans);
	for(int i = 1; i < N; i++) {
		ans = (ans + E[N - i] * (D[i - 1] + MOD - 1)) % MOD;
	}
	ans = (ans + F[N]) % MOD;

	printf("%lld\n", ans);
	return 0;
}