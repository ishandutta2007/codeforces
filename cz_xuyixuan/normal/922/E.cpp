#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
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
long long dp[2][MAXN];
long long w, b, x, cost[MAXN];
int n, m, c[MAXN];
void chkmax(long long &x, long long y) {
	x = max(x, y);
}
int main() {
	read(n), read(w), read(b), read(x);
	for (int i = 1; i <= n; i++)
		read(c[i]), m += c[i];
	for (int i = 1; i <= n; i++)
		read(cost[i]);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = w;
	for (int i = 1; i <= n; i++) {
		int dest = i & 1, last = dest ^ 1;
		memset(dp[dest], -1, sizeof(dp[dest]));
		for (int j = 0; j <= m; j++) {
			if (dp[last][j] == -1) continue;
			for (int k = 0; k <= c[i] && dp[last][j] - k * cost[i] >= 0; k++) {
				long long tj = j + k, tmp = min(dp[last][j] - k * cost[i] + x, w + b * tj);
				chkmax(dp[dest][tj], tmp);
			}
		}
	}
	int ans = 0, now = n & 1;
	for (int i = 0; i <= m; i++)
		if (dp[now][i] != -1) ans = i;
	writeln(ans);
	return 0;
}