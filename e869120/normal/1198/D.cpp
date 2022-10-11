#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, dp[59][59][59][59];
int A[59][59];

int ranged(int px, int py, int qx, int qy) {
	return A[px - 1][py - 1] + A[qx][qy] - A[px - 1][qy] - A[qx][py - 1];
}

int dfs(int px, int py, int qx, int qy) {
	if (ranged(px, py, qx, qy) == 0) return 0;
	if (dp[px][py][qx][qy] >= 1) return dp[px][py][qx][qy] - 1;

	int ans = max(qx - px + 1, qy - py + 1);
	for (int i = px; i <= qx - 1; i++) {
		int E1 = dfs(px, py, i, qy);
		int E2 = dfs(i + 1, py, qx, qy);
		ans = min(ans, E1 + E2);
	}

	for (int i = py; i <= qy - 1; i++) {
		int E1 = dfs(px, py, qx, i);
		int E2 = dfs(px, i + 1, qx, qy);
		ans = min(ans, E1 + E2);
	}
	dp[px][py][qx][qy] = ans + 1;
	return ans;
}

int main() {
	cin >> H; W = H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			char c; cin >> c;
			if (c == '.') A[i][j] = 0;
			if (c == '#') A[i][j] = 1;
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) A[i][j] += A[i][j - 1];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) A[i][j] += A[i - 1][j];
	}
	cout << dfs(1, 1, H, W) << endl;
	return 0;
}