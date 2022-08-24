#include <bits/stdc++.h>
#define long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int dp[5007][5007];

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = -1e9;
			if (s[i] == t[j]) dp[i][j] = 2;
		}
	}

	for (int j = m-1; j >= 0; --j) {
		int res = -1e9;

		vector<int> nxt(26, -1);
		for (int e = m-1; e > j; --e) nxt[t[e] - 'a'] = e;

		for (int i = n-1; i >= 0; --i) {

			res--;
			if (s[i] == t[j]) {
				dp[i][j] = max(dp[i][j], res + 2);
			}

			int N = nxt[s[i] - 'a'];
			if (N != -1) {
				res = max(res, dp[i][N] - (N - j - 1) + 1);
			}

		}

	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//cout << i << " " << j << " " << dp[i][j] << endl;
			ans = max(ans, dp[i][j]);
		}
	}	

	cout << ans;


}