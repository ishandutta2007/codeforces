#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int n, m, q, a[MAXN], nxt[MAXN], last[MAXN];
int Max[MAXN], travel[MAXN][MAXLOG];
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++)
		read(a[i]), nxt[a[i]] = a[i - 1];
	nxt[a[1]] = a[n];
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		travel[i][0] = last[nxt[x]];
		for (int j = 1; j < MAXLOG; j++)
			travel[i][j] = travel[travel[i][j - 1]][j - 1];
		int pos = i;
		for (int j = 0; j < MAXLOG; j++)
			if ((1 << j) & (n - 1)) pos = travel[pos][j];
		Max[i] = max(Max[i - 1], pos);
		last[x] = i;
	}
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		if (Max[y] >= x) putchar('1');
		else putchar('0');
	}
	return 0;
}