#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

// 
int N, M;
int L[10009], S[10009], P[10009];

int cnt[10009], maxv[10009], maxlim[10009];
int dp[2059][12][2059], nex[2059][12][2059];

void solve(int pos) {
	for (int i = 0; i <= N; i++) {
		for (int k = 0; k <= maxlim[pos]; k++) {
			if (i >= 1) {
				for (int j = 0; j <= maxv[pos]; j++) {
					dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k][j]);
				}
				if (L[i] == pos) {
					for (int j = 0; j <= maxv[pos] - 1; j++) {
						if (dp[i - 1][k][j + 1] == -(1 << 30)) continue;
						int bonus = 0, cx = j, cp = pos;
						while (cx > 0 && (cx & 1) == 0) { cp++; bonus += P[cp]; cx >>= 1; }
						dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k][j + 1] + P[pos] - S[i] + bonus);
					}
				}
			}
			if (dp[i][k][0] != -(1 << 30)) {
				int rem = 0;
				for (int j = 0; j <= k - 1; j++) {
					if ((1 << j) > maxv[pos]) break;
					dp[i][j][1 << j] = max(dp[i][j][1 << j], dp[i][k][0] + rem);
					rem += P[pos + j + 1];
				}
			}
		}
	}
	return;
}

int main() {
	//  1. 
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N + M; i++) cin >> P[i];

	//  2. 
	for (int i = 1; i <= N; i++) cnt[L[i]]++;
	for (int i = 1; i <= M; i++) maxv[i] = (maxv[i - 1] / 2) + cnt[i];
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= 12; j++) {
			if (maxv[i] < (1 << j)) { maxlim[i] = j; break; }
		}
	}

	//  3. DP 
	for (int i = 0; i <= N; i++) {
		for (int k = 0; k <= maxlim[M]; k++) {
			for (int j = 0; j <= maxv[M] + 1; j++) { dp[i][k][j] = -(1 << 30); }
		}
	}
	dp[0][maxlim[M]][0] = 0;

	for (int i = M; i >= 1; i--) {
		solve(i);
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= maxlim[i]; l++) {
				for (int k = 0; k <= maxv[i] + 1; k++) { nex[j][l][k] = dp[j][l][k]; }
			}
		}
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= maxlim[i - 1]; l++) {
				for (int k = 0; k <= maxv[i - 1] + 1; k++) dp[j][l][k] = -(1 << 30);
			}
		}
		int LIM = maxlim[i - 1];
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= maxlim[i]; l++) {
				for (int k = 0; k <= maxv[i] + 1; k++) {
					if (nex[j][l][k] == -(1 << 30)) continue;
					int bonus = 0; if (k >= 1) bonus = P[i];
					if (k * 2 <= maxv[i - 1]) dp[j][min(LIM, l + 1)][k * 2] = max(dp[j][min(LIM, l + 1)][k * 2], nex[j][l][k] + bonus);
				}
			}
		}
	}

	//  4. 
	cout << dp[N][0][0] << endl;
	return 0;
}