#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
int n, m, K;
int li[MAXN], bak;
int pre[MAXN];
typedef std::pair<int, int> pi;
typedef std::vector<pi> V;
std::map<int, V> adx;
int tree[MAXN << 2], tag[MAXN << 2];
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) tag[u] += v;
	else {
		int mid = l + r >> 1;
		if (L <= mid) mdf(u << 1, l, mid, L, R, v);
		if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	}
	if (tag[u]) tree[u] = (li[r + 1] - 1) ^ (li[l] - 1);
	else tree[u] = l == r ? 0 : (tree[u << 1] ^ tree[u << 1 | 1]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K;
	for (int i = 1; i <= m; ++i) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		++x2, ++y2;
		li[++bak] = y1, li[++bak] = y2;
		adx[x1].emplace_back(y1, y2);
		adx[x2].emplace_back(-y1, -y2);
	}
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	int lst = 1, ans = 0;
	for (auto T : adx) {
		int now = (T.first - 1) ^ (lst - 1);
		now &= tree[1];
		ans ^= now ^ (now >> 1);
		lst = T.first;
		V & v = T.second;
		std::sort(v.begin(), v.end());
		std::reverse(v.begin(), v.end());
		for (auto t : v) {
			int l, r; std::tie(l, r) = t;
			int co = l < 0 ? -1 : 1;
			l = std::abs(l), r = std::abs(r);
			l = std::lower_bound(li + 1, li + 1 + bak, l) - li;
			r = std::lower_bound(li + 1, li + 1 + bak, r) - li;
			mdf(1, 1, bak, l, r - 1, co);
		}
	}
	K = 1 << std::__lg(K);
	int Ans = 0;
	for (int i = 29, sx = 0; ~i; --i)
		Ans ^= std::min(K, (ans >> i & 1) << i);
	std::cout << (Ans > 0 ? "Hamed" : "Malek") << '\n';
	return 0;
}