#include <bits/stdc++.h>

typedef long long LL;
int dig[20];
LL dp[20][16][1 << 16];
LL calc(int dig, int hi, int mask, bool up) {
	if (dig == -1) return mask >> hi & 1;
	if (!up && ~dp[dig][hi][mask]) return dp[dig][hi][mask];
	LL res = 0;
	for (int i = up ? ::dig[dig] : 15; ~i; --i) {
		bool nu = up && i == ::dig[dig];
		int nm = mask;
		if (dig < 4) nm = nm << 4 | i;
		res += calc(dig - 1, std::max(hi, i), nm, nu);
	}
	if (!up) dp[dig][hi][mask] = res;
	return res;
}
LL solve(LL x) {
	int hi = 0;
	while (x) dig[hi++] = x % 16, x /= 16;
	return calc(hi - 1, 0, 0, true);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	memset(dp, -1, sizeof dp);
	int T; std::cin >> T;
	while (T --> 0) {
		LL l, r;
		std::cin >> std::hex >> l >> std::hex >> r;
		std::cout << solve(r) - solve(l - 1) << '\n';
	}
	return 0;
}