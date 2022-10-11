#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long dp[102000][2], n, c[102000]; string S[102000], T[102000];
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> c[i];
	for (int i = 0; i <= n; i++) { dp[i][0] = 1LL << 62; dp[i][1] = 1LL << 62; }
	for (int i = 1; i <= n; i++)cin >> S[i]; S[0] = "0";
	for (int i = 0; i <= n; i++) { T[i] = S[i]; reverse(T[i].begin(), T[i].end()); }
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (S[i - 1] <= S[i])dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (T[i - 1] <= S[i])dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (S[i - 1] <= T[i])dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if (T[i - 1] <= T[i])dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	long long ret = min(dp[n][0], dp[n][1]);
	if (ret > (1LL << 60))ret = -1;
	cout << ret << endl;
	return 0;
}