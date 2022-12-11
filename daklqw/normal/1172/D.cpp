#include <bits/stdc++.h>

const int MAXN = 1010;
int R[MAXN], C[MAXN], n;
int ar[MAXN], ac[MAXN];
std::vector<std::vector<int> > ansl;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> R[i], ar[R[i]] = i;
	for (int i = 1; i <= n; ++i) std::cin >> C[i], ac[C[i]] = i;
	for (int i = 1; i <= n; ++i) {
		if (R[i] == i && C[i] == i) continue;
		ansl.push_back({ar[i], i, i, ac[i]});
		ar[R[ar[i]] = R[i]] = ar[i];
		ac[C[ac[i]] = C[i]] = ac[i];
	}
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl) {
		for (auto i : t)
			std::cout << i << ' ';
		std::cout << '\n';
	}
	return 0;
}