#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 400009;
vector<int>G1[MAX_N], G2[MAX_N];

long long H, W, Q, X[100009], Y[100009], ans[100009], BASE = 200000;

int main() {
	scanf("%d%d%d", &H, &W, &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		G1[X[i] + Y[i] + BASE].push_back(i);
		G2[X[i] - Y[i] + BASE].push_back(i);
	}
	for (int i = 1; i <= Q; i++) ans[i] = (1LL << 60);

	int cx = 0, cy = 0, cnt = 0; long long leap = 0;
	while (true) {
		if (cnt % 4 == 0) {
			int r1 = H - cx, r2 = W - cy, V = min(r1, r2);
			for (int pos : G2[cx - cy + BASE]) ans[pos] = min(ans[pos], leap + (X[pos] - cx));
			cx += V; cy += V; leap += 1LL * V;
		}
		if (cnt % 4 == 1) {
			int r1 = cx, r2 = W - cy, V = min(r1, r2);
			for (int pos : G1[cx + cy + BASE]) ans[pos] = min(ans[pos], leap + (cx - X[pos]));
			cx -= V; cy += V; leap += 1LL * V;
		}
		if (cnt % 4 == 2) {
			int r1 = cx, r2 = cy, V = min(r1, r2);
			for (int pos : G2[cx - cy + BASE]) ans[pos] = min(ans[pos], leap + (cx - X[pos]));
			cx -= V; cy -= V; leap += 1LL * V;
		}
		if (cnt % 4 == 3) {
			int r1 = H - cx, r2 = cy, V = min(r1, r2);
			for (int pos : G1[cx + cy + BASE]) ans[pos] = min(ans[pos], leap + (X[pos] - cx));
			cx += V; cy -= V; leap += 1LL * V;
		}
		if (cy == 0) {
			if (cnt == 3) cnt = 0;
			if (cnt == 2) cnt = 1;
		}
		else if (cx == H) {
			if (cnt == 0) cnt = 1;
			if (cnt == 3) cnt = 2;
		}
		else if (cy == W) {
			if (cnt == 0) cnt = 3;
			if (cnt == 1) cnt = 2;
		}
		else if (cx == 0) {
			if (cnt == 1) cnt = 0;
			if (cnt == 2) cnt = 3;
		}

		if (cx == 0 && cy == 0) break;
		if (cx == 0 && cy == W) break;
		if (cx == H && cy == 0) break;
		if (cx == H && cy == W) break;
	}
	for (int i = 1; i <= Q; i++) { if (ans[i] == (1LL << 60)) ans[i] = -1; }
	for (int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}