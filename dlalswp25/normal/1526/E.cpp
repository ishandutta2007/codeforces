#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 200000;
const ll MOD = 998244353;

int N, K;
int A[202020];
int pos[202020];

ll F[202020];
ll I[202020];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) {
	return pw(x, MOD - 2);
}

ll ncr(ll n, ll r) {
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	scanf("%d%d", &N, &K);

	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		pos[A[i]] = i;
	}
	pos[N] = -1;

	int cnt = 1;

	for(int i = 1; i < N; i++) {
		int a = A[i - 1], b = A[i];
		if(pos[a + 1] > pos[b + 1]) cnt++;
	}

	ll ans = 0;
	for(int i = cnt; i <= min(N, K); i++) {
		ans = (ans + ncr(K, i) * ncr(N - cnt, i - cnt)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}