#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;

int fa[MAXN], sm[MAXN], R[MAXN];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int A[MAXN], n;
std::vector<int> qs[MAXN];
int xs[MAXN], ys[MAXN];

int rs[MAXN], ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> xs[i] >> ys[i];
	int Q; std::cin >> Q;
	for (int i = 1, l; i <= Q; ++i) {
		std::cin >> l >> rs[i];
		qs[l].push_back(i);
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = n; i; --i){
		int cur = i;
		R[i] = xs[i] + ys[i];
		while (cur < n) {
			if (R[cur] >= xs[cur + 1]) {
				fa[cur] = cur + 1;
				int u = find(cur + 1);
				R[u] = std::max(R[u], R[cur]);
				cur = u;
			} else break;
		}
		sm[cur] = cur == n ? 0 : xs[cur + 1] - R[cur] + sm[find(cur + 1)];
		for (auto t : qs[i])
			ansl[t] = sm[find(i)] - sm[find(rs[t])];
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}