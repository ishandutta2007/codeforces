
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024, szz = 2 * ma;

ll n, c, dp[10001], p, s;
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//freopen("class.in", "r", stdin);
	//freopen("class.out", "w", stdout);
	cin >> n >> c;
	forn (i, n + 1) {
		dp[i] = 1e18;
	}
	vector<ll> ak, pk;
	ak.resize(n);
	forn (i, n) cin >> ak[i];
	pk.resize(n);
	forn (i, n) cin >> pk[i];
	dp[0] = 0;
	forn (i, n) {
		//cin >> p >> s;
		p = ak[i];
		s = pk[i];
		for (int i = n; i > 0; i--) {
			dp[i] = min(dp[i] + c * ll(i) + p, dp[i - 1] + s);
		}
		dp[0] += p; 
		// forn (i, n + 1)
		// 	cout << dp[i] << " ";
		// cout << "\n";
	}
	ll ans = dp[0];
	forn (i, n)
		ans = min(ans, dp[i + 1]);
	cout << ans;
}