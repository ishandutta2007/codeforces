#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int dp[509][30009], N;

void solve() {
	int B = min(N, 500);

	dp[0][0] = 1;
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B * 50; j++) {
			if (dp[i][j] == 0) continue;
			dp[i + 1][j + 1] = 1;
			dp[i + 1][j + 5] = 1;
			dp[i + 1][j + 10] = 1;
			dp[i + 1][j + 50] = 1;
		}
	}
}

int main() {
	cin >> N;
	solve();

	if (N <= 500) {
		int sum = 0;
		for (int i = 0; i <= 50 * N; i++) sum += dp[N][i];
		cout << sum << endl;
	}
	else {
		cout << 49LL * N - 247LL << endl;
	}
	return 0;
}