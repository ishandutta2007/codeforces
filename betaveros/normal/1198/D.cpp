#include <iostream>
#include <algorithm>
using namespace std;

const int N = 52;
int n;
char grid[N][N];
int dp[N][N][N][N]; // min cost for h w i j

int main() {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		fgets(grid[i], N, stdin);
	}

	for (int h = 1; h <= n; h++) {
		for (int w = 1; w <= n; w++) {
			for (int i = 0; i <= n - h; i++) {
				for (int j = 0; j <= n - w; j++) {
					// compute dp[h][w][i][j]
					// paint whole rectangle
					int x = max(h, w);

					if (h == 1 && w == 1 && grid[i][j] == '.') {
						x = 0;
					} else {
						for (int i2 = i + 1; i2 < i + h; i2++) {
							x = min(x, dp[i2 - i][w][i][j] + dp[i + h - i2][w][i2][j]);
						}

						for (int j2 = j + 1; j2 < j + w; j2++) {
							x = min(x, dp[h][j2 - j][i][j] + dp[h][j + w - j2][i][j2]);
						}
					}

					dp[h][w][i][j] = x;
				}
			}
		}
	}

	printf("%d\n", dp[n][n][0][0]);
}