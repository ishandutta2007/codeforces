#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 998244353;
long long N, A[100009], dp[100009][229][2];

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	for (int i = 1; i <= 200; i++) {
		if (A[1] == i || A[1] == -1) dp[1][i][1] = 1;
	}
	for (int i = 1; i < N; i++) {
		long long s = 0;
		for (int j = 200; j >= 1; j--) {
			s += dp[i][j][0]; if (s >= mod) s -= mod;

			if (A[i + 1] == j || A[i + 1] == -1) {
				dp[i + 1][j][0] = s + dp[i][j][1];
				if (dp[i + 1][j][0] >= mod) dp[i + 1][j][0] -= mod;
			}
		}

		long long t = 0;
		for (int j = 1; j <= 200; j++) {
			t += dp[i][j - 1][0] + dp[i][j - 1][1]; t %= mod;
			if (A[i + 1] == j || A[i + 1] == -1) {
				dp[i + 1][j][1] = t;
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= 200; i++) ans += dp[N][i][0];
	cout << ans % mod << endl;
	return 0;
}