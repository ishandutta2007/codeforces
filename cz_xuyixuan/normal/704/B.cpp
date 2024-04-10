#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const long long INF = 1e18;
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
int n, s, t; ll dp[MAXN][MAXN];
int x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int main() {
	read(n), read(s), read(t);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i <= n; i++)
		read(c[i]);
	for (int i = 1; i <= n; i++)
		read(d[i]);
	if (s > t) {
		s = n - s + 1;
		t = n - t + 1;
		for (int i = 1; i <= n; i++)
			x[i] = x[n] - x[i];
		reverse(x + 1, x + n + 1);
		reverse(a + 1, a + n + 1);
		reverse(b + 1, b + n + 1);
		reverse(c + 1, c + n + 1);
		reverse(d + 1, d + n + 1);
		swap(a, b), swap(c, d);
	}
	for (int i = 1; i <= n; i++) {
		a[i] += x[i];
		b[i] -= x[i];
		c[i] += x[i];
		d[i] -= x[i];
	}
	for (int i = 1; i <= n + 1; i++)
	for (int j = 0; j <= n; j++)
		dp[i][j] = INF;
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == s) {
			for (int j = 1 - (i == 1); j <= n; j++) {
				chkmin(dp[i + 1][j + 1], dp[i][j] + d[i]);
				if (j != 0) chkmin(dp[i + 1][j], dp[i][j] + c[i]);
			}
		} else if (i == t) {
			for (int j = 1 - (i == 1); j <= n; j++) {
				chkmin(dp[i + 1][j], dp[i][j] + b[i]);
				if (j != 0) chkmin(dp[i + 1][j - 1], dp[i][j] + a[i]);
			}
		} else {
			for (int j = 1 - (i == 1); j <= n; j++) {
				chkmin(dp[i + 1][j + 1], dp[i][j] + b[i] + d[i]);
				if (j != 0) {
					chkmin(dp[i + 1][j], dp[i][j] + a[i] + d[i]);
					chkmin(dp[i + 1][j - 1], dp[i][j] + a[i] + c[i]);
					if (j != 1 || i < s || i > t) chkmin(dp[i + 1][j], dp[i][j] + b[i] + c[i]);
				}
			}
		}
	}
	cout << dp[n + 1][0] << endl;
	return 0;
}