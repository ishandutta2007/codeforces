#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const long long mod = 998244353;
long long dp[22][1035][2], dp2[22][1035][2], power[22];

int calc(int p, int q) {
	if (p == 1024) {
		if (q == 0) return 1024;
		return (1 << q);
	}
	return (p | (1 << q));
}

long long solve(long long R, long long K) {
	power[0] = 1; for (int i = 1; i <= 21; i++) power[i] = (10LL * power[i - 1]) % mod;
	string str = to_string(R); while (str.size() < 21) str = "0" + str;
	reverse(str.begin(), str.end());

	// DP
	for (int i = 0; i < 22; i++) { for (int j = 0; j < 1025; j++) { for (int k = 0; k < 2; k++) { dp[i][j][k] = 0; dp2[i][j][k] = 0; } } }
	
	dp2[20][1024][1] = 1;
	for (int i = 19; i >= 0; i--) {
		for (int j = 0; j < 1025; j++) {
			for (int k = 0; k <= 9; k++) {
				if (dp2[i + 1][j][0] == 0 && dp[i + 1][j][0] == 0) continue;
				int u = calc(j, k);
				dp2[i][u][0] += dp2[i + 1][j][0];
				dp2[i][u][0] %= mod;
				dp[i][u][0] += dp[i + 1][j][0] + 1LL * k * dp2[i + 1][j][0] * power[i];
				dp[i][u][0] %= mod;
			}
			for (int k = 0; k <= (str[i] - '0'); k++) {
				if (dp2[i + 1][j][1] == 0 && dp[i + 1][j][1] == 0) continue;
				int u = calc(j, k), v = 0; if (k == (str[i] - '0')) v = 1;
				dp2[i][u][v] += dp2[i + 1][j][1];
				dp2[i][u][v] %= mod;
				dp[i][u][v] += dp[i + 1][j][1] + 1LL * k * dp2[i + 1][j][1] * power[i];
				dp[i][u][v] %= mod;
			}
		}
	}

	long long rem = 0;
	for (int i = 0; i < 1024; i++) {
		int popcnts = 0; for (int j = 0; j < 10; j++) { if ((i / (1 << j)) % 2 == 1) popcnts++; }
		if (popcnts <= K) { rem += (dp[0][i][0] + dp[0][i][1]); rem %= mod; }
	}
	return rem;
}

int main() {
	long long L, R, K; cin >> L >> R >> K;
	long long V1 = solve(L - 1, K);
	long long V2 = solve(R, K);
	cout << (V2 - V1 + mod) % mod << endl;
	return 0;
}