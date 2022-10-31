#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 105;
const int inf = 1000;
const int mod = 1e9 + 7;

int dp[MAXN / 2][MAXN / 2][MAXN / 2][MAXN];
int C[MAXN][MAXN];

int main() {
	for(int i = 0; i <= 100; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			C[i][j] = min(inf, C[i - 1][j] + C[i - 1][j - 1]);
		}
	}
	dp[0][1][0][1] = 1;
	int ans = 0, n, K, m;
	cin >> n >> m >> K;
	for(int i = 0; i <= n / 2 && i < m; i++) {
		for(int j = 1; j <= n / 2; j++)
			for(int k = 0; k <= n / 2; k++)
				for(int l = 1; l <= K; l++) {
					if (i)
						ans = (ans + dp[i][j][k][l] * (m - i)) % mod;
					for(int s = 1; s + k <= n / 2; s++) {
						int r = l * C[j + s - 1][s];
						if (r <= K) {
							dp[i + 1][s][k + s][r] += dp[i][j][k][l];
							dp[i + 1][s][k + s][r] %= mod;
						}
					}
				}
	}
	cout << ans << endl;
	return 0;
}