#include <bits/stdc++.h>

const int MAXN = 3010;

struct _ {
	int b, e, v;
	bool operator < (const _ & b) const {
		return v < b.v;
	}
} es[MAXN];
int fa[MAXN], sz[MAXN], xs[MAXN], n;
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	std::cin >> n;
	for (int i = 1; i < n; ++i)
		std::cin >> es[i].b >> es[i].e >> es[i].v;
	std::sort(es + 1, es + n);
	int tox = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> xs[i], sz[fa[i] = i] = 1, tox += xs[i];
	int ans = es[1].v;
	for (int i = 1; i < n; ++i) {
		int x = find(es[i].b), y = find(es[i].e);
		sz[y] += sz[x], xs[y] += xs[x];
		fa[x] = y;
		if ((tox - xs[y]) < sz[y]) break;
		ans = es[i + 1].v;
	}
	std::cout << ans << std::endl;
	return 0;
}