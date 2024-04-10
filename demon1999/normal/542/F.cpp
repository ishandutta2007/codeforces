#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 2 * 16 * 1024;

int n, t, dp[102][1001];
vector<int> q[101];

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> t;
	forn (i, n) {
		int a, b;
		cin >> a >> b;
		q[t - a].push_back(b);
	}
	forn (i, t + 1) {
		sort(q[i].begin(), q[i].end());
		reverse(q[i].begin(), q[i].end());
		/*for (int v : q[i])
			cout << v << " ";
		cout << "\n";*/
	}
	//exit(0);
	forn (i, 102)
		forn (j, 1001)
			dp[i][j] = -10000000;
	dp[0][0] = dp[0][1] = 0;
	for (int j = 0; j <= t; j++) {
		for (int k = 0; k <= n; k++) {
			int sm = 0;
			for (int p = 0; p <= min(k, sz(q[j])); p++) {
				dp[j + 1][min(2 * (k - p), n)] = max(dp[j + 1][min(2 * (k - p), n)], dp[j][k] + sm);
				if (p < sz(q[j]))
					sm += q[j][p];
				//cout << dp[j][k] + sm << " ";
			}
			//cout << dp[j][k] << " ";
		}
		//cout << "\n";
	}
	int ans = 0;
	for (int j = 0; j <= t + 1; j++) {
		forn (p, n + 1)
			ans = max(ans, dp[j][p]);
	}
	cout << ans;
}