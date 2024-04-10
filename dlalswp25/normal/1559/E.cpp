#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const ll W = 3;

int N, M;
int mu[101010];
int L[55];
int R[55];
int tl[55];
int tr[55];
ll D[2][101010];

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

ll solve(int g) {
	ll m = M / g;
	for(int i = 1; i <= N; i++) {
		tl[i] = (L[i] + g - 1) / g;
		tr[i] = R[i] / g;
	}
	for(int i = 1; i <= N; i++) { tr[i] -= tl[i]; m -= tl[i]; }
	if(m < 0) return 0;

	for(int i = 0; i <= m; i++) D[0][i] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= m; j++) {
			if(j <= tr[i]) D[i & 1][j] = D[i + 1 & 1][j];
			else D[i & 1][j] = (D[i + 1 & 1][j] + MOD - D[i + 1 & 1][j - tr[i] - 1]) % MOD;
		}
		for(int j = 1; j <= m; j++) D[i & 1][j] = (D[i & 1][j - 1] + D[i & 1][j]) % MOD;
	}
	return D[N & 1][m];
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d%d", &L[i], &R[i]);
	mu[1] = 1;
	for(int i = 1; i <= M; i++) {
		for(int j = i + i; j <= M; j += i) mu[j] -= mu[i];
	}
	
	ll ans = 0;
	for(int i = 1; i <= M; i++) {
		if(!mu[i]) continue;
		ll t = solve(i);
		// printf("%d %lld\n", i, t);
		ans = (ans + MOD + t * mu[i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}