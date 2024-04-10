#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
int n, m;
char s[MAXN][MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	int ansx = 1, ansy = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		if (s[i][j] == '#') continue;
		int now = 0, cnt = 1;
		for (int k = i + 1; k <= n && k - i + 1 <= m; k++)
			if (s[k][j] == '.') cnt++;
			else break;
		for (int k = i - 1; k >= 1 && i - k + 1 <= m; k--)
			if (s[k][j] == '.') cnt++;
			else break;
		if (cnt >= m) now += cnt - m + 1;
		cnt = 1;
		for (int k = j + 1; k <= n && k - j + 1 <= m; k++)
			if (s[i][k] == '.') cnt++;
			else break;
		for (int k = j - 1; k >= 1 && j - k + 1 <= m; k--)
			if (s[i][k] == '.') cnt++;
			else break;
		if (cnt >= m) now += cnt - m + 1;
		if (now > ans) {
			ans = now;
			ansx = i;
			ansy = j;
		}
	}
	printf("%d %d\n", ansx, ansy);
	return 0;
}