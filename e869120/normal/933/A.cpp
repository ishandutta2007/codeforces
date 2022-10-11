#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[2019], dp[2019][2019][3];
int L[2019], R[2019];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) { if (A[i] == 1) L[i] = 1; if (A[i] == 2) R[i] = 1; }
	for (int i = 1; i <= N + 1; i++) L[i] += L[i - 1];
	for (int i = N; i >= 0; i--) R[i] += R[i + 1];

	for (int i = 1; i <= N; i++) {
		dp[i][i][A[i]] = 1;
		for (int j = i - 1; j >= 1; j--) {
			for (int k = 1; k <= A[j]; k++) {
				dp[i][j][A[j]] = max(dp[i][j][A[j]], dp[i][j + 1][k] + 1);
			}
			for (int k = 1; k <= 2; k++) {
				dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			ans = max(ans, L[i - 1] + max(dp[j][i][1], dp[j][i][2]) + R[j + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}