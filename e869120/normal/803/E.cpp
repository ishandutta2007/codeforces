#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S; int dp[1005][3005]; int n, k;
int main() {
	cin >> n >> k >> S;
	for (int i = 0; i < 1005; i++) { for (int j = 0; j < 3005; j++) { dp[i][j] = -1; } }
	dp[0][1500] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1500 - k + 1; j <= 1500 + k - 1; j++) {
			if (dp[i][j] == -1)continue;
			if (S[i] == 'W' || S[i] == '?') { dp[i + 1][j + 1] = j; }
			if (S[i] == 'L' || S[i] == '?') { dp[i + 1][j - 1] = j; }
			if (S[i] == 'D' || S[i] == '?') { dp[i + 1][j + 0] = j; }
		}
	}
	if (dp[n][1500 + k] == -1 && dp[n][1500 - k] == -1) { cout << "NO" << endl; return 0; }
	int F = 1500 + k; if (dp[n][1500 + k] == -1)F = 1500 - k;
	for (int i = n - 1; i >= 0; i--) {
		int G = F; F = dp[i + 1][F];
		if (G - F == 1)S[i] = 'W'; if (G - F == 0)S[i] = 'D'; if (G - F == -1)S[i] = 'L';
	}
	cout << S << endl;
	return 0;
}