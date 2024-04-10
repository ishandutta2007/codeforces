#include <iostream>
using namespace std;

long long dp[62][109][109], ans[62][109];
long long N, M, mod = 1000000007;

void init() {
	dp[0][0][0] = 1; dp[0][M - 1][0] = 1;
	for (int i = 0; i < M - 1; i++) dp[0][i][i + 1] = 1;
	
	for (int i = 0; i < 61; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					dp[i + 1][j][l] += dp[i][j][k] * dp[i][k][l];
					dp[i + 1][j][l] %= mod;
				}
			}
		}
	}
}

void solve() {
	ans[0][0] = 1;
	for (int i = 0; i < 61; i++) {
		if ((N / (1LL << i)) % 2 == 0) {
			for (int j = 0; j < M; j++) ans[i + 1][j] = ans[i][j];
		}
		else {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) {
					ans[i + 1][k] += ans[i][j] * dp[i][j][k];
					ans[i + 1][k] %= mod;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	init();
	solve();
	cout << ans[61][0] << endl;
	return 0;
}