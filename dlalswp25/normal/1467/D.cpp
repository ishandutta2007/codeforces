#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, K, Q;
ll A[5050];
ll D[5050][5050];
ll U[5050][5050];
ll S[5050];

int main() {
	scanf("%d%d%d", &N, &K, &Q);
	for(int i = 1; i <= N; i++) D[0][i] = U[K][i] = 1;
	for(int i = 1; i <= K; i++) {
		for(int j = 1; j <= N; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % MOD;
		}
	}
	for(int i = K - 1; i >= 0; i--) {
		for(int j = 1; j <= N; j++) {
			U[i][j] = (U[i + 1][j - 1] + U[i + 1][j + 1]) % MOD;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= K; j++) {
			S[i] = (S[i] + U[j][i] * D[j][i]) % MOD;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		ans = (ans + A[i] * S[i]) % MOD;
	}

	while(Q--) {
		int a, b; scanf("%d%d", &a, &b);
		ans += (b - A[a] + MOD) * S[a];
		ans %= MOD;
		A[a] = b;
		printf("%lld\n", ans);
	}

	return 0;
}