#include <iostream>
#include <algorithm>
using namespace std;

int dp[59][59][59], cs[59][59][59][59];
int N, H, Q, cl[59], cr[59], ch[59], cp[59];

int solve(int L, int R, int A) {
	if (L > R) return 0;
	if (dp[L][R][A] != -(1 << 30)) return dp[L][R][A];

	int minx = -(1 << 29);
	for (int i = 0; i <= A; i++) {
		for (int j = L; j <= R; j++) {
			//  [L, R] j 
			int V1 = cs[L][R][j][i];
			int V2 = solve(L, j - 1, i);
			int V3 = solve(j + 1, R, i);
			if (L == 1 && R == 1 && j == 1 && i == 3) {
				i += 0;
			}
			minx = max(minx, i * i + V2 + V3 - V1);
		}
	}
	dp[L][R][A] = minx;
	return minx;
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			for (int k = i; k <= j; k++) {
				for (int l = 0; l <= H; l++) {
					for (int m = 1; m <= Q; m++) {
						if (i <= cl[m] && cr[m] <= j && cl[m] <= k && k <= cr[m] && ch[m] < l) cs[i][j][k][l] += cp[m];
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> H >> Q;
	for (int i = 1; i <= Q; i++) cin >> cl[i] >> cr[i] >> ch[i] >> cp[i];
	for (int i = 0; i < 59; i++) { for (int j = 0; j < 59; j++) { for (int k = 0; k < 59; k++) dp[i][j][k] = -(1 << 30); } }
	init();
	cout << solve(1, N, H) << endl;
	return 0;
}