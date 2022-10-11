#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, Q, dp[335][335][335], pre[100009][27];
string S1, S2, S3, S;

int main() {
	scanf("%d%d", &N, &Q); cin >> S;
	for (int i = 0; i <= N + 2; i++) { for (int j = 0; j <= 26; j++) pre[i][j] = N + 1; }
	for (int i = 0; i < N; i++) pre[i][S[i] - 'a'] = i;
	for (int i = N - 1; i >= 0; i--) { for (int j = 0; j < 26; j++) pre[i][j] = min(pre[i][j], pre[i + 1][j]); }

	dp[0][0][0] = -1;

	for (int t = 1; t <= Q; t++) {
		char d1; int d2; char d3;
		cin >> d1 >> d2; if (d1 == '+') cin >> d3;

		if (d1 == '+') {
			if (d2 == 1) {
				S1 += d3; int B = S1.size();
				for (int i = 0; i <= S2.size(); i++) {
					for (int j = 0; j <= S3.size(); j++) {
						dp[B][i][j] = pre[dp[B - 1][i][j] + 1][S1[B - 1] - 'a'];
					}
				}
				for (int i = 0; i <= S2.size(); i++) {
					for (int j = 0; j <= S3.size(); j++) {
						if (i < S2.size()) dp[B][i + 1][j] = min(dp[B][i + 1][j], pre[dp[B][i][j] + 1][S2[i] - 'a']);
						if (j < S3.size()) dp[B][i][j + 1] = min(dp[B][i][j + 1], pre[dp[B][i][j] + 1][S3[j] - 'a']);
					}
				}
			}
			if (d2 == 2) {
				S2 += d3; int B = S2.size();
				for (int i = 0; i <= S1.size(); i++) {
					for (int j = 0; j <= S3.size(); j++) {
						dp[i][B][j] = pre[dp[i][B - 1][j] + 1][S2[B - 1] - 'a'];
					}
				}
				for (int i = 0; i <= S1.size(); i++) {
					for (int j = 0; j <= S3.size(); j++) {
						if (i < S1.size()) dp[i + 1][B][j] = min(dp[i + 1][B][j], pre[dp[i][B][j] + 1][S1[i] - 'a']);
						if (j < S3.size()) dp[i][B][j + 1] = min(dp[i][B][j + 1], pre[dp[i][B][j] + 1][S3[j] - 'a']);
					}
				}
			}
			if (d2 == 3) {
				S3 += d3; int B = S3.size();
				for (int i = 0; i <= S1.size(); i++) {
					for (int j = 0; j <= S2.size(); j++) {
						dp[i][j][B] = pre[dp[i][j][B - 1] + 1][S3[B - 1] - 'a'];
					}
				}
				for (int i = 0; i <= S1.size(); i++) {
					for (int j = 0; j <= S2.size(); j++) {
						if (i < S1.size()) dp[i + 1][j][B] = min(dp[i + 1][j][B], pre[dp[i][j][B] + 1][S1[i] - 'a']);
						if (j < S2.size()) dp[i][j + 1][B] = min(dp[i][j + 1][B], pre[dp[i][j][B] + 1][S2[j] - 'a']);
					}
				}
			}
		}
		if (d1 == '-') {
			if (d2 == 1) S1 = S1.substr(0, S1.size() - 1);
			if (d2 == 2) S2 = S2.substr(0, S2.size() - 1);
			if (d2 == 3) S3 = S3.substr(0, S3.size() - 1);
		}

		if (dp[S1.size()][S2.size()][S3.size()] <= N) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}