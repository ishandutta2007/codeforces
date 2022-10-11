#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int H, W, K, dp[2009][2009]; char c[2009][2009];
string S; vector<pair<int, int>> vec[4009];

int main() {
	cin >> H >> K; W = H;
	for (int i = 0; i < H; i++) scanf("%s", &c[i]);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { dp[i][j] = (1 << 30); vec[i + j].push_back(make_pair(i, j)); }
	}
	if (c[0][0] == 'a') { dp[0][0] = 0; S += "a"; }
	else if (K >= 1) { dp[0][0] = 1; S += "a"; }
	else { dp[0][0] = 0; S += c[0][0]; }

	for (int i = 0; i < H + W - 2; i++) {
		for (char pos = 'a'; pos <= 'z'; pos++) {
			int minx = (1 << 30);
			for (pair<int, int> j : vec[i]) {
				if (c[j.first + 1][j.second] == pos || c[j.first][j.second + 1] == pos) minx = min(minx, dp[j.first][j.second]);
				else minx = min(minx, dp[j.first][j.second] + 1);
			}
			if (minx <= K) {
				S += pos;
				for (pair<int, int> j : vec[i]) {
					int dx[2] = { 0, 1 }, dy[2] = { 1, 0 };
					for (int k = 0; k < 2; k++) {
						int sx = j.first + dx[k], sy = j.second + dy[k];
						if (sx >= H || sy >= W) continue;
						int cost = 1; if (c[sx][sy] == pos) cost = 0;
						dp[sx][sy] = min(dp[sx][sy], dp[j.first][j.second] + cost);
					}
				}
				break;
			}
		}
	}
	cout << S << endl;
	return 0;
}