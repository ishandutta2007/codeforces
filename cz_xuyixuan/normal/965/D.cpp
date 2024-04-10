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
int n, m, l, r, a[MAXN];
bool check(int mid) {
	static int b[MAXN], c[MAXN];
	int pos;
	for (int i = 1; i <= n; i++)
		c[i] = a[i];
	memset(b, 0, sizeof(b));
	b[pos = 0] = mid;
	for (int i = 1; i <= n; i++) {
		if (i - pos > m) return false;
		while (c[i] != 0 && pos != i) {
			int tmp = min(c[i], b[pos]);
			b[pos] -= tmp;
			b[i] += tmp; c[i] -= tmp;
			while (b[pos] == 0) pos++;
		}
	}
	return true;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++)
		read(a[i]), r += a[i];
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	writeln(l);
	return 0;
}