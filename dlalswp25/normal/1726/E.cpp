#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 300000;

int N;
ll F[606060];
ll I[606060];
ll pw2[303030];
ll D[303030];
ll E[303030];

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

ll ncr(int n, int r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }
ll nhr(int n, int r) { return ncr(n + r - 1, r); }

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX + MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX + MX] = inv(F[MX + MX]);
	for(int i = MX + MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;
	pw2[0] = 1;
	for(int i = 1; i <= MX; i++) pw2[i] = pw2[i - 1] * 2 % MOD;

	D[0] = D[1] = 1;
	for(int i = 2; i <= MX; i++) D[i] = (D[i - 1] + (i - 1) * D[i - 2]) % MOD;
	E[0] = E[2] = 1;
	for(int i = 4; i <= MX; i += 2) E[i] = (i - 1) * E[i - 2] % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		ll ans = 0;
		for(int k = 0; k + k <= N; k += 2) {
			ans = (ans + nhr(k + 1, N - 2 * k) * pw2[k / 2] % MOD * D[N - 2 * k] % MOD * E[k]) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}