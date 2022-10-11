#include<iostream>
#include<vector>
using namespace std;
int n, r, c[500], dp[505][505];
int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++)cin >> c[i]; dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = r; j >= 0; j--) {
			for (int k = r; k >= 0; k--) {
				if (j >= c[i] && dp[j - c[i]][k] == 1)dp[j][k] = 1;
				if (k >= c[i] && dp[j][k - c[i]] == 1)dp[j][k] = 1;
			}
		}
	}
	vector<int>C; for (int i = 0; i <= r; i++) { if (dp[i][r - i] == 1)C.push_back(i); }
	cout << C.size() << endl;
	for (int i = 0; i < C.size(); i++) { if (i)cout << ' '; cout << C[i]; }cout << endl;
	return 0;
}