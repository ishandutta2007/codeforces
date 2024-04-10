#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,a[N],sum[N],dp[N][2];

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum[i] = a[i];
		if(i) sum[i] += sum[i-1];
	}
	dp[n-1][0] = dp[n-1][1] = 0;
	for(int i = n-2; i >= 0; --i) {
		dp[i][0] = dp[i+1][1]+sum[i+1];
		dp[i][1] = dp[i+1][0]-sum[i+1];
		if(i != n-2) {
			dp[i][0] = max(dp[i][0],dp[i+1][0]);
			dp[i][1] = min(dp[i][1],dp[i+1][1]);
		}
	}
	cout << dp[0][0] << "\n";

}