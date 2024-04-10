#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 10010;
namespace db {
	int li[MAXN], bak;
	void init() {
		std::sort(li, li + bak);
		bak = std::unique(li, li + bak) - li;
	}
	void push(int x) { li[bak++] = x; }
	void qry(int & x) {
		x = std::lower_bound(li, li + bak, x) - li + 1;
	}
}
struct deb { int l, r, at; } col[MAXN], row[MAXN];
int cntc, cntr, up;
int n;
std::vector<int> qrs[MAXN], del[MAXN];
int tree[MAXN];
void add(int x, int v) {
	for (; x <= db::bak; x += x & -x) tree[x] += v;
}
int qry(int x) {
	int res = 0;
	for (; x; x &= x - 1) res += tree[x];
	return res;
}
int qry(int l, int r) { return qry(r) - qry(l - 1); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) std::swap(x1, x2);
		if (y1 > y2) std::swap(y1, y2);
		if (x1 == x2) col[++cntc] = (deb) {y1, y2, x1};
		else row[++cntr] = (deb) {x1, x2, y1};
	}
	for (int i = 1; i <= cntc; ++i) db::push(col[i].l), db::push(col[i].r);
	for (int i = 1; i <= cntr; ++i) db::push(row[i].at);
	db::init();
	for (int i = 1; i <= cntc; ++i) db::qry(col[i].l), db::qry(col[i].r);
	for (int i = 1; i <= cntr; ++i) db::qry(row[i].at);
	int lim = db::bak; db::bak = 0;
	for (int i = 1; i <= cntr; ++i) db::push(row[i].l), db::push(row[i].r);
	for (int i = 1; i <= cntc; ++i) db::push(col[i].at);
	db::init();
	for (int i = 1; i <= cntr; ++i) db::qry(row[i].l), db::qry(row[i].r);
	for (int i = 1; i <= cntc; ++i) db::qry(col[i].at);
	for (int i = 1; i <= cntr; ++i)
		qrs[row[i].at].push_back(i);
	for (int i = 1; i <= cntc; ++i) {
		del[col[i].r].push_back(i);
	}
	LL Ans = 0;
	for (int L = 1; L <= lim; ++L) {
		for (int i = 1; i <= cntc; ++i)
			if (col[i].l <= L && col[i].r > L)
				add(col[i].at, 1);
		for (int R = L + 1; R <= lim; ++R) {
			for (auto t1 : qrs[L]) for (auto t2 : qrs[R]) {
				int l = std::max(row[t1].l, row[t2].l);
				int r = std::min(row[t1].r, row[t2].r);
				if (l < r) {
					int c = qry(l, r);
					Ans += c * (c - 1) / 2;
				}
			}
			for (auto t : del[R])
				if (col[t].l <= L)
					add(col[t].at, -1);
		}
	}
	std::cout << Ans << std::endl;
	return 0;
}