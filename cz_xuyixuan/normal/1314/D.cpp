#include<bits/stdc++.h>
using namespace std;
const int MAXN = 85;
const int MAXK = 12;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, k, a[MAXN][MAXN];
bool side[MAXN]; int dp[MAXK][MAXN];
int main() {
	srand('X' + 'Y' + 'X');
	read(n), read(k);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		read(a[i][j]);
	int ans = INT_MAX;
	while (clock() <= 2.0 * CLOCKS_PER_SEC) {
		for (int i = 0; i <= k; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = INT_MAX;
		dp[0][1] = 0;
		for (int i = 1; i <= n; i++)
			side[i] = rand() % 2 == 0;
		for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) {
			int tmp = dp[i - 1][j];
			if (tmp < INT_MAX) {
				for (int l = 1; l <= n; l++)
					if (side[l] ^ side[j]) chkmin(dp[i][l], dp[i - 1][j] + a[j][l]);
			}
		}
		chkmin(ans, dp[k][1]);
	}
	cout << ans << endl;
	return 0;
}