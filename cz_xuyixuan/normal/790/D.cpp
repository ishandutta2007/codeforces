#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
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
int n, a[MAXN][2], r[MAXN][3], dp[MAXN][3];
long long s[MAXN][3];
map <long long, int> mp[3];
void update(int pos, int val, int zro, int one) {
	if (val > dp[pos][2]) {
		dp[pos][0] = zro;
		dp[pos][1] = one;
		dp[pos][2] = val;
	} if (val == dp[pos][2]) {
		chkmin(dp[pos][0], zro);
		chkmin(dp[pos][1], one);
	}
}
int main() {
	read(n);
	for (int t = 0; t <= 1; t++)
	for (int i = 1; i <= n; i++)
		read(a[i][t]);
	for (int i = n; i >= 1; i--) {
		s[i][0] = s[i + 1][0] + a[i][0];
		s[i][1] = s[i + 1][1] + a[i][1];
		s[i][2] = s[i + 1][2] + a[i][0] + a[i][1];
		for (int j = 0; j <= 2; j++) {
			r[i][j] = mp[j][s[i + 1][j]];
			if (r[i][j] == 0) r[i][j] = r[i + 1][j];
			mp[j][s[i + 1][j]] = i;
		}
	}
	for (int i = 0; i <= 2; i++) {
		r[0][i] = mp[i][s[1][i]];
		if (r[0][i] == 0) r[0][i] = r[1][i];
	}
	for (int i = n; i >= 0; i--)
	for (int j = 0; j <= 2; j++) {
		if (r[i][j] == 0) r[i][j] = n + 1;
		if (i != n) chkmin(r[i][j], r[i + 1][j]);
	}
	for (int i = 0; i <= n; i++)
		dp[i][0] = r[i][0], dp[i][1] = r[i][1];
	for (int i = 0; i <= n - 1; i++) {
		int tmp = dp[i][2];
		update(i + 1, tmp, dp[i][0], dp[i][1]);
		update(dp[i][0], tmp + 1, r[dp[i][0]][0], r[i][1]);
		update(dp[i][1], tmp + 1, r[i][0], r[dp[i][1]][1]);
		update(r[i][0], tmp + 1, r[r[i][0]][0], dp[i][1]);
		update(r[i][1], tmp + 1, dp[i][0], r[r[i][1]][1]);
		if (r[i][0] == dp[i][1]) update(r[i][0], tmp + 2, r[r[i][0]][0], r[r[i][0]][1]);
		if (dp[i][0] == r[i][1]) update(r[i][1], tmp + 2, r[r[i][1]][0], r[r[i][1]][1]);
		update(r[i][2], tmp + 1, r[r[i][2]][0], r[r[i][2]][1]);
	}
	writeln(dp[n][2]);
	return 0;
}