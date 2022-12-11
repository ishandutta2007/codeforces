#include <bits/stdc++.h>

const int MAXN = 100010;
const int MAXK = 21;
typedef long long LL;
int n, Q, X;
struct info {
	LL ans;
	int pre[MAXK], ph[MAXK], pc;
	int suc[MAXK], sh[MAXK], sc;
	info() { ans = pc = sc = 0; }
} tree[MAXN << 2];
info operator + (info a, info b) {
	if (a.pc == 0) return b;
	if (b.pc == 0) return a;
	info r; r.ans = a.ans + b.ans;
	static int tmp[22];
	tmp[b.pc] = 0;
	for (int i = b.pc - 1; ~i; --i) tmp[i] = b.ph[i] + tmp[i + 1];
	int cur = 0;
	for (int i = a.sc - 1; ~i; --i) {
		while (cur < b.pc && (a.suc[i] | b.pre[cur]) < X) ++cur;
		r.ans += (LL) a.sh[i] * tmp[cur];
	}
	r.pc = a.pc;
	memcpy(r.pre, a.pre, a.pc << 2);
	memcpy(r.ph, a.ph, a.pc << 2);
	r.sc = b.sc;
	memcpy(r.suc, b.suc, b.sc << 2);
	memcpy(r.sh, b.sh, b.sc << 2);
	for (int i = 0, t = a.pre[a.pc - 1]; i < b.pc; ++i)
		if ((b.pre[i] | t) == r.pre[r.pc - 1])
			r.ph[r.pc - 1] += b.ph[i];
		else r.pre[r.pc] = b.pre[i] | t, r.ph[r.pc++] = b.ph[i];
	for (int i = 0, t = b.suc[b.sc - 1]; i < a.sc; ++i)
		if ((a.suc[i] | t) == r.suc[r.sc - 1])
			r.sh[r.sc - 1] += a.sh[i];
		else r.suc[r.sc] = a.suc[i] | t, r.sh[r.sc++] = a.sh[i];
	return r;
}
void mdf(int u, int l, int r, int at, int v) {
	if (l == r) {
		tree[u].pre[0] = tree[u].suc[0] = v;
		tree[u].ph[0] = tree[u].sh[0] = tree[u].pc = tree[u].sc = 1;
		tree[u].ans = v >= X;
		return ;
	}
	int mid = l + r >> 1;
	if (at <= mid) mdf(u << 1, l, mid, at, v);
	else mdf(u << 1 | 1, mid + 1, r, at, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
info qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; info res;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q >> X;
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, mdf(1, 1, n, i, t);
	while (Q --> 0) {
		int opt, x, y;
		std::cin >> opt >> x >> y;
		if (opt == 1) mdf(1, 1, n, x, y);
		else std::cout << qry(1, 1, n, x, y).ans << '\n';
	}
	return 0;
}