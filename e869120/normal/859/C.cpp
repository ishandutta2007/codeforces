#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;
int n, a[100009], dp[100009][2], s;
int dfs(int pos, int dec) {
	if (dp[pos][dec] >= 1)return dp[pos][dec] - 1;
	if (pos == n)return 0;
	if (dec == 0) {
		dp[pos][dec] = max(dfs(pos + 1, dec ^ 1) + a[pos], dfs(pos + 1, dec));
	}
	if (dec == 1) {
		dp[pos][dec] = min(dfs(pos + 1, dec ^ 1), dfs(pos + 1, dec) + a[pos]);
	}
	dp[pos][dec]++;
	return dp[pos][dec] - 1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; s += a[i]; }
	int G = dfs(0, 0);
	cout << s - G << " " << G << endl;
	return 0;
}