#include <bits/stdc++.h>

using namespace std;

int A[22][22];
int Dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int h, w;

void tc() {
	int h, w, i, j, x, y, dx, dy;
	cin >> h >> w;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			A[i][j] = 0;
		}
	}
	x = 0; y = 0; dy = 1; dx = 0;
	for (; ; ) {
		for (j = 0; j < 8; j++) {
			if (x + Dx[j] < 0 || x + Dx[j] >= h || y + Dy[j] < 0 || y + Dy[j] >= w) continue;
			if (A[x + Dx[j]][y + Dy[j]] == 1) break;
		}
		if (j == 8) A[x][y] = 1;

		if (x + dx < 0 || x + dx >= h || y + dy < 0 || y + dy >= w) {
			swap(dx, dy); dy = -dy; 
		}
		x += dx; y += dy;
		if (x == 0 && y == 0) break;
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cout << A[i][j];
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}