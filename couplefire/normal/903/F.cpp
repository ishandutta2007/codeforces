#include <bits/stdc++.h>
using namespace std;
int dp[1111][4][1 << 12];
int main() {
	int n;
	cin >> n;
	vector<int> a(5);
	for (int i = 1; i <= 4; i++) {
		cin >> a[i];
	}
	vector<vector<int>> origin_map(n + 1);
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;		
		for (int j = 0; j < n; j++) {
			origin_map[j + 1].push_back(s[j] == '.');
		}
	}
	vector<int> state = {
		0, 
		bitset<12>("111111111110").to_ulong(), 
		bitset<12>("111111001100").to_ulong(), 
		bitset<12>("100010001000").to_ulong(),
	};
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < (1 << 12); i++) {
		dp[0][3][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < (1 << 12); k++) {
				for (int t = 1; t <= min(3, j + 1); t++) {
					dp[i][j][k] = min(dp[i][j][k], dp[i - (j == 0)][j - 1 + (j == 0) * 4][1 << 11 | (k & state[t]) >> 1] + a[t]);
				}
				if (origin_map[i][j] == 1 || (k & 1) == 0) {
					dp[i][j][k] = min(dp[i][j][k], dp[i - (j == 0)][j - 1 + (j == 0) * 4][1 << 11 | k >> 1]);
				}
				if (j == 3) {
					dp[i][j][k] = min(dp[i][j][k], dp[max(i - 4, 0)][j][(1 << 12) - 1] + a[4]);
				}
			}
		}
	}	
	cout << dp[n][3][(1 << 12) - 1] << endl;
	return 0;
}