#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int NINF = 0xcfcfcfcf;

void gma(int & x, int y) { x < y ? x = y : 0; }
int n, Q;
struct seg {
	int tr[MAXN << 3], LL;
	void mdf(int tar, int v) {
		int u = 1, l = 1, r = LL;
		while (l != r) {
			int mid = l + r >> 1;
			if (tar <= mid) u <<= 1, r = mid;
			else u = u << 1 | 1, l = mid + 1;
		}
		tr[u] = v;
		while (u >>= 1)
			tr[u] = std::max(tr[u << 1], tr[u << 1 | 1]);
	}
	int qry(int L, int u = 1, int l = 1, int r = -1) {
		if (L <= l) return tr[u];
		if (r == -1) r = LL;
		int mid = l + r >> 1;
		if (L <= mid)
			return std::max(tr[u << 1 | 1], qry(L, u << 1, l, mid));
		return qry(L, u << 1 | 1, mid + 1, r);
	}
} sg, vl;
int at[11], dp[MAXN], val[MAXN];

std::set<int> pos;
void seton(int at, int T) {
	int v = val[at] - Q + T;
	if (v > 10) {
		sg.mdf(at, dp[at]);
		vl.mdf(val[at], dp[at]);
	}
}

void recalc(int at, int T) {
	if (pos.size() >= at) {
		int v = *std::next(pos.begin(), at - 1);
		if (val[v] - Q + T > 10) {
			vl.mdf(val[v], 0);
			dp[v] = vl.qry(val[v]) + 1;
			seton(v, T);
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	sg.LL = n, vl.LL = Q + 10;
	for (int T = 1; T <= Q; ++T) {
		int opt, x, v;
		std::cin >> opt >> x;
		if (opt == 1) {
			std::cin >> v;
			pos.insert(at[v] = x);
			val[x] = v + Q - T;
			recalc(11, T);
		} else {
			auto it = std::next(pos.begin(), x - 1);
			v = *it;
			for (int i = 1; i <= 10; ++i) if (at[i] == v) at[i] = 0;
			sg.mdf(v, 0);
			vl.mdf(val[v], 0);
			val[v] = 0;
			pos.erase(it);
			for (int i = 10; i; --i) recalc(i, T);
		}
		int ans = sg.qry(1);
		for (int i = 10; i; --i) if (at[i]) {
			dp[at[i]] = sg.qry(at[i]) + 1;
			sg.mdf(at[i], dp[at[i]]);
			ans = std::max(ans, dp[at[i]]);
		}
		for (int i = 10; i; --i) if (at[i]) sg.mdf(at[i], 0);
		std::cout << ans << '\n';
		if (at[10]) seton(at[10], T + 1);
		int j = 1;
		for (auto it = pos.begin(); it != pos.end() && j != 11; ++j, ++it)
			vl.mdf(val[*it], 0);
		for (int i = 10; i; --i) at[i] = at[i - 1];
	}
	return 0;
}