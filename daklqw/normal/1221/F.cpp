#include <bits/stdc++.h>

const int MAXN = 500010;
typedef long long LL;
int xs[MAXN], ys[MAXN], vs[MAXN];
int n;
int li[MAXN << 1], bak;
int head[MAXN << 1], nxt[MAXN << 1];
LL tree[MAXN << 3], tag[MAXN << 3];
void mkadd(int x, LL v) {
	tree[x] += v, tag[x] += v;
}
void pushdown(int u) {
	if (LL & t = tag[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, LL v) {
	if (L <= l) return mkadd(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, v);
	mdf(u << 1 | 1, mid + 1, r, L, v);
	tree[u] = std::max(tree[u << 1], tree[u << 1 | 1]);
}
int get(int u, int l, int r) {
	if (l == r) return l;
	int mid = l + r >> 1;
	pushdown(u);
	if (tree[u] == tree[u << 1]) return get(u << 1, l, mid);
	return get(u << 1 | 1, mid + 1, r);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> xs[i] >> ys[i] >> vs[i];
		if (xs[i] > ys[i]) std::swap(xs[i], ys[i]);
		li[++bak] = xs[i], li[++bak] = ys[i];
	}
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	for (int i = 1; i <= n; ++i) {
		xs[i] = std::lower_bound(li + 1, li + 1 + bak, xs[i]) - li;
		ys[i] = std::lower_bound(li + 1, li + 1 + bak, ys[i]) - li;
		nxt[i] = head[xs[i]]; head[xs[i]] = i;
	}
	for (int i = 1; i <= bak; ++i)
		mdf(1, 1, bak, i, li[i - 1] - li[i]);
	LL ans = 0; int ax = 2e9, ay = 2e9;
	const LL NINF = 0xcfcfcfcfcfcfcfcfLL;
	mdf(1, 1, bak, 1, NINF);
	for (int i = bak; i; --i) {
		if (i < bak) mdf(1, 1, bak, i + 1, NINF);
		mdf(1, 1, bak, i, -NINF);
		for (int j = head[i]; j; j = nxt[j])
			mdf(1, 1, bak, ys[j], vs[j]);
		if (tree[1] + li[i] > ans) {
			ans = tree[1] + li[i];
			ax = li[i], ay = li[get(1, 1, bak)];
		}
	}
	std::cout << ans << std::endl;
	std::cout << ax << ' ' << ax << ' ' << ay << ' ' << ay << std::endl;
	return 0;
}