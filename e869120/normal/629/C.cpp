#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int dp[4005][4005], mod = 1000000007;
int main() {
	dp[0][0] = 1;
	for (int i = 0; i < 4002; i++) {
		for (int j = 0; j < 4002; j++) {
			if (j >= 1) { dp[i + 1][j - 1] += dp[i][j]; dp[i + 1][j - 1] %= mod; }
			dp[i + 1][j + 1] += dp[i][j]; dp[i + 1][j + 1] %= mod;
		}
	}
	int n, m; cin >> n >> m;
	string S; cin >> S;
	int lw = 0, ct = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ')')ct--; else ct++;
		lw = min(lw, ct);
	}
	long long ret = 0;
	if (ct >= 2003) { cout << "0" << endl; return 0; }
	for (int i = 0; i <= n - m; i++) {
		for (int j = -lw; j <= n - m; j++) {
			ret += 1LL * dp[i][j] * dp[(n - m) - i][j + ct];
			ret %= mod;
		}
	}
	cout << ret << endl;
	return 0;
}