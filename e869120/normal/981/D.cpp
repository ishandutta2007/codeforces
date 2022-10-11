#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1009]; bool dp[59][59];

long long solve(long long pos) {
	for (int i = 0; i <= N; i++) { for (int j = 0; j <= K; j++) dp[i][j] = false; }
	dp[0][0] = true;
	for (int i = 0; i < N; i++) {
		for (int t = 0; t <= K; t++) {
			if (dp[i][t] == false) continue;
			long long r = 0;
			for (int j = i + 1; j <= N; j++) {
				r += A[j - 1];
				if ((r&pos) == pos) dp[j][t + 1] = true;
			}
		}
	}
	return dp[N][K];
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];

	long long r = 0;
	for (int i = 60; i >= 0; i--) {
		bool t = solve(r + (1LL << i));
		if (t == true) r += (1LL << i);
	}
	cout << r << endl;
	return 0;
}