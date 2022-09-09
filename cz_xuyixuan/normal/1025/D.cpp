#include<bits/stdc++.h>
using namespace std;
const int MAXN = 705;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, a[MAXN];
bool mp[MAXN][MAXN];
bool dp[MAXN][MAXN][2];
int gcd(int x, int y) {
	if (x == 0 || y == 0) return x + y;
	else return gcd(y, x % y);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 0; i <= n + 1; i++)
	for (int j = 0; j <= n + 1; j++)
		mp[i][j] = gcd(a[i], a[j]) >= 2;
	for (int i = 0; i <= n; i++)
		dp[i + 1][i][0] = dp[i + 1][i][1] = true;
	for (int len = 1; len <= n; len++) {
		for (int i = 1, j = len; j <= n; i++, j++) {
			for (int k = i; k <= j; k++) {
				dp[i][j][0] |= mp[i - 1][k] && dp[i][k - 1][1] && dp[k + 1][j][0];
				dp[i][j][1] |= mp[j + 1][k] && dp[i][k - 1][1] && dp[k + 1][j][0];
			}
		}
	}
	if (dp[1][n][0]) printf("Yes\n");
	else printf("No\n");
	return 0;
}