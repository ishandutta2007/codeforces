#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 200005;

int N;
ll F[202020];
ll I[202020];
ll D[202020];
ll ans[202020];

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
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	scanf("%d", &N);
	for(int i = 2; i <= (N + 1) / 2; i++) {
		ll t;
		if(i == 2) t = N - i - (N - 1) / 2 + 1;
		else {
			t = F[(N - 1) / 2] % MOD * I[(N - 1) / 2 - (i - 1)] % MOD;
			t = t * inv(i - 1) % MOD;
		}
		D[i] = F[N - i] * I[i - 2] % MOD * t % MOD;
		D[i] = D[i] * F[i - 1] % MOD * I[N - 1] % MOD;
	}

	ll s = 0;
	for(int i = (N + 1) / 2; i >= 2; i--) {
		ans[i] = F[N - 1] * (D[i] + MOD - s) % MOD;
		s = (s + D[i] * inv(i - 1)) % MOD;
	}

	ans[1] = ans[2];
	for(int i = 1; i <= N; i++) printf("%lld ", ans[i]); puts("");
	return 0;
}