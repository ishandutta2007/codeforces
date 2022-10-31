#include <bits/stdc++.h>
using namespace std;

const int N = 700000;

struct pt {
	int x, y;
	pt (int x = 0, int y = 0) : x(x), y(y) {}
	void in() { cin >> x >> y; }
	void rot() {
		swap(x, y);
		x *= -1;
	}
} p[N];

int dis(pt p1, pt p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
	int n; cin >> n;
	int minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;
	for (int i = 0; i < n; i++) {
		p[i].in();
		minX = min(minX, p[i].x);
		maxX = max(maxX, p[i].x);
		minY = min(minY, p[i].y);
		maxY = max(maxY, p[i].y);
	}
	reverse(p, p + n);
	int v4 = ((maxY - minY) + (maxX - minX)) * 2;
	int v3 = 0;
	for (int T : {0, 1, 2, 3}) {
		for (int i = n; i < n+n; i++) p[i] = p[i - n];
		int Lid, minX = 1e9;
		for (int i = 0; i < n; i++) {
			if (minX > p[i].x) {
				minX = p[i].x;
				Lid = i;
			}
		}
		int Rid, maxX = -1e9;
		for (int i = 0; i < n; i++) {
			if (maxX < p[i].x) {
				maxX = p[i].x;
				Rid = i;
			}
		}
		int Did, minY = 1e9;
		for (int i = 0; i < n; i++) {
			if (minY > p[i].y) {
				minY = p[i].y;
				Did = i;
			}
		}
		int Uid, maxY = -1e9;
		for (int i = 0; i < n; i++) {
			if (maxY < p[i].y) {
				maxY = p[i].y;
				Uid = i;
			}
		}
		if (Uid < Rid) Uid += n;
		for (int i = Rid; i <= Uid; i++) {
			v3 = max(v3, 2 * (p[i].x - minX + p[i].y - minY));
		}
		for (int i = 0; i < n; i++) p[i].rot();
	}
	printf("%d", v3);
	for (int i = 4; i <= n; i++) printf(" %d", v4);
}