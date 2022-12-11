#include <bits/stdc++.h>

const int MAXN = 200010;
const int MAXP = MAXN << 2;
std::set<int> tr[MAXP];
int ansl[MAXN];
int ma[MAXP], dp[MAXP], mi[MAXP];
void mdf(int u, int l, int r, int L, int R, int v, int t) {
	if (L <= l && r <= R) {
		if (t == 1) tr[u].insert(v);
		else if (t == -1) tr[u].erase(v);
		ma[u] = tr[u].empty() ? 0 : *tr[u].rbegin();
	} else {
		int mid = l + r >> 1;
		if (L <= mid) mdf(u << 1, l, mid, L, R, v, t);
		if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v, t);
	}
	dp[u] = 0, mi[u] = ma[u];
	if (l < r) {
		dp[u] = std::max(dp[u << 1], dp[u << 1 | 1]);
		mi[u] = std::max(ma[u], std::min(mi[u << 1], mi[u << 1 | 1]));
	}
	if (dp[u] < ma[u]) dp[u] = ansl[ma[u]] ? 0 : ma[u];
	if (dp[u] < mi[u]) dp[u] = 0;
}
struct itv { int l, r, v; } ;
std::vector<itv> ins[MAXN], del[MAXN];
std::map<int, int> DC; int idx, idy;
struct mat { int x1, y1, x2, y2; } ms[MAXN];
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> ms[i].x1 >> ms[i].y1 >> ms[i].x2 >> ms[i].y2;
	for (int i = 1; i <= n; ++i) ++DC[ms[i].x1], ++DC[ms[i].x2];
	for (auto & t : DC) t.second = ++idx;
	for (int i = 1; i <= n; ++i)
		ms[i].x1 = DC[ms[i].x1], ms[i].x2 = DC[ms[i].x2];
	DC.clear();
	for (int i = 1; i <= n; ++i) ++DC[ms[i].y1], ++DC[ms[i].y2];
	for (auto & t : DC) t.second = ++idy;
	for (int i = 1; i <= n; ++i)
		ms[i].y1 = DC[ms[i].y1], ms[i].y2 = DC[ms[i].y2];
	for (int i = 1; i <= n; ++i) {
		mat t = ms[i];
		ins[t.x1].push_back((itv) {t.y1, t.y2 - 1, i});
		del[t.x2].push_back((itv) {t.y1, t.y2 - 1, i});
	}
	for (int i = 1; i <= idx; ++i) {
		for (auto t : ins[i])
			mdf(1, 1, idy, t.l, t.r, t.v, 1);
		for (auto t : del[i])
			mdf(1, 1, idy, t.l, t.r, t.v, -1);
		while (int u = dp[1]) {
			ansl[u] = true; mat t = ms[u];
			mdf(1, 1, idy, t.y1, t.y2 - 1, u, 0);
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) ans += ansl[i];
	std::cout << ans << std::endl;
	return 0;
}