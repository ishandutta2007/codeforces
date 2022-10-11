#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[200009], W[200009], LIKE, DISLIKE;
long long dp[3009][3009], D[20009], mod = 998244353;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1LL << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++) scanf("%lld", &W[i]);
	for (int i = 0; i < N; i++) { if (A[i] == 1) LIKE += W[i]; else DISLIKE += W[i]; }

	for (int i = 0; i <= 20000; i++) D[i] = modpow(LIKE + DISLIKE + (i - 10000), mod - 2, mod);

	dp[0][0] = 1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j] == 0) continue;

			long long EA = (LIKE + i), EB = (DISLIKE - j);
			long long F = D[10000 + i - j];
			dp[i + 1][j] += dp[i][j] * (EA*F%mod); dp[i + 1][j] %= mod;
			dp[i][j + 1] += dp[i][j] * (EB*F%mod); dp[i][j + 1] %= mod;
		}
	}

	long long S1 = 0, S2 = 0;
	for (int i = 0; i <= M; i++) {
		S1 += 1LL * (LIKE + i) * dp[i][M - i]; S1 %= mod;
		S2 += 1LL * (DISLIKE - i) * dp[M - i][i]; S2 %= mod;
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == 1) cout << (S1*W[i] % mod) * modpow(LIKE, mod - 2, mod) % mod << endl;
		if (A[i] == 0) cout << (S2*W[i] % mod) * modpow(DISLIKE, mod - 2, mod) % mod << endl;
	}
	return 0;
}