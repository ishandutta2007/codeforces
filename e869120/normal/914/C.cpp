#include <iostream>
#include <string>
using namespace std;

int K, dp1[1009], dp[1009][1009][2], mod = 1000000007; string S;

int main() {
	dp1[1] = 0;
	for (int i = 2; i <= 1008; i++) {
		int cnt = 0;
		for (int j = 0; j < 10; j++) { if ((i / (1 << j)) % 2 == 1) cnt++; }
		dp1[i] = dp1[cnt] + 1;
	}
	cin >> S >> K;
	if (K == 0) { cout << "1" << endl; return 0; }
	if (K == 1) { cout << S.size() - 1 << endl; return 0; }
	dp[0][0][0] = 1;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			if (S[i] == '1') {
				dp[i + 1][j][1] += dp[i][j][0]; dp[i + 1][j][1] %= mod;
				dp[i + 1][j][1] += dp[i][j][1]; dp[i + 1][j][1] %= mod;
				dp[i + 1][j + 1][0] += dp[i][j][0]; dp[i + 1][j + 1][0] %= mod;
				dp[i + 1][j + 1][1] += dp[i][j][1]; dp[i + 1][j + 1][1] %= mod;
			}
			else {
				dp[i + 1][j][0] += dp[i][j][0]; dp[i + 1][j][0] %= mod;
				dp[i + 1][j][1] += dp[i][j][1]; dp[i + 1][j][1] %= mod;
				dp[i + 1][j + 1][1] += dp[i][j][1]; dp[i + 1][j + 1][1] %= mod;
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= S.size(); i++) {
		if (dp1[i] == K - 1) { sum += (dp[S.size()][i][0] + dp[S.size()][i][1]) % mod; sum %= mod; }
	}
	cout << sum << endl;
	return 0;
}