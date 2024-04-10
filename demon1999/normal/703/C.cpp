#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define fi first
#define se second

const ld inf = 1000. * 1000. * 1000. - 1;
ll n, w, u, v;

vector<pair<ll, ll> > a; 
vector<pair<pll, pll> > c;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> w >> v >> u;
	a.resize(n);
	forn (i, n) {
		cin >> a[i].se >> a[i].fi;
	}
	forn (i, n) {
		if (a[i].fi != a[(i + 1) % n].fi) 
			c.push_back(mp(min(a[i], a[(i + 1) % n]), max(a[i], a[(i + 1) % n])));
	}
	sort(c.begin(), c.end());
	vector<pair<ll, pld> > cc;
	pair<pll, pll> mx = {mp(-inf, -inf), mp(-inf, -inf)};
	forn (i, sz(c)) {
		if (c[i].fi.fi >= mx.fi.fi && c[i].fi.fi < mx.se.fi) {
			//cout << mx.fi.fi << " " << mx.se.fi << " " << c[i].fi.fi << endl;
			ld xx = ld(mx.se.se - mx.fi.se) / ld(mx.se.fi - mx.fi.fi), xr = c[i].fi.se;
			xx *= ld(c[i].fi.fi - mx.fi.fi);
			xx += mx.fi.se;
			//cout << xx << endl;
			cc.push_back(mp(c[i].fi.fi, mp(min(xx, xr), max(xx, xr))));
		}
		if (c[i].se.fi > mx.se.fi)
			mx = c[i];
	}
	pld lans = {0, 0}, rans = {0, 0};
	ld cq = 0;
	const ld eps = 1e-9;
	forn (i, sz(cc)) {
		lans.se += (ld(cc[i].fi) - cq) / ld(u);
		rans.se += (ld(cc[i].fi) - cq) / ld(u);
		if (cc[i].se.se - ld(v) * rans.se > -eps) {
			rans.se = cc[i].se.se / ld(v);
		}
		//cout << cc[i].fi << " " << cc[i].se.fi << " " << cc[i].se.se << endl;
		if (cc[i].se.fi - ld(v) * lans.se < -eps && cc[i].se.se > eps) {
			lans = rans;
		}
		cq = cc[i].fi;
		//cout << lans.se << "\n";
	}
	lans.se += (ld(w) - cq) / ld(u);
	cout.precision(30);
	cout << fixed << lans.se;
	re 0;
}