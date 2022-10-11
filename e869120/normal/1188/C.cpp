#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, A[100009], P[100009], dp[1009][1009][2], mod = 998244353;

long long solve(int pos) {
	for (int i = 0; i <= N; i++) { for (int j = 0; j <= K; j++) { dp[i][j][0] = 0; dp[i][j][1] = 0; } }
	for (int i = 0; i <= N; i++) dp[i][0][0] = 1;
	for (int i = 1; i <= N; i++) {
		int id1 = 1; if (A[i] - pos >= 0) id1 = P[A[i] - pos];
		int id2 = 1; if (A[i] - (pos - 1) >= 0) id2 = P[A[i] - (pos - 1)];

		for (int j = 1; j <= min(i, (int)K); j++) {
			for (int k = 0; k < 2; k++) {
				//  K + 1 
				dp[i][j][k] += dp[id1 - 1][j - 1][k];

				//  K
				if (k == 1) {
					dp[i][j][k] += (dp[id2 - 1][j - 1][0] - dp[id1 - 1][j - 1][0] + mod);
					dp[i][j][k] += (dp[id2 - 1][j - 1][1] - dp[id1 - 1][j - 1][1] + mod);
				}
				dp[i][j][k] += dp[i - 1][j][k];
				while (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
			}
		}
	}
	return dp[N][K][1];
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);
	for (int i = 0; i <= 100001; i++) P[i] = N + 1;
	for (int i = 1; i <= N; i++) { P[A[i]] = min(P[A[i]], 1LL * i); }
	for (int i = 100000; i >= 0; i--) P[i] = min(P[i], P[i + 1]);

	long long ans = 0;
	for (int i = 1; i <= 100000 / (K - 1); i++) {
		long long E = solve(i);
		ans += 1LL * E * i;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}