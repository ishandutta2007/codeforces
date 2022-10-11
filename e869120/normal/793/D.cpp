#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[87][87][87][87], n, m, k, a, b, c, minx = 1e9, x[87][87];
int solve(int num, int pos, int L, int R) {
	if (num == m)return 0;
	if (dp[num][pos][L][R] != -1)return dp[num][pos][L][R];
	int res = 1e9;
	for (int i = L + 1; i < pos; i++) {
		if (x[pos][i] == 0)continue;
		res = min(res, solve(num + 1, i, L, pos) + x[pos][i]);
	}
	for (int i = pos + 1; i <= R - 1; i++) {
		if (x[pos][i] == 0)continue;
		res = min(res, solve(num + 1, i, pos, R) + x[pos][i]);
	}
	dp[num][pos][L][R] = res;
	return res;
}
int main() {
	cin >> n >> m >> k;
	if (n < m) { cout << "-1" << endl; return 0; }
	if (k == 1) { cout << "0" << endl; return 0; }
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c; if (x[a][b] == 0)x[a][b] = c; x[a][b] = min(x[a][b], c); minx = min(minx, c);
	}
	if (k == 2) { cout << minx << endl; return 0; }

	for (int i = 0; i <= 85; i++) { for (int j = 0; j <= 85; j++) { for (int k = 0; k <= 85; k++) { for (int l = 0; l <= 85; l++)dp[i][j][k][l] = -1; } } }
	int ret = 1e9;
	for (int i = 1; i <= n; i++) {
		ret = min(ret, solve(1, i, 0, n + 1));
	}
	if (ret == 1000000000)ret = -1;
	cout << ret << endl;
	return 0;
}