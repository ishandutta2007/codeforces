#include<iostream>
using namespace std;
int dp[205][100005], a[100005], n;
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= 200; i++) {
		for (int j = n; j >= 1; j--) {
			int T = j + a[j] + i;
			if (T > n)dp[i][j] = 1; else dp[i][j] = dp[i][T] + 1;
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int p, q; cin >> p >> q;
		if (q <= 200)cout << dp[q][p] << endl;
		else {
			int cnt = p, ret = 0;
			while (cnt <= n) { cnt += a[cnt] + q; ret++; }
			cout << ret << endl;
		}
	}
	return 0;
}