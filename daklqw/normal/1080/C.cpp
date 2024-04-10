#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
typedef long long LL;
inline LL getcnt(int x1, int y1, int x2, int y2) {
	LL cnt = static_cast<LL> (y2 - y1 + 1) * (x2 - x1 + 1);
	return cnt;
}
LL calcw(int x1, int y1, int x2, int y2) {
	LL cnt = static_cast<LL> (y2 - y1 + 1) * (x2 - x1 + 1);
	if (cnt & 1) {
		return (((x1 ^ y1) & 1) == 0) + (cnt >> 1);
	}
	return cnt >> 1;
}
LL calcb(int x1, int y1, int x2, int y2) {
	LL cnt = static_cast<LL> (y2 - y1 + 1) * (x2 - x1 + 1);
	if (cnt & 1) {
		return (((x1 ^ y1) & 1) == 1) + (cnt >> 1);
	}
	return cnt >> 1;
}
int main() {
	int T; std::cin >> T;
	while (T --> 0) {
		int n, m, x1, x2, y1, y2, x3, x4, y3, y4;
		std::cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		LL ans1 = calcw(1, 1, n, m), ans2 = calcb(1, 1, n, m);
		ans1 -= calcw(x1, y1, x2, y2);
		ans1 -= calcw(x3, y3, x4, y4);
		ans2 -= calcb(x1, y1, x2, y2);
		ans2 -= calcb(x3, y3, x4, y4);
		ans1 += getcnt(x1, y1, x2, y2);
		ans2 += getcnt(x3, y3, x4, y4);
		int tx1 = std::max(x1, x3);
		int tx2 = std::min(x2, x4);
		int ty1 = std::max(y1, y3);
		int ty2 = std::min(y2, y4);
		if (tx1 <= tx2 && ty1 <= ty2) {
			ans1 += calcw(tx1, ty1, tx2, ty2);
			ans2 += calcb(tx1, ty1, tx2, ty2);
			ans1 -= getcnt(tx1, ty1, tx2, ty2);
		}
		std::cout << ans1 << " " << ans2 << std::endl;
	}
	return 0;
}