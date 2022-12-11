#include <bits/stdc++.h>

typedef long long LL;
LL calc(LL n, int coef, const int * term) {
	LL bse = 1, res = 0;
	while (n >= bse) n -= bse, bse <<= 2;
	static int dig[1000];
	int bak = 0;
	while (n) dig[bak++] = n % 4, n /= 4;
	for (int i = bak - 1; ~i; --i)
		res = res * 4 + term[dig[i]];
	res += bse * (coef + 1);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		LL n; std::cin >> n;
		static const int arr[3][4] = {
			{0, 1, 2, 3},
			{0, 2, 3, 1},
			{0, 3, 1, 2}
		};
		LL ans = calc((n - 1) / 3, (n - 1) % 3, arr[(n - 1) % 3]);
		std::cout << ans << '\n';
	}
	return 0;
}