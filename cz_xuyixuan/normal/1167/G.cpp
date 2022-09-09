#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 7040;
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
int n, m, d, a[MAXN];
bitset <MAXM> l, r;
int main() {
	read(n), read(d);
	int last = 0, lp = 1, rp = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] < MAXM) {
			r.set(a[i]);
			rp = i + 1;
		}
	} 
	read(m);
	while (m--) {
		int pos; read(pos);
		int delta = pos - last;
		l <<= delta, r >>= delta;
		while (lp <= n && a[lp] + 1 <= pos) {
			if (pos - a[lp] - 1 < MAXM) l.set(pos - a[lp] - 1);
			lp++;
		}
		while (rp <= n && a[rp] - pos < MAXM) {
			if (a[rp] - pos >= 0) r.set(a[rp] - pos);
			rp++;
		}
		double ans = atan2(1, min(l._Find_first(), r._Find_first()));
		chkmax(ans, 2 * atan2(1, (l & r)._Find_first()));
		chkmax(ans, 2 * atan2(1, 1 + ((l >> 1) & r)._Find_first()));
		chkmax(ans, 2 * atan2(1, 1 + (l & (r >> 1))._Find_first()));
		printf("%.10lf\n", ans);
		last = pos;
	}
	return 0;
}