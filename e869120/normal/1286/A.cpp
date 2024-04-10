#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<pair<int, int>> vec;
int N, A[1 << 18], s0, s1;
bool used[109];
int dp[109][109][109][2];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] >= 1) {
			used[A[i]] = true;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == true) continue;
		if (i % 2 == 0) s0++;
		if (i % 2 == 1) s1++;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= N; k++) {
				dp[i][j][k][0] = (1 << 30);
				dp[i][j][k][1] = (1 << 30);
			}
		}
	}

	dp[0][0][0][0] = 0;
	dp[0][0][0][1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= s0; j++) {
			for (int k = 0; k <= s1; k++) {
				if (A[i] >= 1 && A[i] % 2 == 0) {
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k][0]);
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k][1] + 1);
				}
				else if (A[i] >= 1 && A[i] % 2 == 1) {
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][0] + 1);
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][1]);
				}
				else {
					if (j < s0) {
						dp[i][j + 1][k][0] = min(dp[i][j + 1][k][0], dp[i - 1][j][k][0]);
						dp[i][j + 1][k][0] = min(dp[i][j + 1][k][0], dp[i - 1][j][k][1] + 1);
					}
					if (k < s1) {
						dp[i][j][k + 1][1] = min(dp[i][j][k + 1][1], dp[i - 1][j][k][0] + 1);
						dp[i][j][k + 1][1] = min(dp[i][j][k + 1][1], dp[i - 1][j][k][1]);
					}
				}
			}
		}
	}

	cout << min(dp[N][s0][s1][0], dp[N][s0][s1][1]) << endl;
	return 0;
}