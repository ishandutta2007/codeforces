#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
ll ncr[4141][4141];
ll X[2121][2121];
ll Y[2121][2121];

ll nhr(int n, int r) {
	return ncr[n + r - 1][r];
}

int main() {
	for(int i = 0; i <= 4100; i++) ncr[i][0] = 1;
	for(int i = 1; i <= 4100; i++) {
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
	}

	scanf("%d%d", &N, &M);
	if(N <= 1 || M <= 1) { puts("0"); return 0; }

	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= M; j++) {
			X[i][j] = (X[i][j - 1] + nhr(i + 1, j - 1) * nhr(i, M - j)) % MOD;
		}
	}

	for(int j = 1; j <= M; j++) {
		for(int i = N - 1; i > 1; i--) {
			Y[i][j] = (Y[i + 1][j] + nhr(i + 1, j - 1) * nhr(N - i, j)) % MOD;
		}
	}

	ll ans = 0;

	for(int i = 2; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			ans = (ans + X[i - 1][j - 1] * nhr(N - i + 1, j - 1) % MOD * nhr(N - i + 2, M - j)) % MOD;
			// printf("%lld\n", X[i - 1][j - 1]);
			ans = (ans + Y[i][j - 1] * nhr(N - i + 2, M - j) % MOD * nhr(i - 1, M - j + 1)) % MOD;
			// printf("%d %d %lld\n", i, j, ans);
		}
	}

	printf("%lld\n", (ans + ans) % MOD);	

	return 0;
}