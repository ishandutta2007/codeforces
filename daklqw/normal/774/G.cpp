#include <bits/stdc++.h>

typedef long long LL;
int A, H, W;
double ax = 1e100;
void exgcd(int a, int b, int & x, int & y) {
	if (!b) { x = 1, y = 0; }
	else {
		exgcd(b, a % b, y, x); y -= a / b * x;
	}
}
void solve(int x, int y) {
	int p = y / A, q = y - p * A;
	if (!p) return ;
	int t = ((LL) H * p - q) % y, t2 = (A + H) % y, k, bl;
	exgcd(t2, y, k, bl); k += k >> 31 & y;
	k = (LL) k * t % y;
	p -= k, q += k;
	if (p <= 0 || (LL) H * p < q) return ;
	assert(((LL) H * p - q) % y == 0);
	ax = std::min(ax, (double) q / p);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> A >> H >> W;
	if (H > W) std::swap(H, W);
	if (A <= H) {
		int d = W - H;
		if (!d) {
			int t = H / A;
			ax = (H - t * A) / (t + 1.);
		} else
		for (int i = 1; i * i <= d; ++i)
			if (d % i == 0) solve(i, d / i), solve(d / i, i);
	}
	if (ax > 1e99) std::cout << -1 << std::endl;
	else std::cout << std::fixed << std::setprecision(9) << ax << std::endl;
	return 0;
}