#include <iostream>
#include <algorithm>
using namespace std;

int N, H[5009], dp[5009][5009][3];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = 0; i <= N + 1; i++) { for (int j = 0; j <= N + 1; j++) { for (int k = 0; k < 3; k++) dp[i][j][k] = (1 << 30); } }
	dp[1][0][2] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k < 3; k++) {
				if (dp[i][j][k] == (1 << 30)) continue;

				// 
				if (k >= 1) {
					int s = max(0, H[i - 1] - H[i] + 1) + max(0, H[i + 1] - H[i] + 1);
					if (k == 1) {
						int v1 = max(0, H[i - 1] - H[i - 2] + 1);
						int v2 = max(0, H[i - 1] - H[i] + 1);
						s = max(0, H[i + 1] - H[i] + 1) + max(v1, v2) - v1;
					}
					dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dp[i][j][k] + s);
				}

				// 
				dp[i + 1][j][min(k + 1, 2)] = min(dp[i + 1][j][min(k + 1, 2)], dp[i][j][k]);
			}
		}
	}
	for (int i = 1; i <= (N + 1) / 2; i++) {
		if (i >= 2) cout << " ";
		cout << min({ dp[N + 1][i][0], dp[N + 1][i][1], dp[N + 1][i][2] });
	}
	cout << endl;
	return 0;
}