#include <bits/stdc++.h>
using namespace std;

const int N = 110;

long long f[N][N], dp[N][N][N][2];
int a[N];

inline void chkmax(long long &a, long long b) {
	if (b > a) a = b;
}

int main() {
	int n; string s; cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	const long long inf = 1LL<<60;
	for (int i = 0; i < n; i++) {
		dp[i][i][1][0] = dp[i][i][1][1] = -inf;
		dp[i][i][1][s[i]-'0'] = 0;
		f[i][i] = a[1];
		dp[i][i][0][0] = dp[i][i][0][1] = a[1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n-i; j++) {
			int k = j+i-1;
			f[j][k] = -inf;
			for (int l = 1; l <= i; l++) {
				dp[j][k][l][0] = dp[j][k][l][1] = -inf;
				chkmax(dp[j][k][l][s[j]-'0'], dp[j+1][k][l-1][s[j]-'0']);
				for (int mid = j; mid <= k-l; mid++) {
					chkmax(dp[j][k][l][0], dp[mid+1][k][l][0] + f[j][mid]);
					chkmax(dp[j][k][l][1], dp[mid+1][k][l][1] + f[j][mid]);
				}
				chkmax(f[j][k], dp[j][k][l][0] + a[l]);
				chkmax(f[j][k], dp[j][k][l][1] + a[l]);
			}
			dp[j][k][0][0] = dp[j][k][0][1] = f[j][k];
		}
	}
	cout << f[0][n-1] << endl;
	return 0;
}