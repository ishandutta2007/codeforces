#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
typedef long long LL;
int n, A[MAXN];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void gma(int & x, int y) {
	x < y ? x = y : 0;
}
int ma[MAXN];
int can[MAXN << 1];
std::vector<int> hav[MAXN];
int suc[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> A[i], hav[gcd(i, n)].push_back(i);
	LL ans = 0;
	for (int i = 1; i < n; ++i) if (!hav[i].empty()) {
		memset(ma, 0, i << 2);
		for (int j = 0; j < n; ++j)
			gma(ma[j % i], A[j]);
		for (int j = 0; j < n; ++j)
			can[j] = can[j + n] = (A[j] >= ma[j % i]);
		int r = 0;
		memset(suc, 0, n + 1 << 2);
		for (int j = 0; j < n; ++j) {
			if (!can[j]) continue;
			r = std::max(r, j);
			while (can[r]) ++r;
			++suc[std::min(r - j, n)];
		}
		for (int j = n; j; --j) suc[j] += suc[j + 1];
		for (auto t : hav[i]) ans += suc[t];
	}
	std::cout << ans << std::endl;
	return 0;
}