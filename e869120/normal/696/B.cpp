#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int>x[100001]; int n, a[100001], dp1[100001]; double dp2[100001];
int dfs(int pos) {
	int ret = 0;
	for (int i = 0; i < x[pos].size(); i++)ret += dfs(x[pos][i]);
	dp1[pos] = ret + 1;
	return dp1[pos];
}
int main() {
	cin >> n; for (int i = 2; i <= n; i++) { cin >> a[i]; x[a[i]].push_back(i); }
	dfs(1); dp2[1] = 1;
	for (int i = 1; i <= n; i++) {
		int ret = 0; for (int j = 0; j < x[i].size(); j++)ret += dp1[x[i][j]];
		for (int j = 0; j < x[i].size(); j++) {
			dp2[x[i][j]] = dp2[i] + 1.0 + 0.5*(ret - dp1[x[i][j]]);
		}
	}
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; printf("%.1lf", dp2[i]); }cout << endl;
	return 0;
}