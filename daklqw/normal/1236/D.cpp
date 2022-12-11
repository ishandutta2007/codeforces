#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int H, W, n;
struct deque {
	std::vector<int> hav;
	int b, e;
	void init() {
		b = 0, e = hav.size() - 1;
		std::sort(hav.begin(), hav.end());
	}
	bool empty() { return b > e; }
	int front() { return hav[b]; }
	int back() { return hav[e]; }
	void popfront() { ++b; }
	void popback() { --e; }
} col[MAXN], row[MAXN];
const int avx[4] = {0, 1, 0, -1};
const int avy[4] = {1, 0, -1, 0};
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> H >> W >> n;
	const int MA = std::max(H, W) + 1, MI = -1;
	LL sm = (LL) H * W - n;
	for (int i = 1, x, y; i <= n; ++i) {
		std::cin >> x >> y;
		col[y].hav.push_back(x);
		row[x].hav.push_back(y);
	}
	for (int i = 1; i <= H; ++i) row[i].init();
	for (int i = 1; i <= W; ++i) col[i].init();
	int x = 1, y = 0, dire = 0;
	int dx = 0, ux = H + 1, dy = 0, uy = W + 1;
	while (true) {
		int go = -1;
		switch (dire) {
			case 0: {
				while (!row[x].empty() && row[x].front() <= y)
					row[x].popfront();
				go = std::min(uy, row[x].empty() ? MA : row[x].front()) - y;
				break;
			}
			case 1: {
				while (!col[y].empty() && col[y].front() <= x)
					col[y].popfront();
				go = std::min(ux, col[y].empty() ? MA : col[y].front()) - x;
				break;
			}
			case 2: {
				while (!row[x].empty() && row[x].back() >= y)
					row[x].popback();
				go = y - std::max(dy, row[x].empty() ? MI : row[x].back());
				break;
			}
			case 3: {
				while (!col[y].empty() && col[y].back() >= x)
					col[y].popback();
				go = x - std::max(dx, col[y].empty() ? MI : col[y].back());
				break;
			}
		}
		if (--go <= 0) break;
		x += avx[dire] * go, y += avy[dire] * go;
		sm -= go;
		switch (dire) {
			case 0: dx = x; break;
			case 1: uy = y; break;
			case 2: ux = x; break;
			case 3: dy = y; break;
		}
		(++dire) &= 3;
	}
	std::cout << (sm ? "No" : "Yes") << std::endl;
	return 0;
}