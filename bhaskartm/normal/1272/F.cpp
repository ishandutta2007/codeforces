#include <bits/stdc++.h>

using namespace std;

const int N = 202;
const int INF = 1e9;

int dp[N][N][2 * N];
pair<pair<int, int>, pair<int, char>> p[N][N][2 * N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int bal = 0; bal < 2 * N; ++bal) {
				dp[i][j][bal] = INF;
			}
		}
	}
	
	dp[0][0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int bal = 0; bal < 2 * N; ++bal) {
				if (dp[i][j][bal] == INF) continue;
				
				int nxti = i + (i < n && s[i] == '(');
				int nxtj = j + (j < m && t[j] == '(');
				if (bal + 1 < 2 * N && dp[nxti][nxtj][bal + 1] > dp[i][j][bal] + 1) {
					dp[nxti][nxtj][bal + 1] = dp[i][j][bal] + 1;
					p[nxti][nxtj][bal + 1] = make_pair(make_pair(i, j), make_pair(bal, '('));
				}
				
				nxti = i + (i < n && s[i] == ')');
				nxtj = j + (j < m && t[j] == ')');
				if (bal > 0 && dp[nxti][nxtj][bal - 1] > dp[i][j][bal] + 1) {
					dp[nxti][nxtj][bal - 1] = dp[i][j][bal] + 1;
					p[nxti][nxtj][bal - 1] = make_pair(make_pair(i, j), make_pair(bal, ')'));
				}
			}
		}
	}
	
	int ci = n, cj = m, cbal = 0;
	for (int bal = 0; bal < 2 * N; ++bal) {
		if (dp[n][m][bal] + bal < dp[n][m][cbal] + cbal) {
			cbal = bal;
		}
	}
	string res = string(cbal, ')');
	while (ci > 0 || cj > 0 || cbal != 0) {
		int nci = p[ci][cj][cbal].first.first;
		int ncj = p[ci][cj][cbal].first.second;
		int ncbal = p[ci][cj][cbal].second.first;
		res += p[ci][cj][cbal].second.second;
		ci = nci;
		cj = ncj;
		cbal = ncbal;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	
	return 0;
}