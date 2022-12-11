#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
int n, Q, A[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	while (Q --> 0) {
		int opt, l, r, K;
		std::cin >> opt >> l >> r >> K;
		if (opt == 1) {
			for (int i = l; i <= r; ++i)
				if (A[i] > K)
					A[i] -= K;
		} else {
			int ans = 0;
			for (int i = l; i <= r; ++i) ans += A[i] == K;
			std::cout << ans << '\n';
		}
	}
	return 0;
}