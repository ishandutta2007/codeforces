#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int dp[5500], n, a[5500], c[5500], d[5500], e, g[5500];
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i], c[a[i]]++;
	for (int i = 0; i < 5500; i++) { if (c[i] >= 1)e++; }
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1]; for (int j = 0; j < 5500; j++)d[j] = 0, g[j] = 0;
		int f = 0, R = a[i]; g[a[i]] = 1;
		for (int j = i - 1; j >= 0; j--) {
			d[a[j + 1]]++; if (d[a[j + 1]] == c[a[j + 1]])f--; if (d[a[j + 1]] == 1)f++;
			if (f == 0)dp[i] = max(dp[i], dp[j] + R);
			if (g[a[j]] == 0)R ^= a[j], g[a[j]] = 1;
		}
	}
	cout << dp[n] << endl;
	return 0;
}