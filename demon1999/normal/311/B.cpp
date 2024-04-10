#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, ma = 1024 * 128;

ll n, m, p, h, t, ans, dp[101][100001];
vector<ll> a, d, sum;


int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> n >> m >> p;
	d.resize(n);
	d[0] = 0;
	forn (i, n - 1) {
		cin >> d[i + 1];
		d[i + 1] += d[i];
	}
	forn (j, m) {
		cin >> h >> t;
		h--;
		t -= d[h];
		//if (t < 0) ans += -t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	sum.resize(m);
	sum[0] = a[0];
	for (ll i = 1; i < m; i++)
		sum[i] = sum[i - 1] + a[i];
	/*forn (i, m)
		cout << a[i] << " ";
	cout << endl;*/
	forn (i, m) {
		dp[0][i] = (i + 1LL) * a[i] - sum[i];
		//cout << dp[0][i] << " ";
	}
	//cout << endl;
	for (ll i = 1; i < p; i++) {
		deque<pair<ll, ll> > aa;
		dp[i][0] = dp[i - 1][0];
		aa.push_back(mp(dp[i - 1][0] + sum[0], -1));
		//cout << dp[i][0] << " ";
		for (ll j = 1; j < m; j++) {
			while (!aa.empty()) {
				pll q = aa.front();
				aa.pop_front();
				if (aa.empty()) {
					aa.push_front(q);
					break;
				}
				if (q.fi + q.se * a[j] >= aa.front().fi + aa.front().se * a[j]) continue;
				aa.push_front(q);
				break;
			}
			dp[i][j] = min(aa.front().fi + aa.front().se * a[j] - sum[j] + a[j] * (j + 1), dp[i - 1][j]);
			pll cc = mp(dp[i - 1][j] + sum[j], -j - 1);
			while (!aa.empty()) {
				pll q = aa.back();
				aa.pop_back();
				if (aa.empty()) {
					aa.push_back(q);
					break;
				}
				pll c = aa.back();
				ll x = q.fi - c.fi, y = c.se - q.se;
				ll xx = cc.fi - q.fi, yy = q.se - cc.se;
				if (x * yy >= xx * y) {
					continue;
				}
				aa.push_back(q);
				break;
			}
			aa.push_back(cc);
		}
		//cout << endl;
	}
	cout << ans + dp[p - 1][m - 1];
	re 0;
}