#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int P = 1e9 + 7;
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
char s[MAXN]; int x[MAXN], y[MAXN];
int n, m, dp[MAXN][MAXN], sum[MAXN][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n), read(m);
	scanf("\n%s", s + 1);
	for (int i = 1; i <= n; i++) {
		x[i] = 'z' - s[i];
		y[i] = s[i] - 'a';
	}
	int ans = 0; dp[0][0] = sum[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= m; j++) {
		dp[i][j] = 1ll * y[i] * sum[i - 1][j] % P;
		int delta = n - i + 1, cur = j - delta;
		for (int k = i - 1; k >= 0 && cur >= 0; k--, cur -= delta)
			update(dp[i][j], 1ll * dp[k][cur] * x[i] % P);
		sum[i][j] = (sum[i - 1][j] + dp[i][j]) % P;
	}
	for (int i = 1; i <= n; i++)
		update(ans, dp[i][m]);
	update(ans, m == 0);
	cout << ans << endl;
	return 0;
}