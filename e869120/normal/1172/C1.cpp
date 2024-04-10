#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[59], W[59], LIKE, DISLIKE;
long long dp[59][59][59][59], inv[3009], divs[3009][3009], mod = 998244353;

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

void init() {
	for (int i = 1; i <= 3000; i++) inv[i] = modpow(i, mod - 2, mod);
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) divs[i][j] = (1LL * i * inv[j]) % mod;
	}
}

long long solve(int pos) {
	for (int i = 0; i <= M; i++) { for (int j = 0; j <= i; j++) { for (int k = 0; k <= i; k++) { for (int l = 0; l <= i; l++) dp[i][j][k][l] = 0; } } }

	dp[0][0][0][0] = 1;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i; k++) {
				for (int l = 0; l <= i; l++) {
					if (dp[i][j][k][l] == 0) continue;

					long long LA = LIKE + k, LB = DISLIKE - l;
					long long LC = W[pos];
					if (A[pos] == 1) { LC += j; LA -= LC; }
					if (A[pos] == 0) { LC -= j; LB -= LC; }

					// 
					if (LC >= 1) {
						if (A[pos] == 1) { dp[i + 1][j + 1][k + 1][l] += dp[i][j][k][l] * divs[LC][LA + LB + LC]; dp[i + 1][j + 1][k + 1][l] %= mod; }
						if (A[pos] == 0) { dp[i + 1][j + 1][k][l + 1] += dp[i][j][k][l] * divs[LC][LA + LB + LC]; dp[i + 1][j + 1][k][l + 1] %= mod; }
					}

					// LIKE 
					if (LA >= 1) {
						dp[i + 1][j][k + 1][l] += dp[i][j][k][l] * divs[LA][LA + LB + LC];
						dp[i + 1][j][k + 1][l] %= mod;
					}

					// DISLIKE 
					if (LB >= 1) {
						dp[i + 1][j][k][l + 1] += dp[i][j][k][l] * divs[LB][LA + LB + LC];
						dp[i + 1][j][k][l + 1] %= mod;
					}
				}
			}
		}
	}

	long long S = 0;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= M; k++) {
				long long V = W[pos];
				if (A[pos] == 1) V += i;
				if (A[pos] == 0) V -= i;
				S += V * dp[M][i][j][k];
				S %= mod;
			}
		}
	}
	return S;
}

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++) scanf("%lld", &W[i]);
	for (int i = 0; i < N; i++) { if (A[i] == 1) LIKE += W[i]; else DISLIKE += W[i]; }

	init();
	for (int i = 0; i < N; i++) cout << solve(i) << endl;
	return 0;
}