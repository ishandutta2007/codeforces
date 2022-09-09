#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int dp[2][MAXN];
struct HumdrumQueue {
	int l, r, num[MAXN], val[MAXN];
	void init() {
		l = 0;
		r = -1;
	}
	void push(int pos, int v) {
		while (r >= l && v <= val[r]) r--;
		val[++r] = v;
		num[r] = pos;
	}
	void pop(int pos) {
		if (num[l] == pos) l++;
	}
	int get() {
		return val[l];
	}
} HQ, HP;
int main() {
	int n, k; read(n), read(k);
	for (int j = 0; j <= n; j++)
		dp[0][j] = 1e9;
	dp[0][0] = 0;
	int last = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++)
			dp[1][j] = 1e9;
		int ql, qr; read(ql), read(qr);
		for (int j = 0; j <= n; j++) {
			int tmp = j - (ql - last);
			if (tmp >= 0) dp[1][j] = dp[0][tmp];
		}
		for (int j = 0; j <= n; j++)
			dp[0][j] = 1e9;
		HQ.init(); HP.init();
		for (int j = 0; j <= n; j++) {
			HQ.push(j, dp[1][j]);
			HQ.pop(j - (qr - ql) - 1);
			int l = qr - j;
			int tl = l - (qr - ql);
			if (tl >= 0 && tl <= n) HP.push(tl, dp[1][tl]);
			HP.pop(l + 1);
			if (l < 0 || l > n) continue;
			int tmp = j - (qr - ql);
			if (tmp >= 0) dp[0][j] = dp[1][tmp];
			dp[0][j] = min(dp[0][j], HP.get() + 1);
			dp[0][j] = min(dp[0][j], HQ.get() + 2);
		}
		last = qr;
	}
	for (int j = 0; j <= n; j++)
		dp[1][j] = 1e9;
	for (int j = 0; j <= n; j++) {
		int tmp = j - (2 * n - last);
		if (tmp >= 0) dp[1][j] = dp[0][tmp];
	}
	if (dp[1][n] >= 1e9) printf("Hungry\n");
	else printf("Full\n%d\n", dp[1][n]);
	return 0;
}