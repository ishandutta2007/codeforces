#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int n, k, dp[MAXN][MAXN];
char s[MAXN][MAXN], ans[MAXN * 2];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	memset(dp, -1, sizeof(dp));
	if (s[1][1] == 'a' || k >= 1) {
		ans[1] = 'a';
		dp[1][1] = k - (s[1][1] != 'a');
	} else {
		ans[1] = s[1][1];
		dp[1][1] = 0;
	}
	for (int i = 2, now = 0, dest = 1; i <= 2 * n - 1; i++, swap(now, dest)) {
		char opt = 'z';
		for (int x = 1; x <= n; x++) {
			int y = i - x;
			if (y < 0 || y > n || dp[x][y] == -1) continue;
			if (dp[x][y]) opt = 'a';
			if (x + 1 <= n) chkmin(opt, s[x + 1][y]);

			if (y + 1 <= n) chkmin(opt, s[x][y + 1]);
		}
		ans[i] = opt;
		for (int x = 1; x <= n; x++) {
			int y = i - x;
			if (y < 0 || y > n || dp[x][y] == -1) continue;
			if (dp[x][y]) {
				if (x + 1 <= n) chkmax(dp[x + 1][y], dp[x][y] - (s[x + 1][y] != 'a'));
				if (y + 1 <= n) chkmax(dp[x][y + 1], dp[x][y] - (s[x][y + 1] != 'a'));
			} else {
				if (x + 1 <= n && s[x + 1][y] == opt) chkmax(dp[x + 1][y], dp[x][y]);
				if (y + 1 <= n && s[x][y + 1] == opt) chkmax(dp[x][y + 1], dp[x][y]);
			}
		}
	}
	printf("%s\n", ans + 1);
	return 0;
}