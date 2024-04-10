#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long dp[61][19][19], prevs[61][19][19];
long long mod = 1000000007;

void solve(long long C, long long K) {
	for (int i = 0; i <= 60; i++) { for (int j = 0; j < 19; j++) { for (int k = 0; k < 19; k++) { dp[i][j][k] = 0; prevs[i][j][k] = 0; } } }
	for (int i = 0; i < C; i++) { prevs[0][i][i] = 1; if (i >= 1) prevs[0][i][i - 1] = 1; if (i + 1 < C) prevs[0][i][i + 1] = 1; }
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < C; k++) {
				for (int l = 0; l < C; l++) {
					prevs[i + 1][j][l] += prevs[i][j][k] * prevs[i][k][l];
					prevs[i + 1][j][l] %= mod;
				}
			}
		}
	}
	for (int i = 0; i < C; i++) dp[0][i][i] = 1;
	for (int i = 0; i < 60; i++) {
		if ((K / (1LL << i)) % 2 == 0) {
			for (int j = 0; j < C; j++) { for (int k = 0; k < C; k++) dp[i + 1][j][k] = dp[i][j][k]; }
		}
		else {
			for (int j = 0; j < C; j++) {
				for (int k = 0; k < C; k++) {
					for (int l = 0; l < C; l++) {
						dp[i + 1][j][l] += dp[i][j][k] * prevs[i][k][l];
						dp[i + 1][j][l] %= mod;
					}
				}
			}
		}
	}
}

long long N, K, A[109], B[109], E[109], pr[109][19];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> E[i];
	pr[0][0] = 1;
	for (int i = 0; i < N; i++) {
		solve(E[i] + 1, min(B[i], K) - A[i]);
		for (int j = 0; j <= E[i]; j++) {
			for (int k = 0; k <= E[i]; k++) {
				pr[i + 1][k] += pr[i][j] * dp[60][j][k];
				pr[i + 1][k] %= mod;
			}
		}
	}
	cout << pr[N][0] << endl;
	return 0;
}