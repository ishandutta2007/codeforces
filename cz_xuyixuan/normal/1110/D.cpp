#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int cnt[MAXN], ans[MAXN];
int dp[MAXN][3][3];
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		cnt[x]++;
	}
	memset(dp, -1, sizeof(dp));
	dp[1][0][0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= 2; j++)
		for (int k = 0; k <= 2; k++) {
			if (dp[i][j][k] == -1) continue;
			int tmp = dp[i][j][k];
			if (j + k > cnt[i]) continue;
			for (int l = 0; l <= 2 && j + k + l <= cnt[i]; l++)
				chkmax(dp[i + 1][k][l], tmp + l + (cnt[i] - j - k - l) / 3);
		}
	}
	writeln(dp[m + 1][0][0]);
	return 0;
}