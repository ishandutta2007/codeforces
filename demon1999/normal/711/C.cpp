#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = ll(1e9) * ll(1e9);

ll n, m, k, col[101], pq[101][101], dp[101][101][101];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m >> k;
	forn (i, n) cin >> col[i];
	forn (i, n)
		forn (j, m)
			cin >> pq[i][j];
	forn (i, m)
		forn (j, k)
			dp[0][i][j] = inf; 
	if (col[0] == 0)
		forn (i, m)
			dp[0][i][0] = pq[0][i];
	else
		dp[0][col[0] - 1][0] = 0;
	for(int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int p = 0; p < k; p++) {
				dp[i][j][p] = inf;
				if (col[i] == 0) {
					dp[i][j][p] = dp[i - 1][j][p];
					if (p)
						forn (cl, m)
							if (cl != j)
								dp[i][j][p] = min(dp[i][j][p], dp[i - 1][cl][p - 1]);
					dp[i][j][p] += pq[i][j];
				}
				else {
					if (col[i] - 1 != j) continue;
					dp[i][j][p] = dp[i - 1][j][p];
					if (p)
						forn (cl, m)
							if (cl != j)
								dp[i][j][p] = min(dp[i][j][p], dp[i - 1][cl][p - 1]);
				}
				//cout << dp[i][j][p] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
	} 
	ll ans = inf;
	forn (cl, m)
		ans = min(ans, dp[n - 1][cl][k - 1]);
	if (ans == inf) cout << "-1";
	else
		cout << ans;
	re 0;
}