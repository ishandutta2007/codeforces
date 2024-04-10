#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
int n, m, Max, type, val[MAXN], len[MAXN], home[MAXN];
int a[MAXN][MAXN], b[MAXN], dp[MAXN][MAXN];
char s[MAXN];
bool cmp(int x, int y) {
	if (a[x][type] == a[y][type]) return home[x] < home[y];
	else return a[x][type] > a[y][type];
}
int main() {
	scanf("%s", s + 1), read(n);
	m = strlen(s + 1);
	reverse(s + 1, s + m + 1);
	for (int i = 1; i <= m; i++)
		if (s[i] == '?') b[i] = -1;
		else b[i] = s[i] - '0';
	int Max = m;
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		len[i] = strlen(s + 1);
		reverse(s + 1, s + len[i] + 1);
		for (int j = 1; j <= len[i]; j++)
			a[i][j] = s[j] - '0';
		chkmax(len[i], m);
		chkmax(Max, len[i]);
	}
	Max++;
	for (int i = 0; i <= 9; i++)
		read(val[i]);
	for (int i = 0; i <= Max; i++)
	for (int j = 0; j <= n; j++)
		dp[i][j] = -INF;
	dp[0][0] = 0;
	static int now[MAXN];
	for (int i = 1; i <= n; i++)
		now[i] = i;
	for (int i = 1; i <= Max; i++) {
		int from, to;
		if (b[i] == -1) {
			if (i == m) from = 1, to = 9;
			else from = 0, to = 9;
		} else from = to = b[i];
		for (int ch = from; ch <= to; ch++) {
			int sum = 0, cnt = 0;
			for (int j = 1; j <= n; j++)
				if (i <= len[j]) {
					sum += val[(a[j][i] + ch) % 10];
					if (a[j][i] + ch >= 10) cnt++;
				}
			chkmax(dp[i][cnt], dp[i - 1][0] + sum);
			for (int j = 1; j <= n; j++) {
				if (i <= len[now[j]]) {
					sum -= val[(a[now[j]][i] + ch) % 10];
					if (a[now[j]][i] + ch >= 10) cnt--;
				}
				sum += val[(a[now[j]][i] + ch + 1) % 10];
				if (a[now[j]][i] + ch + 1 >= 10) cnt++;
				chkmax(dp[i][cnt], dp[i - 1][j] + sum);
			}
		}
		for (int j = 1; j <= n; j++)
			home[now[j]] = j;
		type = i;
		sort(now + 1, now + n + 1, cmp);
	}
	writeln(dp[Max][0]);
	return 0;
}