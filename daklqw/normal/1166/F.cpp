#include <bits/stdc++.h>

const int MAXN = 100010;
int fa[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
std::map<int, int> lst[MAXN];
std::set<int> sing[MAXN];
void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) {
		fa[x] = y;
		if (sing[x].size() > sing[y].size())
			sing[x].swap(sing[y]);
		for (auto t : sing[x]) sing[y].insert(t);
		sing[x].clear();
	}
}
void add(int u, int v, int c) {
	if (int t = lst[c][u]) merge(t, v);
	lst[c][u] = v;
	sing[find(u)].insert(v);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n, m, C, Q;
	std::cin >> n >> m >> C >> Q;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1, x, y, v; i <= m; ++i)
		std::cin >> x >> y >> v, add(x, y, v), add(y, x, v);
	while (Q --> 0) {
		static char opt[10];
		int x, y, z;
		std::cin >> opt >> x >> y;
		if (*opt == '+') {
			std::cin >> z;
			add(x, y, z);
			add(y, x, z);
		} else {
			bool ans = find(x) == find(y) || sing[find(x)].count(y);
			std::cout << (ans ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}