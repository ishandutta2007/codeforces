#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int H, W;
char c[1000009];
string v[1000009];

vector<long long> dp1[1000009], dp2[1000009];
long long mod = 2147483647LL;

int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; i++) {
		scanf("%s", &c);
		for (int j = 0; j < W; j++) v[i] += c[j];
	}
	for (int i = 0; i < H; i++) {
		dp1[i].resize(W, 0);
		dp2[i].resize(W, 0);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (v[i][j] == '#') continue;
			if (i == 0 && j == 0) dp1[i][j] = 1;
			else if (i == 0) dp1[i][j] = dp1[i][j - 1];
			else if (j == 0) dp1[i][j] = dp1[i - 1][j];
			else dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1];
			dp1[i][j] %= mod;
		}
	}
	for (int i = H - 1; i >= 0; i--) {
		for (int j = W - 1; j >= 0; j--) {
			if (v[i][j] == '#') continue;
			if (i == H - 1 && j == W - 1) dp2[i][j] = 1;
			else if (i == H - 1) dp2[i][j] = dp2[i][j + 1];
			else if (j == W - 1) dp2[i][j] = dp2[i + 1][j];
			else dp2[i][j] = dp2[i + 1][j] + dp2[i][j + 1];
			dp2[i][j] %= mod;
		}
	}

	if (dp1[H - 1][W - 1] == 0) {
		cout << "0" << endl;
	}
	else {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == 0 && j == 0) continue;
				if (i == H - 1 && j == W - 1) continue;
				if (dp1[i][j] * dp2[i][j] % mod == dp1[H - 1][W - 1]) {
					cout << "1" << endl;
					return 0;
				}
			}
		}
		cout << "2" << endl;
	}
	return 0;
}