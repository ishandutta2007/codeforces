#include <bits/stdc++.h>

const int MAXN = 2010;
int at[MAXN];
int n, S[MAXN], T[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> S[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> T[i], at[T[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		S[i] = at[S[i]] - i;
		ans += std::abs(S[i]);
	}
	ans >>= 1;
	std::cout << ans << std::endl;
	std::vector<std::pair<int, int> > ansl;
	while (ans) {
		int l = 1;
		for (int i = 1; i <= n; ++i)
			if (std::abs(S[i]) > std::abs(S[l]))
				l = i;
		int r = -1;
		if (S[l] > 0) {
			for (int i = S[l] + l; i > l; --i)
				if (S[i] + i <= l) {
					r = i;
					break;
				}
			assert(r != -1);
		} else {
			r = l, l = -1;
			for (int i = S[r] + r; i < r; ++i)
				if (S[i] + i >= r) {
					l = i;
					break;
				}
			assert(l != -1);
		}
		ansl.emplace_back(l, r);
		std::swap(S[l], S[r]);
		S[l] += r - l;
		S[r] -= r - l;
		ans -= r - l;
	}
	std::cout << ansl.size() << '\n';
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}