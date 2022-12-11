#include <bits/stdc++.h>

typedef long long LL;
int up(int x, int y) { return x / y + (x % y != 0); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int A, B, n; std::cin >> A >> B; n = A + B;
	int ans = 0;
	for (int l = 1, r, t; l <= n; l = r + 1) {
		t = n / l, r = n / t;
		int ll = std::max(up(A, t + 1) + up(B, t + 1), l);
		int rr = std::min(A / t + B / t, r);
		if (up(A, t + 1) > A / t) continue;
		if (up(B, t + 1) > B / t) continue;
		ans += std::max(rr - ll + 1, 0);
	}
	std::cout << ans << std::endl;
	return 0;
}