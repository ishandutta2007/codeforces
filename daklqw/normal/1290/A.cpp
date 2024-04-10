#include <bits/stdc++.h>

const int MAXN = 3510;
int n, m, K;
int A[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> n >> m >> K; K = std::min(K, m - 1);
		for (int i = 1; i <= n; ++i) std::cin >> A[i];
		int ans = 0;
		for (int pre = 0; pre <= K; ++pre) {
			int t = std::numeric_limits<int>::max();
			for (int tp = pre; tp <= pre + m - 1 - K; ++tp) {
				int tr = m - 1 - tp;
				t = std::min(t, std::max(A[tp + 1], A[n - tr]));
			}
			ans = std::max(ans, t);
		}
		std::cout << ans << '\n';
	}
	return 0;
}