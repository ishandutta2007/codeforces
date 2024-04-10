#include <bits/stdc++.h>

const int MAXN = 120010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
const int MAXP = MAXN << 2;
struct mier {
	int v, c;
	friend mier operator + (mier a, mier b) {
		if (a.v == b.v) a.c += b.c;
		return a.v <= b.v ? a : b;
	}
} val[MAXP];
int taga[MAXP], tags[MAXP]; LL sum[MAXP];
void mkadd(int u, int v) { taga[u] += v, val[u].v += v; }
void mksav(int u, int v) { tags[u] += v, sum[u] += (LL) val[u].c * v; }
void pushdown(int u) {
	if (int & t = taga[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
	if (int & t = tags[u]) {
		if (val[u << 1].v == val[u].v) mksav(u << 1, t);
		if (val[u << 1 | 1].v == val[u].v) mksav(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1; pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	val[u] = val[u << 1] + val[u << 1 | 1];
}
LL qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sum[u];
	int mid = l + r >> 1; pushdown(u);
	LL res = 0;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res += qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void build(int u, int l, int r) {
	val[u].v = l; val[u].c = 1;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}
int n, Q, ls[MAXN];
LL ansl[MAXN];
std::vector<int> qs[MAXN];
struct itv { int l, r, v; } ;
itv sta[MAXN], sti[MAXN];
int topa, topi;
void mkeff(itv x, int c) {
	mdf(1, 1, n, x.l, x.r, x.v * c);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	static int A[MAXN];
	std::cin >> n; build(1, 1, n);
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::cin >> Q;
	for (int i = 1, r; i <= Q; ++i)
		std::cin >> ls[i] >> r, qs[r].push_back(i);
	for (int i = 1; i <= n; ++i) {
		mkadd(1, -1);
		int L = i;
		while (topa && sta[topa].v < A[i])
			L = sta[topa].l, mkeff(sta[topa--], -1);
		mkeff(sta[++topa] = (itv) {L, i, A[i]}, 1);
		L = i;
		while (topi && sti[topi].v > A[i])
			L = sti[topi].l, mkeff(sti[topi--], 1);
		mkeff(sti[++topi] = (itv) {L, i, A[i]}, -1);
		mksav(1, 1);
		for (auto t : qs[i])
			ansl[t] = qry(1, 1, n, ls[t], i);
	}
	for (int i = 1; i <= Q; ++i) std::cout << ansl[i] << '\n';
	return 0;
}