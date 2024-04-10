#include <bits/stdc++.h>

const int MAXN = 400010;
const int INF = 0x3f3f3f3f;
typedef long long LL;

struct info {
	int fir, sec, cnt;
	info() { fir = sec = INF; }
} pos[MAXN], neg[MAXN];
info operator + (info a, info b) {
	info res;
	res.fir = std::max(a.fir, b.fir);
	res.cnt = (-(a.fir == res.fir) & a.cnt) + (-(b.fir == res.fir) & b.cnt);
	res.sec = std::max(a.sec, b.sec);
	if (a.fir < res.fir) res.sec = std::max(res.sec, a.fir);
	if (b.fir < res.fir) res.sec = std::max(res.sec, b.fir);
	return res;
}
LL sum[MAXN];
void mkadd(int u, info * tr, int v) {
	if (v < tr[u].fir) {
		sum[u] -= (LL) tr[u].cnt * (tr[u].fir - v);
		tr[u].fir = v;
	}
}
void mkpush(int u, info * tr) {
	mkadd(u << 1, tr, tr[u].fir);
	mkadd(u << 1 | 1, tr, tr[u].fir);
}
void pushdown(int u) {
	mkpush(u, pos), mkpush(u, neg);
}
void update(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	pos[u] = pos[u << 1] + pos[u << 1 | 1];
	neg[u] = neg[u << 1] + neg[u << 1 | 1];
}
void _mdf(int u, int l, int r, int v) {
	if (l == r) {
		if (v > 0)
			pos[u].fir = std::min(pos[u].fir, v), pos[u].sec = 0;
		else
			neg[u].fir = std::min(neg[u].fir, -v), neg[u].sec = 0;
		if (pos[u].fir != INF && neg[u].fir != INF) {
			sum[u] = pos[u].fir + neg[u].fir;
			pos[u].cnt = neg[u].cnt = 1;
		} else sum[u] = pos[u].cnt = neg[u].cnt = 0;
		return ;
	}
	if (v > 0 && v > pos[u].sec) return mkadd(u, pos, v);
	if (v < 0 && -v > neg[u].sec) return mkadd(u, neg, -v);
	int mid = l + r >> 1;
	pushdown(u);
	_mdf(u << 1, l, mid, v);
	_mdf(u << 1 | 1, mid + 1, r, v);
	update(u);
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return _mdf(u, l, r, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	update(u);
}
LL qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sum[u];
	int mid = l + r >> 1; LL res = 0;
	pushdown(u);
	if (L <= mid) res += qry(u << 1, l, mid, L, R);
	if (mid < R) res += qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
const int RAN = 100000;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q; std::cin >> Q;
	while (Q --> 0) {
		int opt, l, r, K;
		std::cin >> opt >> l >> r;
		if (opt == 1)
			std::cin >> K, mdf(1, 1, RAN, l, r - 1, K);
		else
			std::cout << qry(1, 1, RAN, l, r - 1) << '\n';
	}
	return 0;
}