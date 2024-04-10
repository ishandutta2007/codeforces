#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include<queue>
using namespace std;
long long n, x[1000], y[1000], r[1000], dp[1000][2][2], res[1000]; vector<int>X[1000]; bool used[1000]; vector<pair<int, int>>G;
long long dfs(int pos, int rec1, int rec2) {
	if (dp[pos][rec1][rec2] >= 0)return dp[pos][rec1][rec2];
	long long ret1 = 0; for (int i = 0; i < X[pos].size(); i++)ret1 += dfs(X[pos][i], rec1 ^ 1, rec2); if (rec1 == 1)ret1 -= r[pos] * r[pos]; else ret1 += r[pos] * r[pos];
	long long ret2 = 0; for (int i = 0; i < X[pos].size(); i++)ret2 += dfs(X[pos][i], rec1, rec2 ^ 1); if (rec2 == 1)ret2 -= r[pos] * r[pos]; else ret2 += r[pos] * r[pos];
	dp[pos][rec1][rec2] = max(ret1, ret2);
	return dp[pos][rec1][rec2];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i] >> r[i], G.push_back(make_pair(r[i], i)); sort(G.begin(), G.end());
	for (int i = 0; i < n; i++) { for (int j = 0; j < 4; j++)dp[i][j / 2][j % 2] = -1; }
	for (int h = 0; h < n; h++) {
		int i = G[h].second;
		for (int j = 0; j < n; j++) {
			if (r[i] <= r[j] || used[j] == true)continue;
			long long E = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			if (E <= (r[i] - r[j])*(r[i] - r[j])) {
				X[i].push_back(j); res[j]++; used[j] = true;
			}
		}
	}
	long long P = 0;
	for (int i = 0; i < n; i++) {
		if (res[i] >= 1)continue;
		P += dfs(i, 0, 0);
	}
	printf("%.20Lf\n", 3.14159265358979323846264L*P);
	return 0;
}