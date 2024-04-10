#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

const int MAXN = 100010;
int n, W, Q, A[MAXN];
int ma[MAXN], mi[MAXN], tar[MAXN], ans[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> W >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= Q; ++i) {
		std::cin >> tar[i]; tar[i] = W - tar[i];
		ma[i] = 0, mi[i] = 1e9;
	}
	for (int i = 1; i <= n; ++i) {
		const int t = A[i];
		for (int j = 1; j <= Q; ++j) {
			if (ma[j] < t) ma[j] = t;
			if (mi[j] > t) mi[j] = t;
			if (ma[j] - mi[j] > tar[j]) {
				ma[j] = t;
				mi[j] = t;
				++ans[j];
			}
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ans[i] << '\n';
	return 0;
}