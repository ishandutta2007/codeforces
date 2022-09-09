#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
char s[MAXN], ans[MAXN];
int main() {
	int n, k;
	read(n), read(k);
	scanf("\n%s", s + 1);
	int cnt = (n - k) / 2, len = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') ans[++len] = '(';
		else if (cnt) cnt--, len--;
		else ans[++len] = ')';
	}
	ans[len + 1] = 0;
	printf("%s\n", ans + 1);
	return 0;
}