/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int W, H, x1, y1, x2, y2, w, h;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
	auto f = [&](int W, int x1, int x2, int w) {
		if (W < w + (x2 - x1)) return INT_MAX;
		int d = max(x1, W - x2);
		return max(0, w - d);
	};
	auto ans = min(f(W, x1, x2, w), f(H, y1, y2, h));
	cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}