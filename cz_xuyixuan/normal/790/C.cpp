#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = 1e9;
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
char s[MAXN];
int n, a[MAXN], cnt[3], pos[3][MAXN];
int dp[MAXN][MAXN][MAXN][2];
int cost(int type, int zero, int one, int two, int to, int from) {
	int ans = abs(from - to);
	if (to <= from) {
		for (int i = 1; i <= zero; i++)
			if (pos[0][i] > from) ans += 2;
		for (int i = 1; i <= one; i++)
			if (pos[1][i] > from) ans += 2;
		for (int i = 1; i <= two; i++)
			if (pos[2][i] > from) ans += 2;
	} else {
		if (type == 0) zero++;
		else if (type == 1) one++;
		else two++;
		for (int i = zero + 1; i <= cnt[0]; i++)
			if (pos[0][i] < from) ans += 2;
		for (int i = one + 1; i <= cnt[1]; i++)
			if (pos[1][i] < from) ans += 2;
		for (int i = two + 1; i <= cnt[2]; i++)
			if (pos[2][i] < from) ans += 2;
	}
	return ans;
}
int main() {
	read(n);
	scanf("\n%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'V') a[i] = 0, pos[0][++cnt[0]] = i;
		else if (s[i] == 'K') a[i] = 1, pos[1][++cnt[1]] = i;
		else a[i] = 2, pos[2][++cnt[2]] = i;
	}
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++)
	for (int k = 0; k <= n; k++)
		dp[i][j][k][0] = dp[i][j][k][1] = INF;
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= n - 1; i++)
	for (int j = 0; j <= cnt[0] && j <= i; j++)
	for (int k = 0; k <= cnt[1] && j + k <= i; k++) {
		int l = i - j - k, tmp;
		tmp = dp[i][j][k][0];
		if (j != cnt[0]) chkmin(dp[i + 1][j + 1][k][1], tmp + cost(0, j, k, l, i + 1, pos[0][j + 1]));
		if (k != cnt[1]) chkmin(dp[i + 1][j][k + 1][0], tmp + cost(1, j, k, l, i + 1, pos[1][k + 1]));
		if (l != cnt[2]) chkmin(dp[i + 1][j][k][0], tmp + cost(2, j, k, l, i + 1, pos[2][l + 1]));
		tmp = dp[i][j][k][1];
		if (j != cnt[0]) chkmin(dp[i + 1][j + 1][k][1], tmp + cost(0, j, k, l, i + 1, pos[0][j + 1]));
		if (l != cnt[2]) chkmin(dp[i + 1][j][k][0], tmp + cost(2, j, k, l, i + 1, pos[2][l + 1]));
	}
	writeln(min(dp[n][cnt[0]][cnt[1]][0], dp[n][cnt[0]][cnt[1]][1]) / 2);
	return 0;
}