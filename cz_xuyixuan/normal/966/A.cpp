#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int func(int dist, int v) {
	return dist / v + (dist % v != 0);
}
int a[MAXN], b[MAXN];
int main() {
	int r, n, m, v;
	read(r), read(r), read(n), read(m), read(v);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		int sx, sy, tx, ty;
		read(sx), read(sy);
		read(tx), read(ty);
		if (sx == tx) {
			writeln(abs(sy - ty));
			continue;
		}
		int tmp = lower_bound(a + 1, a + n + 1, sy) - a;
		int tnp = tmp - 1;
		int ans = 2e9;
		if (tmp <= n) chkmin(ans, abs(a[tmp] - sy) + abs(a[tmp] - ty) + abs(sx - tx));
		if (tnp >= 1) chkmin(ans, abs(a[tnp] - sy) + abs(a[tnp] - ty) + abs(sx - tx));
		tmp = lower_bound(b + 1, b + m + 1, sy) - b;
		tnp = tmp - 1;
		if (tmp <= m) chkmin(ans, abs(b[tmp] - sy) + abs(b[tmp] - ty) + func(abs(sx - tx), v));
		if (tnp >= 1) chkmin(ans, abs(b[tnp] - sy) + abs(b[tnp] - ty) + func(abs(sx - tx), v));
		writeln(ans);
	}
	return 0;
}