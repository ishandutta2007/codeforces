#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
typedef std::vector<int> VI;
int n, m, G;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void exgcd(int a, int b, int & x, int & y) {
	if (!b) x = 1, y = 0;
	else exgcd(b, a % b, y, x), y -= a / b * x;
}
int li[MAXN], bak, tl[MAXN];
LL solve(VI a) {
	int _n = n / G, _m = m / G; bak = 0;
	for (auto t : a) li[++bak] = (t < 0 ? -(t + 1) : t) % _n;
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	if (bak == _n) {
		static int arr[MAXN];
		memset(arr, 0, _m << 2);
		for (int i : a) ++arr[(i < 0 ? -(i + 1) : i) % _n];
		int res = -1;
		for (int i = 0; i < _m; ++i)
			if (arr[i] != 2) res = i;
		return res;
	}
	int inv, t;
	exgcd(_m, _n, inv, t); inv += inv >> 31 & _n;
	assert((LL) _m * inv % _n == 1);
	for (int i = 1; i <= bak; ++i) tl[i] = (LL) li[i] * inv % _n;
	std::sort(tl + 1, tl + 1 + bak);
	tl[bak + 1] = tl[1] + _n;
	LL res = 0;
	for (int i = 1; i <= bak; ++i)
		if (tl[i] + 1 != tl[i + 1])
			res = std::max(res, (LL) (tl[i + 1] - tl[i] - 1) * _m + ((LL) tl[i] * _m) % _n);
	return res;
}
std::map<int, VI> M;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m; G = gcd(n, m);
	int sw = false;
	if (n < m) std::swap(n, m), sw = true;
	int t; std::cin >> t;
	auto D = [] (int a, int b) { return b ? -a - 1 : a; };
	for (int i = 1, t2; i <= t; ++i)
		std::cin >> t2, M[t2 % G].push_back(D(t2 / G, sw));
	std::cin >> t;
	for (int i = 1, t2; i <= t; ++i)
		std::cin >> t2, M[t2 % G].push_back(D(t2 / G, sw ^ 1));
	if (M.size() < G) return std::cout << -1 << std::endl, 0;
	LL ans = 0;
	for (auto i : M) {
		LL res = solve(i.second);
		if (~res) ans = std::max(ans, res * G + i.first);
	}
	std::cout << ans << std::endl;
	return 0;
}