#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll X[202020];
ll Y[202020];
int Z[202020];
ll D[202020];
ll S[202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld%d", &X[i], &Y[i], &Z[i]);
	for(int i = 1; i <= N; i++) {
		int t = lower_bound(X + 1, X + N + 1, Y[i]) - X;
		D[i] = (S[i - 1] - S[t - 1] + X[i] - Y[i] + MOD + MOD) % MOD;
		S[i] = (S[i - 1] + D[i]) % MOD;
	}

	X[N + 1] = X[N] + 1;

	ll ans = X[1];
	for(int i = 1; i <= N; i++) {
		if(Z[i]) ans = (ans + D[i]) % MOD;
		ans = (ans + X[i + 1] - X[i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}