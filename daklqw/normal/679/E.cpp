#include <bits/stdc++.h>

typedef long long LL;
const int INF = std::numeric_limits<int>::max();
const LL INFL = std::numeric_limits<LL>::max();
const int VL = 13;
const LL li[VL] = {
	1, 42, 1764, 74088, 3111696, 130691232, 5489031744ll,
	230539333248ll, 9682651996416ll, 406671383849472ll,
	17080198121677824ll, 717368321110468608ll, 9223372036854775807ll
}; // I believe it won't be such large.
const int MAXN = 100010;
int tol[MAXN];
LL minv[MAXN << 2], dag[MAXN << 2];
LL sev[MAXN], cur[MAXN];
int bel[MAXN << 2], tag[MAXN << 2];
inline void mkset(int u, int v) {
	minv[u] = sev[bel[u] = tag[u] = v]; dag[u] = 0;
}
inline void mkdec(int u, LL v) { dag[u] += v, minv[u] -= v; }
inline void update(int x) {
	bel[x] = minv[x << 1] < minv[x << 1 | 1] ? bel[x << 1] : bel[x << 1 | 1];
	minv[x] = std::min(minv[x << 1], minv[x << 1 | 1]);
}
inline void pushdown(int x) {
	if (int & t = tag[x]) mkset(x << 1, t), mkset(x << 1 | 1, t), t = 0;
	if (LL & t = dag[x]) mkdec(x << 1, t), mkdec(x << 1 | 1, t), t = 0;
}
void mkset(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkset(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mkset(u << 1, l, mid, L, R, v);
	if (mid < R) mkset(u << 1 | 1, mid + 1, r, L, R, v);
	update(u);
}
void mkdec(int u, int l, int r, int L, int R, LL v) {
	if (L <= l && r <= R) return mkdec(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mkdec(u << 1, l, mid, L, R, v);
	if (mid < R) mkdec(u << 1 | 1, mid + 1, r, L, R, v);
	update(u);
}
typedef std::pair<LL, int> pi;
pi query(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return pi(minv[u], bel[u]);
	int mid = l + r >> 1;
	pushdown(u); pi res(INFL, INF);
	if (L <= mid) res = query(u << 1, l, mid, L, R);
	if (mid < R) res = std::min(res, query(u << 1 | 1, mid + 1, r, L, R));
	return res;
}
int n, Q;
void split(int l) {
	if (l == 0 || l == n) return ;
	auto bl = query(1, 1, n, l, l);
	auto br = query(1, 1, n, l + 1, l + 1);
	if (bl.second == br.second) {
		int r = bl.second;
		tol[l] = tol[r]; tol[r] = l + 1;
		cur[l] = cur[r]; sev[l] = bl.first;
		mkset(1, 1, n, tol[l], l, l);
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1, t; i <= n; ++i) {
		tol[i] = i; std::cin >> t;
		cur[i] = std::lower_bound(li, li + VL, t) - li;
		sev[i] = li[cur[i]] - t;
		mkset(1, 1, n, i, i, i);
	}
	while (Q --> 0) {
		int opt, l, r, x;
		std::cin >> opt >> l;
		if (opt == 1) {
			auto res = query(1, 1, n, l, l);
			std::cout << li[cur[res.second]] - res.first << '\n';
		} else if (opt == 2) {
			std::cin >> r >> x;
			split(l - 1); split(r);
			tol[r] = l;
			cur[r] = std::lower_bound(li, li + VL, x) - li;
			sev[r] = li[cur[r]] - x;
			mkset(1, 1, n, l, r, r);
		} else if (opt == 3) {
			std::cin >> r >> x;
			split(l - 1); split(r);
			mkdec(1, 1, n, l, r, x);
			auto res = query(1, 1, n, l, r);
			while (res.first <= 0) {
				while (res.first < 0) {
					int R = res.second;
					sev[R] = res.first;
					do {
						sev[R] += li[cur[R] + 1] - li[cur[R]];
						++cur[R];
					} while (sev[R] < 0);
					mkset(1, 1, n, tol[R], R, R);
					res = query(1, 1, n, l, r);
				}
				if (res.first == 0) {
					mkdec(1, 1, n, l, r, x);
					res = query(1, 1, n, l, r);
				}
			}
		}
	}
	return 0;
}