#include <bits/stdc++.h>

const int MAXN = 400010;
typedef long long LL;
int A[MAXN], n;
int hav[1 << 25];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	int ans = 0;
	for (int i = 0; i != 25; ++i) {
		const int U = 1 << i + 1;
		memset(hav, 0, U << 2);
		for (int j = 1; j <= n; ++j) ++hav[A[j] & (U - 1)];
		int bi = 0;
		for (int j = U - 1; ~j; --j) hav[j] += hav[j + 1];
		for (int j = 1; j < U; ++j) {
			int si = hav[j] - hav[j + 1];
			if ((j + j) >> i & 1) {
				if ((LL) si * (si - 1) / 2 % 2 == 1) bi ^= 1;
			}
			if (si & 1) {
			int l = 1 << i, r = 1 << i + 1;
			l = std::max(0, l - j), r = std::min(r - j, j);
			if (l < r) {
				if ((LL) (hav[l] - hav[r]) * si % 2 == 1) bi ^= 1;
			}
			l = (1 << i + 1) + (1 << i), r = (1 << i + 2);
			l = std::max(0, l - j), r = std::min(r - j, j);
			if (l < r) {
				if ((LL) (hav[l] - hav[r]) * si % 2 == 1) bi ^= 1;
			}
			}
		}
		ans ^= bi << i;
	}
	std::cout << ans << std::endl;
	return 0;
}