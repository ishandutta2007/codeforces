#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int INF  = 1e9 + 7;
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
int n, m, l[MAXN], s[MAXN], c[MAXN], dp[MAXN][MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(l[i]);
	for (int i = 1; i <= n; i++)
		read(s[i]);
	reverse(l + 1, l + n + 1);
	reverse(s + 1, s + n + 1);
	for (int i = 1; i <= n + m; i++)
		read(c[i]);
	for (int i = 1; i <= n + m; i++)
	for (int j = 1; j <= n; j++)
		dp[i][j] = -INF;
	for (int i = 1; i <= n; i++) {
		int cur = l[i];
		for (int j = n; j >= 0; j--) {
			if (dp[cur][j] == -INF) continue;
			int tmp = dp[cur][j] - s[i] + c[cur];
			for (int k = cur + 1, t = j; t & 1; k++, t >>= 1)
				tmp += c[k];
			for (int k = cur, t = j + 1; t != 0; k++, t >>= 1)
				chkmax(dp[k][t], tmp);
		}
		for (int j = 1; j <= n + m; j++) {
			chkmax(dp[j][0], dp[j - 1][0]);
			chkmax(dp[j][0], dp[j - 1][1]);
		}
	}
	int ans = -INF;
	for (int i = 1; i <= n + m; i++)
	for (int j = 0; j <= n; j++)
		chkmax(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}