#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

int N, A[5009], C[5009], dp[5009][5009], cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		if (A[i] != A[i + 1] || i == N - 1) {
			C[cnt] = A[i]; cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) { for (int j = 0; j < cnt; j++) dp[i][j] = (1 << 30); }
	for (int i = 0; i < cnt; i++) dp[i][i] = 0;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			int L = j, R = j + i; if (R >= cnt) continue;

			if (L >= 1) dp[L - 1][R] = min(dp[L - 1][R], dp[L][R] + 1);
			if (R < N - 1) dp[L][R + 1] = min(dp[L][R + 1], dp[L][R] + 1);
			if (L >= 1 && R < N - 1 && C[L - 1] == C[R + 1]) dp[L - 1][R + 1] = min(dp[L - 1][R + 1], dp[L][R] + 1);
		}
	}
	cout << dp[0][cnt - 1] << endl;
	return 0;
}