#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007;
long long N, A[109], B[109], dp[109][109][109], dp2[109][109][109], nr[109][109], s[109], ans[109];
vector<int>X[109], Y[109]; bool used[109];

void init() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
}

void dfs1(int pos) {
	used[pos] = true; s[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		Y[pos].push_back(X[pos][i]);
		dfs1(X[pos][i]);
		s[pos] += s[X[pos][i]];
	}
}

void dfs2(int pos) {
	for (int i = 0; i < Y[pos].size(); i++) dfs2(Y[pos][i]);

	int SS = 0, S = 0; for (int i = 0; i <= Y[pos].size(); i++) { for (int j = 0; j <= SS; j++) { for (int k = 0; k <= SS; k++) dp2[i][j][k] = 0; } if (i < Y[pos].size()) SS += s[Y[pos][i]]; }
	
	dp2[0][0][0] = 1;
	for (int i = 0; i < Y[pos].size(); i++) {
		for (int j = 0; j <= S; j++) {
			for (int k = 0; k <= S; k++) {
				if (dp2[i][j][k] == 0) continue;

				for (int l = 0; l <= s[Y[pos][i]]; l++) {
					for (int m = 0; m <= s[Y[pos][i]]; m++) {
						if (dp[Y[pos][i]][l][m] == 0) continue;
						dp2[i + 1][j + l][k + m] += dp2[i][j][k] * dp[Y[pos][i]][l][m];
						dp2[i + 1][j + l][k + m] %= mod;
					}
				}
			}
		}
		S += s[Y[pos][i]];
	}

	for (int i = 0; i <= S; i++) {
		for (int j = 0; j <= S; j++) {
			dp[pos][i + 1][0] += 1LL * (j + 1) * dp2[Y[pos].size()][i][j]; dp[pos][i + 1][0] %= mod;
			dp[pos][i][j + 1] += 1LL * dp2[Y[pos].size()][i][j]; dp[pos][i][j + 1] %= mod;
		}
	}
}

int main() {
	cin >> N; init();
	for (int i = 0; i < N - 1; i++) { cin >> A[i] >> B[i]; X[A[i]].push_back(B[i]); X[B[i]].push_back(A[i]); }
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= N; i++) {
		ans[i] = dp[1][i][0]; if (i == 1) ans[i] = 1;
		for (int j = 0; j < i - 2; j++) { ans[i] *= N; ans[i] %= mod; }
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i - 1; j++) {
			int v1 = N - i, v2 = N - j;
			ans[i] -= ans[j] * nr[v1][v2 - v1];
			ans[i] += mod * mod; ans[i] %= mod;
		}
	}
	for (int i = N; i >= 1; i--) { if (i != N) cout << " "; cout << ans[i]; } cout << endl;
	return 0;
}