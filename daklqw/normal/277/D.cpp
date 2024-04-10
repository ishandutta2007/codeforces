#include <bits/stdc++.h>

typedef long double ld;
const int MAXN = 1010;

int n, T;
struct Prob {
	int te, se, th, sh; ld prob;
	friend bool operator < (Prob a, Prob b) {
		return a.th * a.prob * (1 - b.prob) < b.th * b.prob * (1 - a.prob);
	}
} ps[MAXN];
const ld eps = 1e-12;
struct status {
	ld x, y;
	status(ld a = 0, ld b = 0) { x = a, y = b; }
	bool operator < (status b) const {
		return fabsl(x - b.x) < eps ? y < b.y : x > b.x;
	}
	friend status operator + (status a, status b) {
		return status(a.x + b.x, a.y + b.y);
	}
} f[MAXN][1600];
void getmin(status & a, status b) {
	b < a ? (void) (a = b) : (void) (0);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> T;
	for (int i = 1; i <= n; ++i)
		std::cin >> ps[i].se >> ps[i].sh >> ps[i].te >> ps[i].th >> ps[i].prob;
	std::sort(ps + 1, ps + 1 + n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= T; ++j)
			getmin(f[i][j], f[i - 1][j]);
		for (int j = ps[i].te; j <= T; ++j)
			getmin(f[i][j], f[i - 1][j - ps[i].te] + status(ps[i].se, ps[i].te));
		for (int j = ps[i].te + ps[i].th; j <= T; ++j) {
			status t = f[i - 1][j - ps[i].te - ps[i].th];
			getmin(f[i][j], status(t.x + ps[i].se + (1 - ps[i].prob) * ps[i].sh, t.y * ps[i].prob + ps[i].te + (1 - ps[i].prob) * (j - ps[i].te)));
		}
	}
	status ans;
	for (int j = 0; j <= T; ++j)
		getmin(ans, f[n][j]);
	std::cout << std::fixed << std::setprecision(20) << ans.x << " " << ans.y << std::endl;
	return 0;
}