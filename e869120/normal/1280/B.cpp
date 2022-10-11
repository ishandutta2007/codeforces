#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int T, H, W;
char c[109][109];

int solve() {
	int ret = (1 << 30);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int maxs = 4;
			if (i == 0 || i == H - 1) maxs--;
			if (j == 0 || j == W - 1) maxs--;
			if (c[i][j] == 'A') ret = min(ret, maxs);
		}
	}
	for (int i = 0; i < H; i++) {
		int score = 0;
		for (int j = 0; j < W; j++) {
			if (c[i][j] == 'A') score++;
		}
		if (score == W) {
			if (i == 0 || i == H - 1) ret = min(ret, 1);
			else ret = min(ret, 2);
		}
	}
	for (int i = 0; i < W; i++) {
		int score = 0;
		for (int j = 0; j < H; j++) {
			if (c[j][i] == 'A') score++;
		}
		if (score == H) {
			if (i == 0 || i == W - 1) ret = min(ret, 1);
			else ret = min(ret, 2);
		}
	}

	int score = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (c[i][j] == 'A') score++;
		}
	}
	if (score == H * W) ret = min(ret, 0);
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &H, &W);
		for (int j = 0; j < H; j++) scanf("%s", &c[j]);
		int Z = solve();
		if (Z == (1 << 30)) printf("MORTAL\n");
		else printf("%d\n", Z);
	}
	return 0;
}