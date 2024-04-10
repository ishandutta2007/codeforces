#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n, m, k, use[N];
vector<int> e[N];
vector<int> num;

bitset<500> go[2][61][500];
ll dp[60][500][2];

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &m);
	forn (i, m) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		x--;
		y--;
		go[t][0][x][y] = 1;
		dp[0][x][t] = 1;
		//e[x].push_back(mp(y, t));
	}
	//exit(0);
	for (int j = 1; j <= 60; j++) {
		forn (i, n) {
			forn (k, n) {
				if (go[0][j - 1][i][k])
					go[0][j][i] |= go[1][j - 1][k];
				if (go[1][j - 1][i][k])
					go[1][j][i] |= go[0][j - 1][k];
			}
		}
	}
	forn (i, n) {
		forn (j, n) {
			if (go[0][60][i][j]) {
				printf("-1\n");
				re 0;
			}
		}
	}
	//exit(0);
	ll ans = 0;
	for (int i = 1; i < 60; i++) {
		forn (v, n) {
			dp[i][v][0] = dp[i - 1][v][0];
			dp[i][v][1] = dp[i - 1][v][1];
			forn (x, n) {
				if (go[0][i][v][x])
					dp[i][v][0] = max(dp[i][v][0], (1LL << ll(i)) + dp[i - 1][x][1]);
				if (go[1][i][v][x])
					dp[i][v][1] = max(dp[i][v][1], (1LL << ll(i)) + dp[i - 1][x][0]);
			}
		}
	}
	forn (i, 60)
	forn (v, n)
		ans = max(ans, dp[i][v][0]);
	if (ans > ll(1e18))
		printf("-1\n");
	else
		cout << ans;
		//printf("%lld\n", ans);
}