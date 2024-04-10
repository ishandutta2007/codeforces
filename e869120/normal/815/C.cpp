#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, b, p[5700], q[5700], x[5700], dp[5700][5700][2], dp2[5700][5700], dd[5700]; vector<int>X[5700], D;
int dfs(int pos) {
	for (int i = 0; i < X[pos].size(); i++)dd[pos] += dfs(X[pos][i]);
	D.push_back(pos);
	dd[pos] += 1;
	return dd[pos];
}
vector<int>product(vector<int>p1, vector<int>p2, int size_) {
	for (int i = size_ - 2; i >= 0; i--)p1[i] = min(p1[i], p1[i + 1]);
	for (int i = size_ - 2; i >= 0; i--)p2[i] = min(p2[i], p2[i + 1]);
	for (int i = 0; i < p1.size(); i++) {
		if (p1[i] > b) { p1.erase(p1.begin() + i, p1.end()); break; }
	}
	for (int i = 0; i < p2.size(); i++) {
		if (p2[i] > b) { p2.erase(p2.begin() + i, p2.end()); break; }
	}
	vector<int>p3(p1.size() + p2.size() - 1, 1.01e9);
	for (int i = 0; i < p1.size(); i++) {
		for (int j = 0; j < p2.size(); j++) {
			p3[i + j] = min(p3[i + j], p1[i] + p2[j]);
		}
	}
	return p3;
}
int main() {
	cin >> n >> b >> p[1] >> q[1];
	for (int i = 2; i <= n; i++)cin >> p[i] >> q[i] >> x[i], X[x[i]].push_back(i); dfs(1);
	for (int i = 1; i <= n; i++) { for (int j = 0; j <= n; j++)dp[i][j][0] = 1.01e9, dp[i][j][1] = 1.01e9; }
	for (int i : D) {
		for (int j = 0; j <= X[i].size(); j++) {
			for (int k = 0; k <= n; k++)dp2[j][k] = 1.01e9;
		}
		dp2[0][0] = 0;
		for (int j = 0; j < X[i].size(); j++) {
			vector<int>G1, G2;
			for (int k = 0; k <= n; k++)G1.push_back(dp2[j][k]);
			for (int k = 0; k <= n; k++)G2.push_back(dp[X[i][j]][k][0]);
			vector<int>G3 = product(G1, G2, n + 1);
			for (int k = 0; k < G3.size(); k++)dp2[j + 1][k] = G3[k];
		}
		for (int j = 0; j <= n; j++)dp[i][j][0] = min(dp[i][j][0], dp2[X[i].size()][j]);
		for (int j = 0; j <= n; j++)dp[i][j + 1][0] = min(dp[i][j + 1][0], dp2[X[i].size()][j] + p[i]);
		for (int j = 0; j < X[i].size(); j++) {
			for (int k = 0; k <= n; k++)dp2[j][k] = 1.01e9;
		}
		dp2[0][0] = 0;
		for (int j = 0; j < X[i].size(); j++) {
			vector<int>G1, G2;
			for (int k = 0; k <= n; k++)G1.push_back(dp2[j][k]);
			for (int k = 0; k <= n; k++)G2.push_back(min(dp[X[i][j]][k][1], dp[X[i][j]][k][0]));
			vector<int>G3 = product(G1, G2, n + 1);
			for (int k = 0; k < G3.size(); k++)dp2[j + 1][k] = G3[k];
		}
		for (int j = 0; j <= n; j++)dp[i][j + 1][1] = min(dp[i][j + 1][1], dp2[X[i].size()][j] + p[i] - q[i]);
	}
	dp[1][n + 1][0] = 1.2e9; dp[1][n + 1][1] = 1.2e9;
	for (int i = 0; i <= n + 1; i++) {
		if (dp[1][i][1] > b && dp[1][i][0] > b) { cout << i - 1 << endl; break; }
	}
	return 0;
}