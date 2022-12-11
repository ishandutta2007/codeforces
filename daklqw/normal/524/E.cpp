#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int MAXK = 2e5 + 10;
int tr[MAXN << 2];
void mdf(int r, int tar, int v) {
	int l = 1, u = 1;
	while (true) {
		if (l == r) break;
		int mid = l + r >> 1;
		if (tar <= mid) u <<= 1, r = mid;
		else u = u << 1 | 1, l = mid + 1;
	}
	tr[u] = v;
	while (u >>= 1)
		tr[u] = std::max(tr[u << 1], tr[u << 1 | 1]);
}
int qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[u];
	int mid = l + r >> 1;
	int res = 0;
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = std::max(res, qry(u << 1 | 1, mid + 1, r, L, R));
	return res;
}
bool ansl[MAXK];
std::vector<int> col[MAXN], row[MAXN];
struct _ {
	int L, R, l, r;
} qs[MAXK];
int Q;
void solve(std::vector<int> * li, int n, int m) {
	static std::vector<int> qt[MAXN];
	for (int i = 1; i <= Q; ++i) {
		std::swap(qs[i].L, qs[i].l);
		std::swap(qs[i].R, qs[i].r);
		qt[qs[i].l].push_back(i);
	}
	typedef std::pair<int, int> pi;
	static std::vector<pi> mdl[MAXN];
	for (int i = 1; i <= m; ++i) {
		std::sort(li[i].begin(), li[i].end());
		mdf(m, i, 0);
		int lst = 0;
		for (auto t : li[i]) {
			mdl[lst + 1].emplace_back(i, t);
			lst = t;
		}
		if (lst != n)
			mdl[lst + 1].emplace_back(i, n + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (auto t : mdl[i])
			mdf(m, t.first, t.second);
		for (auto t : qt[i])
			ansl[t] |= qry(1, 1, m, qs[t].L, qs[t].R) <= qs[t].r;
		mdl[i].clear();
		qt[i].clear();
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n, m, K;
	std::cin >> n >> m >> K >> Q;
	for (int i = 1, x, y; i <= K; ++i) {
		std::cin >> x >> y;
		col[x].push_back(y);
		row[y].push_back(x);
	}
	for (int i = 1; i <= Q; ++i)
		std::cin >> qs[i].L >> qs[i].l >> qs[i].R >> qs[i].r;
	solve(row, n, m);
	solve(col, m, n);
	static const char ans[2][5] = {"NO", "YES"};
	for (int i = 1; i <= Q; ++i)
		std::cout << ans[ansl[i]] << '\n';
	return 0;
}