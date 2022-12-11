#include <bits/stdc++.h>

const int MAXN = 1010;
typedef long double db;
int H, W, n;
struct vec { int x, y; } ps[MAXN];
inline db pw(db x) { return x * x; }
db ansall = 0;
db calc(db px, db py) {
	db fir = 1e100, sec = 1e100;
	for (int i = 1; i <= n; ++i) {
		db t = pw(px - ps[i].x) + pw(py - ps[i].y);
		if (t < fir) sec = fir, fir = t;
		else if (t < sec) sec = t;
	}
	ansall = std::max(ansall, sec);
	return sec;
}
std::mt19937 rd(time(0) + (size_t) new char);
const auto Up = std::numeric_limits<unsigned>::max();
db rnd() { return rd() / (db) Up; }
inline db lim(db x, int y) {
	return std::min<db>(std::max<db>(x, 0), y);
}
void fire() {
	db x = rnd() * H, y = rnd() * W, ans = calc(x, y);
	for (db T = 1; T > 1e-12; T *= 0.998) {
		db tx = lim(x + (rnd() - 0.5) * H * T, H);
		db ty = lim(y + (rnd() - 0.5) * W * T, W);
		db ta = calc(tx, ty);
		if (ta > ans || std::exp((ta - ans) / T) > rnd())
			x = tx, y = ty, ans = ta;
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> H >> W >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> ps[i].x >> ps[i].y;
	do fire(); while (clock() / (double) CLOCKS_PER_SEC < 1.5);
	std::cout << std::fixed << std::setprecision(15);
	std::cout << sqrtl(ansall) << std::endl;
	return 0;
}