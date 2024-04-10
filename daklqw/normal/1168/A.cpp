#include <bits/stdc++.h>

const int MAXN = 300010;
int n, m, A[MAXN];
bool judge(int delta) {
	int low = 0;
	for (int i = 1; i <= n; ++i) {
		int lb = A[i], ub = (A[i] + delta) % m;
		if (lb <= ub) {
			if (low < lb) low = lb;
			if (low > ub) return false;
		} else {
			if (low < lb && low > ub) low = lb;
		}
	}
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	int l = 0, r = m - 1, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (judge(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	std::cout << ans << std::endl;
	return 0;
}