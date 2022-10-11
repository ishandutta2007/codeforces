#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int BASE = 120000;

int H, W, N, g[1 << 17], p[1 << 17], t[1 << 17], ansx[1 << 17], ansy[1 << 17];
vector<pair<int, int>> X[1 << 19]; vector<int> Z[1 << 19];

int main() {
	scanf("%d%d%d", &N, &W, &H);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &g[i], &p[i], &t[i]);
		if (g[i] == 1) {
			X[p[i] - t[i] + BASE].push_back(make_pair(p[i], i));
			Z[p[i] - t[i] + BASE].push_back(-(W - p[i]));
		}
		else {
			X[p[i] - t[i] + BASE].push_back(make_pair(-p[i], i));
			Z[p[i] - t[i] + BASE].push_back(H - p[i]);
		}
	}
	for (int i = 0; i <= H + W + BASE; i++) {
		sort(X[i].begin(), X[i].end());
		sort(Z[i].begin(), Z[i].end());
	}
	for (int i = 0; i <= H + W + BASE; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			int id = X[i][j].second;
			if (Z[i][j] < 0) {
				ansx[id] = W + Z[i][j];
				ansy[id] = H;
			}
			else {
				ansx[id] = W;
				ansy[id] = H - Z[i][j];
			}
		}
	}
	for (int i = 1; i <= N; i++) printf("%d %d\n", ansx[i], ansy[i]);
	return 0;
}