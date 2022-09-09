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
int a[MAXN], f[MAXN][MAXN], ans[MAXN][MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), f[i][i] = a[i], ans[i][i] = a[i];
	for (int len = 2; len <= n; len++)
	for (int i = 1, j = len; j <= n; i++, j++) {
		f[i][j] = f[i + 1][j] ^ f[i][j - 1];
		ans[i][j] = f[i][j];
		chkmax(ans[i][j], ans[i + 1][j]);
		chkmax(ans[i][j], ans[i][j - 1]);
	}
	int q; read(q);
	while (q--) {
		int l, r;
		read(l), read(r);
		writeln(ans[l][r]);
	}
	return 0;
}