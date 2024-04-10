#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int W, H, x1, x2, y1, y2, w, h;
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		if (x1 <= W - x2) {
			int a = x1;
			int b = x2;
			x1 = W - b;
			x2 = W - a;
		}
		if (y1 <= H - y2) {
			int a = y1;
			int b = y2;
			y1 = H - b;
			y2 = H - a;
		}
		int res = 1e9;
		if (w + x2 - x1 <= W)
			res = min(res, max(0, w - x1));
		if (h + y2 - y1 <= H)
			res = min(res, max(0, h - y1));
		cout << (res == 1e9 ? -1 : res) << "\n";
	}
	return 0;
}