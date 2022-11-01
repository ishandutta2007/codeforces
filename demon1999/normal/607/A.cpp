#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

int n, dp[2][100001];
vector<pair<int, int> > a;
vector<int> b;

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	a.resize(n);
	forn (i, n) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a.begin(), a.end());
	forn (i, n)
		b.push_back(a[i].fi);
	int ans = 0;
	forn (i, n) {
		int k = lower_bound(b.begin(), b.end(), a[i].fi - a[i].se) - b.begin();
		//cout << k << "\n";
		dp[0][i + 1] = dp[0][k] + 1;
		ans = max(ans, dp[0][i + 1]);
		dp[1][i + 1] = ans;
		
		//cout << dp[1][i + 1] << " " << dp[0][i + 1] << "\n"; 
	}
	cout << n - ans;
}