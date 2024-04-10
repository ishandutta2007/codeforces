#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, c[5009], p[100009], f[509], g[19], dp[6009][6009];
vector<int>vec[100009];

void init() {
	for (int i = 0; i <= n*k; i++) { for (int j = 0; j <= n; j++) dp[i][j] = -(1 << 30); }
	dp[0][0] = 0;
	for (int i = 0; i <= n*k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= k; l++) dp[i + l][j + 1] = max(dp[i + l][j + 1], dp[i][j] + g[l]);
		}
	}
}
int solve(int N, int M) {
	int maxn = 0;
	for (int i = 0; i <= N; i++) maxn = max(maxn, dp[i][M]);
	return maxn;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n*k; i++) { cin >> c[i]; p[c[i]]++; }
	for (int i = 0; i < n; i++) { cin >> f[i]; vec[f[i]].push_back(i); }
	for (int i = 1; i <= k; i++) cin >> g[i];

	init();
	int ret = 0;

	for (int i = 0; i <= 100000; i++) {
		if (vec[i].size() == 0) continue;
		// N  M 
		ret += solve(p[i], vec[i].size());
	}
	cout << ret << endl;
	return 0;
}