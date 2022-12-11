#include <bits/stdc++.h>

const int MAXN = 1010;
int A[MAXN], n;
typedef std::pair<int, int> pi;
std::vector<pi> ansl;
void make(int x, int y) {
	ansl.emplace_back(x, y);
	A[y] -= A[x], A[x] <<= 1;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	while (true) {
		static pi li[MAXN];
		int bak = 0;
		for (int i = 1; i <= n; ++i)
			if (A[i]) li[++bak] = pi(A[i], i);
		if (bak < 2) {
			std::cout << -1 << std::endl;
			return 0;
		}
		if (bak == 2) break;
		std::sort(li + 1, li + 1 + bak);
		int v = li[2].first / li[1].first;
		for (; v; v >>= 1)
			make(li[1].second, li[v & 1 ? 2 : 3].second);
	}
	std::cout << ansl.size() << '\n';
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}