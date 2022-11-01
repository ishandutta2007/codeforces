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

ll n, m, p, h, t, ans, dp[100001];
vector<ll> a, b, sum, sum1;


int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> n;
	a.resize(n);
	b.resize(n);
	forn (j, n) {
		cin >> a[j];
	}
	forn (j, n)
		cin >> b[j];
	m = n;
	deque<pair<ll, ll> > aa;
	aa.push_back(mp(0, b[0]));
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
		dp[j] = min(aa.front().fi + aa.front().se * a[j], inf * inf);
		pll cc = mp(dp[j], b[j]);
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
			ld pp = ld(x) / ld(y), pp1 = ld(xx) / ld(yy);
			if (pp >= pp1) continue;
			aa.push_back(q);
			break;
		}
		aa.push_back(cc);
	}
	cout << dp[m - 1];
	re 0;
}