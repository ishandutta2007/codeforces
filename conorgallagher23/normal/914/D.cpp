#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 500005;

int n, a[N], ans;

inline int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);
}

struct SegmentTree {
	int t[N << 2];
		
	void build(int rt, int l, int r) {
		if (l == r) { t[rt] = a[l]; return; }
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		t[rt] = gcd(t[rt << 1], t[rt << 1 | 1]);
	}
	void modify(int rt, int l, int r, int x, int y) {
		if (l == r) { t[rt] = y; return; }
		int mid = (l + r) >> 1;
		if (x <= mid) modify(rt << 1, l, mid, x, y);
		else modify(rt << 1 | 1, mid + 1, r, x, y);
		t[rt] = gcd(t[rt << 1], t[rt << 1 | 1]);
	}
	void ask(int rt, int l, int r, int ql, int qr, int x) {
		// printf("!!! %d %d %d %d %d %d %d\n", rt, l, r, ql, qr, x, ans);
		if (l == r) {
			// printf("%d %d", l, t[rt]);
			if (t[rt] % x != 0) ans++;
		}
		if (ans > 1) return;
		if (l != r) {
			int mid = (l + r) >> 1;
			if (ql <= mid && t[rt << 1] % x != 0) ask(rt << 1, l, mid, ql, qr, x);
			if (qr > mid && t[rt << 1 | 1] % x != 0) ask(rt << 1 | 1, mid + 1, r, ql, qr, x);
		}
	}
	
} st;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	st.build(1, 1, n);
	int T = read();
	while (T--) {
		int opt = read();
		if (opt == 1) {
			int l = read(), r = read(), x = read();
			ans = 0; st.ask(1, 1, n, l, r, x);
			if (ans > 1) printf("NO\n");
			else printf("YES\n");
		} else {
			int x = read(), y = read();
			st.modify(1, 1, n, x, y);
		}
	}		
	return 0;
}