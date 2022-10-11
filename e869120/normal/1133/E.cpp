#include <iostream>
#include <algorithm>
using namespace std;

int N, K, A[5009], P[5009], dp[5009][5009];
int L[5009][6];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 5; j++) L[i][j] = lower_bound(A, A + N, A[i - 1] - j) - A;
	}

	for (int i = 0; i <= N; i++) { for (int j = 0; j <= N; j++) dp[i][j] = -(1 << 30); }

	for (int i = 0; i <= N; i++) dp[0][i] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= 5; k++) dp[i][j] = max(dp[i][j], dp[i - 1][L[j][k]] + (j - L[j][k]));
		}
		for (int j = 1; j <= N; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
	}
	int maxn = 0;
	for (int i = 0; i <= K; i++) { for (int j = 0; j <= N; j++) maxn = max(maxn, dp[i][j]); }

	cout << maxn << endl;
	return 0;
}