#include <bits/stdc++.h>

typedef long long LL;
typedef std::pair<LL, LL> pi;
std::map<pi, LL> M[2];
LL solve(LL n, LL v, bool eq = false) {
	if (n < v || n < 1) return 0;
	pi t(n, v);
	if (M[eq].count(t)) return M[eq][t];
	LL mid = n + 1 >> 1;
	LL res = solve(mid - 1, v, eq) + solve(n - mid, v, eq);
	if (eq) res += mid == v; else res += mid >= v;
	return M[eq][t] = res;
}
LL kth(LL n, LL v, LL k) {
	LL mid = n + 1 >> 1;
	k -= mid == v;
	if (!k) return mid;
	LL lhs = solve(mid - 1, v, k);
	if (lhs >= k) return kth(mid - 1, v, k);
	LL res = kth(n - mid, v, k - lhs) + mid;
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	LL n, K, ans;
	std::cin >> n >> K;
	if (K <= 2)
		return std::cout << (K == 1 ? 1 : n) << std::endl, 0;
	K -= 2, n -= 2;
	LL l = 1, r = n;
	while (l <= r) {
		LL mid = l + r >> 1;
		if (solve(n, mid) < K) r = mid - 1;
		else l = mid + 1, ans = mid;
	}
	std::cout << kth(n, ans, K - solve(n, ans + 1)) + 1 << std::endl;
	return 0;
}