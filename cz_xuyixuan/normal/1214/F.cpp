#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, m, va[MAXN], vb[MAXN]; ll s[MAXN];
pair <int, int> a[MAXN], b[MAXN];
void add(int l, int r, ll x) {
	if (l < 0 && r < 0) {
		l += n;
		r += n;
	}
	if (l < 0) s[l + n] += x, l = 0;
	s[l] += x, s[r + 1] -= x;
}
int main() {
	read(m), read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].first), a[i].second = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		read(b[i].first), b[i].second = i;
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		va[i] = a[i].first;
		vb[i] = b[i].first;
	}
	for (int i = 1; i <= n; i++) {
		int x = b[i].first;
		if (x - 1 <= m - (x - 1)) {
			int l = 1, r = x;
			int ql = lower_bound(va + 1, va + n + 1, l) - va;
			int qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, x);
		} else {
			int l = x - m / 2, r = x;
			int ql = lower_bound(va + 1, va + n + 1, l) - va;
			int qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, x);
			r = l - 1, l = 1;
			ql = lower_bound(va + 1, va + n + 1, l) - va;
			qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, m - x);
		}
		if (m - x <= m - (m - x)) {
			int l = x + 1, r = m;
			int ql = lower_bound(va + 1, va + n + 1, l) - va;
			int qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, -x);
		} else {
			int l = x + 1, r = x + m / 2;
			int ql = lower_bound(va + 1, va + n + 1, l) - va;
			int qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, -x);
			l = r + 1, r = m;
			ql = lower_bound(va + 1, va + n + 1, l) - va;
			qr = upper_bound(va + 1, va + n + 1, r) - va - 1;
			add(i - qr, i - ql, m + x);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int x = a[i].first;
		if (x - 1 <= m - (x - 1)) {
			int l = 1, r = x - 1;
			int ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			int qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, x);
		} else {
			int l = x - m / 2, r = x - 1;
			int ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			int qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, x);
			r = l - 1, l = 1;
			ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, -x);
		}
		if (m - x <= m - (m - x)) {
			int l = x, r = m;
			int ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			int qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, -x);
		} else {
			int l = x, r = x + m / 2;
			int ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			int qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, -x);
			l = r + 1, r = m;
			ql = lower_bound(vb + 1, vb + n + 1, l) - vb;
			qr = upper_bound(vb + 1, vb + n + 1, r) - vb - 1;
			add(ql - i, qr - i, x);
		}
	}
	ll ans = 1e18; int pos = 0;
	for (int i = 0; i <= n - 1; i++) {
		if (i != 0) s[i] += s[i - 1];
		if (s[i] < ans) {
			ans = s[i];
			pos = i;
		}
	}
	writeln(ans);
	static int res[MAXN];
	for (int i = 1; i <= n; i++)
		if (i + pos <= n) res[a[i].second] = b[i + pos].second;
		else res[a[i].second] = b[i + pos - n].second;
	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	return 0;
}