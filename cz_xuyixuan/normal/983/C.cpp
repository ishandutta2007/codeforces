#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MAXM = 1005;
const int MAXF = 10;
const int MAXQ = 2e7 + 5;
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
int tot, x[MAXN], y[MAXN];
int num[MAXF][MAXF][MAXF][MAXF];
int home[MAXM][5];
int dp[MAXN][MAXM][MAXF];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]), read(y[i]);
	for (int i = 0; i <= 9; i++)
	for (int j = i; j <= 9; j++)
	for (int k = j; k <= 9; k++)
	for (int l = k; l <= 9; l++) {
		num[i][j][k][l] = ++tot;
		home[tot][1] = i;
		home[tot][2] = j;
		home[tot][3] = k;
		home[tot][4] = l;
	}
	for (int i = 0; i <= n; i++)
	for (int j = 1; j <= tot; j++)
	for (int k = 1; k <= 9; k++)
		dp[i][j][k] = 1e9;
	dp[0][1][1] = 0;
	static int q[MAXQ];
	int l = 0, r = 0;
	q[0] = 1 + 10 * 1 + 10000 * 0;
	while (l <= r) {
		int tmp = q[l++];
		int si = tmp / 10000;
		int sj = tmp / 10 % 1000;
		int sk = tmp % 10;
		int now[5], val = dp[si][sj][sk];
		if (si == n && sj == 1) {
			printf("%d\n", val);
			return 0;
		}
		for (int i = 1; i <= 4; i++)
			now[i] = home[sj][i];
		for (int i = 1; i <= 4; i++) {
			if (now[i] == sk) {
				now[i] = 0;
				sort(now + 1, now + 5);
				int ti = si;
				int tj = num[now[1]][now[2]][now[3]][now[4]];
				int tk = sk;
				if (dp[ti][tj][tk] == 1e9) {
					dp[ti][tj][tk] = val + 1;
					q[++r] = ti * 10000 + tj * 10 + tk;
				}
				for (int j = 1; j <= 4; j++)
					now[j] = home[sj][j];
			}
		}
		if (si < n && now[1] == 0 && x[si + 1] == sk) {
			now[1] = y[si + 1];
			sort(now + 1, now + 5);
			int ti = si + 1;
			int tj = num[now[1]][now[2]][now[3]][now[4]];
			int tk = sk;
			if (dp[ti][tj][tk] == 1e9) {
				dp[ti][tj][tk] = val + 1;
				q[++r] = ti * 10000 + tj * 10 + tk;
			}
		}
		if (sk > 1) {
			int ti = si;
			int tj = sj;
			int tk = sk - 1;
			if (dp[ti][tj][tk] == 1e9) {
				dp[ti][tj][tk] = val + 1;
				q[++r] = ti * 10000 + tj * 10 + tk;
			}
		}
		if (sk < 9) {
			int ti = si;
			int tj = sj;
			int tk = sk + 1;
			if (dp[ti][tj][tk] == 1e9) {
				dp[ti][tj][tk] = val + 1;
				q[++r] = ti * 10000 + tj * 10 + tk;
			}
		}
	}
	return 0;
}