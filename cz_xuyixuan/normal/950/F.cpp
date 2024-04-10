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
int n, m, d, b;
int x[MAXN], y[MAXN];
bool check(int mid) {
	for (int i = 1; i <= n; i++)
		x[i] = y[i];
	int pos = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		r += 1 + d;
		chkmin(r, n);
		if (i < mid + 1) continue;
		int req = b;
		while (req) {
			if (x[pos]) {
				int used = min(req, x[pos]);
				req -= used;
				x[pos] -= used;
			} else pos++;
		}
		if (pos > r) return false;
	}
	int l = n + 1; pos = n;
	for (int i = n; i >= m + 1; i--) {
		l -= 1 + d;
		chkmax(l, 1);
		if (i > n - mid) continue;
		int req = b;
		while (req) {
			if (x[pos]) {
				int used = min(req, x[pos]);
				req -= used;
				x[pos] -= used;
			} else pos--;
		}
		if (pos < l) return false;
	}
	return true;
}
int main() {
	read(n), read(d), read(b);
	for (int i = 1; i <= n; i++)
		read(y[i]);
	m = (n + 1) / 2;
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	writeln(l);
	return 0;
}