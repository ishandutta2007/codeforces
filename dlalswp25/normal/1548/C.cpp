#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, Q;
ll D[3030303][3];
ll F[3030303];
ll FI[3030303];
ll I[3030303];
ll ncr[3030303];

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
	scanf("%d%d", &N, &Q);
	F[0] = 1;
	for(int i = 1; i <= 3 * N; i++) F[i] = F[i - 1] * i % MOD;
	FI[3 * N] = inv(F[3 * N]);
	for(int i = 3 * N - 1; i >= 0; i--) FI[i] = FI[i + 1] * (i + 1) % MOD;
	for(int i = 1; i <= 3 * N; i++) I[i] = FI[i] * F[i - 1] % MOD;
	ncr[0] = 1;
	for(int i = 1; i <= 3 * N; i++) ncr[i] = ncr[i - 1] * (3 * N - i + 2) % MOD * I[i] % MOD;

	D[3 * N][0] = 1;
	D[3 * N][1] = D[3 * N][2] = 0;

	for(int i = 3 * N - 1; i >= 1; i--) {
		D[i][0] = (D[i + 1][1] + MOD - D[i + 1][0] + ncr[i + 1]) % MOD;
		D[i][1] = (D[i + 1][2] + MOD - D[i + 1][1]) % MOD;
		D[i][2] = (D[i + 1][0] + MOD - D[i + 1][2]) % MOD;
	}

	while(Q--) {
		int x; scanf("%d", &x);
		printf("%lld\n", D[x][0]);
	}
	return 0;
}