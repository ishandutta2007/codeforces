#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 10;
const long long INF = 1e18;
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
long long dp[MAXM][MAXN], a[MAXN];
long long times(long long a, long long b) {
	if ((long double) a * b >= INF) return INF;
	else return a * b;
}
int main() {
	for (int i = 1; i <= 5; i++)
	for (int j = 1; j <= 10000; j++) {
		long long ans = -1, pos = j;
		for (int k = 0; k <= j; k++) {
			ans += dp[i - 1][pos] + 1;
			chkmin(ans, INF);
			pos += dp[i - 1][pos] + 1;
			if (pos >= 10000) {
				ans += times(dp[i - 1][10000] + 1, j - k);
				chkmin(ans, INF);
				break;
			}
		}
		dp[i][j] = ans;
	}
	int cnt = 5; long long pos = 1;
	while (true) {
		int tmp = min(pos, 10000ll), tnp = tmp;
		cout << tmp; a[0] = pos - 1;
		for (int i = 1; i <= tmp; i++) {
			pos += dp[cnt - 1][tnp];
			tnp = min(tnp + dp[cnt - 1][tnp] + 1, 10000ll);
			a[i] = pos; pos++;
			cout << ' ' << a[i];
		}
		cout << endl;
		read(tnp);
		if (tnp == -1) return 0;
		cnt--; pos = a[tnp] + 1;
	}
	return 0;
}