#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
int mi[MAXN << 2], ma[MAXN << 2], set[MAXN << 2];
LL tag[MAXN << 2], sm[MAXN << 2];
void mkadd(int x, int l, LL v) {
	tag[x] += v, sm[x] += l * v;
}
void mkset(int x, int v) {
	set[x] = v, mi[x] = ma[x] = v;
}
void pushdown(int x, int l) {
	if (LL & t = tag[x]) {
		mkadd(x << 1, l + 1 >> 1, t);
		mkadd(x << 1 | 1, l >> 1, t);
		t = 0;
	}
	if (int & t = set[x]) {
		mkset(x << 1, t);
		mkset(x << 1 | 1, t);
		t = 0;
	}
}
void update(int u) {
	ma[u] = std::max(ma[u << 1], ma[u << 1 | 1]);
	mi[u] = std::min(mi[u << 1], mi[u << 1 | 1]);
	sm[u] = sm[u << 1] + sm[u << 1 | 1];
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		if (ma[u] != mi[u]) {
			int mid = l + r >> 1;
			pushdown(u, r - l + 1);
			mdf(u << 1, l, mid, L, R, v);
			mdf(u << 1 | 1, mid + 1, r, L, R, v);
			update(u);
		} else {
			mkadd(u, r - l + 1, std::abs(v - ma[u]));
			mkset(u, v);
		}
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	update(u);
}
LL qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sm[u];
	int mid = l + r >> 1; LL res = 0;
	pushdown(u, r - l + 1);
	if (L <= mid) res += qry(u << 1, l, mid, L, R);
	if (mid < R) res += qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void build(int u, int l, int r) {
	mi[u] = l, ma[u] = r;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
int n, m;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	build(1, 1, n);
	while (m --> 0) {
		int opt, l, r, x;
		std::cin >> opt >> l >> r;
		if (opt == 1) std::cin >> x, mdf(1, 1, n, l, r, x);
		else std::cout << qry(1, 1, n, l, r) << '\n';
	}
	return 0;
}