#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int CNT = 10;
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
int f[MAXN], g[MAXN];
int sum[MAXN][CNT];
int main() {
	for (int i = 1; i < MAXN; i++) {
		int tmp = i, now = 1;
		while (tmp) {
			if (tmp % 10) now *= tmp % 10;
			tmp /= 10;
		}
		f[i] = now;
		if (i <= 9) g[i] = i;
		else g[i] = g[f[i]];
		for (int j = 1; j < CNT; j++)
			sum[i][j] = sum[i - 1][j];
		sum[i][g[i]]++;
	}
	int q; read(q);
	while (q--) {
		int l, r, k;
		read(l), read(r), read(k);
		writeln(sum[r][k] - sum[l - 1][k]);
	}
	return 0;
}