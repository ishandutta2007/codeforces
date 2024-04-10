#include<iostream>
#include<algorithm>
using namespace std;
int n, a[200000], dp[200000];
int main() {
	cin >> n; a[0] = -999999999;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int pos1 = lower_bound(a, a + i + 1, a[i] - 89) - a; pos1--;
		int pos2 = lower_bound(a, a + i + 1, a[i] - 1439) - a; pos2--;
		dp[i] = min(dp[i - 1] + 20, min(dp[pos1] + 50, dp[pos2] + 120));
		cout << dp[i] - dp[i - 1] << endl;
	}
	return 0;
}