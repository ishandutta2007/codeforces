#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
int n, s[MAXN], c[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(s[i]);
	for (int i = 1; i <= n; i++)
		read(c[i]);
	int ans = 1e9;
	for (int i = 2; i <= n - 1; i++) {
		int pre = 1e9, suf = 1e9;
		for (int j = 1; j <= i - 1; j++)
			if (s[j] < s[i]) chkmin(pre, c[j]);
		for (int j = i + 1; j <= n; j++)
			if (s[j] > s[i]) chkmin(suf, c[j]);
		chkmin(ans, pre + suf + c[i]);
	}
	if (ans == 1e9) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}