#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
using namespace std;
const int maxn = 503;
int go[maxn][2], dp[maxn][maxn][maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	string A, B;
	cin >> n >> m;
	cin >> A >> B;
	A = ' ' + A + ' '; B = ' ' + B + ' ';
	string_view a(A), b(B);
	for (int i = 0; i <= m; ++i) {
		int x = b[i + 1] - '0';
		for (int c = 0; c <= 1; ++c) {
			if (c == x)
				go[i][c] = i + 1;
			else {
				for (int j = i - 1; j >= 0; --j) {
					if (b.substr(1, j) == b.substr(i - j + 1, j) && b[j + 1] == c + '0') {
						go[i][c] = j + 1;
						break;
					}
				}
			}
		}
	}
	//for (int i = 0; i <= m; ++i) printf("%d %d\n", go[i][0], go[i][1]);

	//dp[i][j][k]: ijk
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= n - m + 1; ++k) {
				for (int c = 0; c <= 1; ++c) {
					int x = go[j][c];
					int k2 = k + (x == m);
					dp[i + 1][x][k2] = min(dp[i + 1][x][k2], dp[i][j][k] + (a[i + 1] != '0' + c));
				}
			}
		}
	}
	for (int k = 0; k <= n - m + 1; ++k) {
		int ans = maxn;
		for (int j = 0; j <= m; ++j)
			ans = min(ans, dp[n][j][k]);
		if (ans >= maxn)
			ans = -1;
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}