#include<iostream>
using namespace std;
long long a[50], b[50], dp[50][50];
int main() {
	long long a1, a2; cin >> a1 >> a2;
	for (int i = 0; i < 50; i++) { a[i] = (a1 / (1LL << i)) % 2; b[i] = (a2 / (1LL << i)) % 2; }
	dp[0][0] = 1;
	for (int i = 0; i < 48; i++) {
		if (b[i] == 1) { if (a[i] == 1)dp[i + 1][0] += dp[i][0] * 2; else dp[i + 1][1] += dp[i][1] * 2; }
		if (b[i] == 0) { dp[i + 1][0] += dp[i][a[i]]; dp[i + 1][1] += dp[i][a[i]]; }
	}
	if (a1 == a2)dp[48][0] -= 2;
	cout << dp[48][0] << endl;
	return 0;
}