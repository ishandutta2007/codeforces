#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, m, t;
int dp[5000][5000];
vector<pii> e[5000], g[5000];

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m >> t;
	forn (i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		e[a].push_back(mp(b, c));
		g[b].push_back(mp(a, c));
	}
	forn (i, n)
		forn (j, n)
			dp[i][j] = t + 1;
	dp[0][0] = 0;
	for (int i = 0; i + 1 < n; i++) {
		forn (j, n)
			if (dp[i][j] <= t)
				for (auto v : e[j])
					dp[i + 1][v.fi] = min(dp[i + 1][v.fi], dp[i][j] + v.se);
	}
	int num = 0;
	for (int j = n - 1; j >= 0; j--)
		if (dp[j][n - 1] <= t) {
			num = j;
			break;
		}
	vector<int> a;
	int nu = n - 1;
	for (int i = num; i > 0; i--) {
		a.push_back(nu + 1);
		for (auto v : g[nu]) {
			if (dp[i - 1][v.fi] + v.se == dp[i][nu]) {
				nu = v.fi;
				break;
			}
		}
	}
	a.push_back(1);
	cout << sz(a) << "\n";
	forn (i, sz(a))
		cout << a[int(sz(a)) - i - 1] << " ";
	re 0;
}