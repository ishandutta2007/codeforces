#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int ma = 1024 * 1024 * 2;

int n, k, m, dp[100][100][101];
vector<pair<int, int> > e[100];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> k;
	cin >> m;
	forn (i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back(mp(b, c));
	}
	forn (i, n + 3)
		forn (j, n + 3)
			forn (kk, k + 2)
				dp[kk][i][j] = int(1e9);
	for (int i = 1; i <= n; i++) {
		dp[1][0][i] = 0;
		dp[1][n + 1][i] = 0;
	}
	//re 0;
	for (int kk = 1; kk < k; kk++) {
		for (int l = 0; l <= n + 1; l++)
			for (int r = 1; r < n + 1; r++)
				for (auto u : e[r]) {
					if (u.fi < max(l, r) && u.fi > min(l, r)) {
						dp[kk + 1][r][u.fi] = min(dp[kk + 1][r][u.fi], dp[kk][l][r] + u.se);
						dp[kk + 1][l][u.fi] = min(dp[kk + 1][l][u.fi], dp[kk][l][r] + u.se);
					}
				}
	}
	int ans = int(1e9);
	for (int l = 0; l <= n; l++)
		for (int r = 0; r <= n; r++)
			ans = min(ans, dp[k][l][r]);
		if (ans == int(1e9)) ans = -1;
	cout << ans << "\n";
	re 0;
}