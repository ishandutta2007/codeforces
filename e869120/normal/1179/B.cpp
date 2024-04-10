#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);
int H, W, cnts, lx[MAX_N], ly[MAX_N]; vector<int>G[MAX_N];

int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; i++) G[i].resize(W, 0);
	for (int i = 0; i <= (H - 1) / 2; i++) {
		int b1 = i, b2 = H - 1 - i;
		if (b1 == b2) {
			vector<pair<int, int>>vec;
			for (int j = 0; j < W; j++) vec.push_back(make_pair(abs(j * 2 - (W - 1)), -j));
			sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
			for (int j = 0; j < W; j++) { G[b1][-vec[j].second] = cnts; cnts++; }
		}
		else {
			vector<pair<int, int>>vec;
			for (int j = 0; j < W; j++) vec.push_back(make_pair(abs(j * 2 - (W - 1)), -j));
			sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
			int r = 0;
			for (int j = 0; j < W; j++) {
				if (r % 2 == 0) { G[b1][-vec[j].second] = cnts; cnts++; }
				if (r % 2 == 1) { G[b2][-vec[j].second] = cnts; cnts++; }
				r++;
			}
			for (int j = W - 1; j >= 0; j--) {
				if (r % 2 == 0) { G[b1][-vec[j].second] = cnts; cnts++; }
				if (r % 2 == 1) { G[b2][-vec[j].second] = cnts; cnts++; }
				r++;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { lx[G[i][j]] = i + 1; ly[G[i][j]] = j + 1; }
	}
	for (int i = 0; i < H*W; i++) printf("%d %d\n", lx[i], ly[i]);
	return 0;
}