#include <bits/stdc++.h>
using namespace std;

int n, k, p;

const int inf = -1e8;

int a[510000];
int dp[110][110], b[110];

int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] %= p, a[i] = (a[i-1] + a[i]) % p;
	for (int x = 0; x < p; x++) for (int j = 0; j <= k; j++) dp[x][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) b[j] = inf;
		for (int j = 1; j <= k; j++) {
			for (int x = 0; x <= a[i]; x++) b[j] = max(b[j], dp[x][j-1] + a[i] - x);
			for (int x = a[i]+1; x < p; x++) b[j] = max(b[j], dp[x][j-1] + a[i] + p - x);
		}
		for (int j = 1; j <= k; j++) dp[a[i]][j] = max(dp[a[i]][j], b[j]);
	}
	cout << dp[a[n]][k] << endl;
	return 0;
}