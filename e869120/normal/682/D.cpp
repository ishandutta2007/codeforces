#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp[1009][1009][12][2], a, b, c; string S, T;
int main() {
	cin >> a >> b >> c >> S >> T; S += '~'; T += '-';
	for (int i = 0; i < 1009; i++) { for (int j = 0; j < 1009; j++) { for (int k = 0; k < 12; k++) { for (int l = 0; l < 2; l++)dp[i][j][k][l] = -999999999; } } }
	dp[0][0][0][0] = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < T.size(); j++) {
			for (int k = 0; k <= c; k++) {
				dp[i + 1][j][k][0] = max(dp[i + 1][j][k][0], dp[i][j][k][0]);
				dp[i + 1][j][k + 1][0] = max(dp[i + 1][j][k + 1][0], dp[i][j][k][1]);
				dp[i][j + 1][k][0] = max(dp[i][j + 1][k][0], dp[i][j][k][0]);
				dp[i][j + 1][k + 1][0] = max(dp[i][j + 1][k + 1][0], dp[i][j][k][1]);
				if (S[i] == T[j] && k != c) {
					dp[i + 1][j + 1][k][1] = max(dp[i + 1][j + 1][k][1], dp[i][j][k][0] + 1);
					dp[i + 1][j + 1][k][1] = max(dp[i + 1][j + 1][k][1], dp[i][j][k][1] + 1);
					dp[i + 1][j + 1][k + 1][0] = max(dp[i + 1][j + 1][k + 1][0], dp[i][j][k][0] + 1);
					dp[i + 1][j + 1][k + 1][0] = max(dp[i + 1][j + 1][k + 1][0], dp[i][j][k][1] + 1);
					dp[i + 1][j + 1][k + 1][1] = max(dp[i + 1][j + 1][k + 1][1], dp[i][j][k][0] + 1);
					dp[i + 1][j + 1][k + 1][1] = max(dp[i + 1][j + 1][k + 1][1], dp[i][j][k][1] + 1);
				}
			}
		}
	}
	cout << dp[a][b][c][0] << endl;
	return 0;
}