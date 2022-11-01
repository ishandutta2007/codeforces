#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 300005, M = 1000005;

int n, m, cnt[M], a[N];

void sieve(int l) {
	for (int i = 1; i <= l; i++)
		for (int j = i; j <= l; j += i) cnt[j]++;
}

struct SegmentTree {
	ll t[N << 2];
	int mx[N << 2];
	
	void build(int rt, int l, int r) {
		if (l == r) {
			t[rt] = mx[rt] = a[l];
			// printf("BUILD: %d %d %d\n", l, a[l], t[rt]);
			return;
		}
		int mid = (l + r) >> 1;
		build(rt << 1, l, mid);
		build(rt << 1 | 1, mid + 1, r);
		t[rt] = t[rt << 1] + t[rt << 1 | 1], mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	}
	void modify(int rt, int l, int r, int ql, int qr) {
		if (mx[rt] <= 2) return;
		if (l == r) {
			a[l] = cnt[a[l]];
			t[rt] = mx[rt] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) modify(rt << 1, l, mid, ql, qr);
		if (qr > mid) modify(rt << 1 | 1, mid + 1, r, ql, qr);
		t[rt] = t[rt << 1] + t[rt << 1 | 1], mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	}
	ll ask(int rt, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return t[rt];
		int mid = (l + r) >> 1; ll ret = 0;
		if (ql <= mid) ret += ask(rt << 1, l, mid, ql, qr);
		if (qr > mid) ret += ask(rt << 1 | 1, mid + 1, r, ql, qr);
		return ret;
	}
} st;

int main() {
	sieve(1e6);
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	st.build(1, 1, n); 
	while (m--) {
		int opt = read(), l = read(), r = read();
		if (opt == 1) st.modify(1, 1, n, l, r);
		else printf("%lld\n", st.ask(1, 1, n, l, r));
	}
	return 0;
}