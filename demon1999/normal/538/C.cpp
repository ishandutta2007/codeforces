#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024;

int n, m;
vector<pair<int, int> > d;

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> m;
	d.resize(m);
	forn (i, m) {
		cin >> d[i].fi >> d[i].se;
	}
	sort(d.begin(), d.end());
	ll ans = d[0].se + d[0].fi - 1;

	forn (i, m - 1) {
		if (abs(d[i].se - d[i + 1].se) > d[i + 1].fi - d[i].fi) {
			cout << "IMPOSSIBLE\n";
			re 0;
		}
		ll mc = max(d[i].se, d[i + 1].se) + (d[i + 1].fi - d[i].fi - abs(d[i].se - d[i + 1].se)) / 2LL;
		ans = max(ans, mc);
	}
	ans = max(ans, ll(d[m - 1].se + n - d[m - 1].fi));
	cout << ans;
}