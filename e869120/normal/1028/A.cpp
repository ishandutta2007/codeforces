#include <iostream>
#include <algorithm>
using namespace std;

int H, W, minx = 120, maxx = 0, miny = 120, maxy = 0;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char c; cin >> c;
			if (c == 'B') {
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	cout << (maxx + minx) / 2 << " " << (maxy + miny) / 2 << endl;
	return 0;
}