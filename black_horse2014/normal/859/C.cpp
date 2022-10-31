#include <bits/stdc++.h>
using namespace std;

int s[55], a[55], dp[55];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = n; i > 0; i--) s[i] = s[i+1] + a[i], dp[i] = max(dp[i+1], a[i] + s[i+1] - dp[i+1]);
	cout << s[1] - dp[1] << ' ' << dp[1] << endl;
	return 0;
}