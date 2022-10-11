#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1 << 20], dp[1 << 20][5][5], mod3[1 << 20], div3[1 << 20];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int c; scanf("%d", &c); A[c]++;
	}
	for (int i = 0; i < (1 << 20); i++) { mod3[i] = (i % 3); div3[i] = (i / 3); }

	for (int i = 0; i <= M + 3; i++) {
		for (int j = 0; j < 5; j++) { for (int k = 0; k < 5; k++) { dp[i][j][k] = -(1 << 30); } }
	}
	dp[0][0][0] = 0;
	for (int i = 0; i <= M + 3; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (dp[i][j][k] == -(1 << 30)) continue;

				int a0 = A[i + 1], a1 = j, a2 = k;
				for (int l = 0; l <= min({ a0, a1, a2 }); l++) {
					int s0 = a0 - l, s1 = a1 - l, s2 = a2 - l;
					int v0 = mod3[s0], c0 = div3[s0];

					for (int m = v0; m <= 7; m += 3) {
						dp[i + 1][min(4, m)][s1] = max(dp[i + 1][min(4, m)][s1], dp[i][j][k] + c0 + l);
						c0--; if (c0 < 0) break;
					}
				}
			}
		}
	}
	cout << dp[M + 4][0][0] << endl;
	return 0;
}