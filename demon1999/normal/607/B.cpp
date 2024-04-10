#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

int n, dp[501][501];
vector<int> a;

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	for (int len = 1; len <= n; len++)
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			
			dp[i][j] = 1e9;
			for (int pos = i; pos < j; pos++) {
				dp[i][j] = min(dp[i][j], dp[i][pos] + dp[pos + 1][j]);
			}
			if (a[i] == a[j]) {
				if (i + 1 <= j - 1)
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
				else
					dp[i][j] = 1;
			}
		}
	cout << dp[0][n - 1] << "\n";
}