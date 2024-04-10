#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int A[MAXN], n, m;
std::set<int> app[MAXN];
struct itv {
	int l, r, v, id;
	bool operator < (const itv & b) const {
		return r == b.r ? id < b.id : r < b.r;
	}
} qs[MAXN * 8];
int bak;
LL ansl[MAXN];
void additv(int l, int r, int v) {
	qs[++bak] = (itv) {l, r, v * (r - l), 0};
}
LL tree[MAXN];
void add(int x, int v) {
	for (; x; x &= x - 1) tree[x] += v;
}
LL qry(int x) {
	LL res = 0;
	for (; x <= n; x += x & -x) res += tree[x];
	return res;
}
void solve(int l, int r) {
	if (l >= r) return ;
	int mid = l + r >> 1;
	solve(l, mid); solve(mid + 1, r);
	int lcur = l, rcur = mid + 1;
	while (lcur <= mid || rcur <= r) {
		if (lcur <= mid && (rcur > r || qs[lcur] < qs[rcur])) {
			if (qs[lcur].id == 0) {
				add(qs[lcur].l, qs[lcur].v);
			}
			++lcur;
		} else {
			if (qs[rcur].id != 0) {
				ansl[qs[rcur].id] += qry(qs[rcur].l);
			}
			++rcur;
		}
	}
	for (int i = l; i <= mid; ++i)
		if (qs[i].id == 0)
			add(qs[i].l, -qs[i].v);
	std::sort(qs + l, qs + r + 1);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		if (!app[A[i]].empty()) {
			int at = *app[A[i]].rbegin();
			additv(at, i, 1);
		}
		app[A[i]].insert(i);
	}
	int qc = 0;
	for (int i = 1; i <= m; ++i) {
		int opt, x, y;
		std::cin >> opt >> x >> y;
		if (opt == 2) qs[++bak] = (itv) {x, y, 1, ++qc};
		else {
			auto it = app[A[x]].lower_bound(x), t = it;
			auto pre = it == app[A[x]].begin() ? -1 : *--t;
			auto suc = ++it == app[A[x]].end() ? -1 : *it;
			if (pre != -1) additv(pre, x, -1);
			if (suc != -1) additv(x, suc, -1);
			if (pre != -1 && suc != -1) additv(pre, suc, 1);
			app[A[x]].erase(x);
			t = it = app[A[x] = y].insert(x).first;
			pre = it == app[y].begin() ? -1 : *--t;
			suc = ++it == app[y].end() ? -1 : *it;
			if (pre != -1 && suc != -1) additv(pre, suc, -1);
			if (pre != -1) additv(pre, x, 1);
			if (suc != -1) additv(x, suc, 1);
		}
	}
	solve(1, bak);
	for (int i = 1; i <= qc; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}