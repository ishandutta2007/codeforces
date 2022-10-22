#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i < n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e5 + 111;
const ll INF = 3 * 1e16;

ll x, y;;
ll ax, bx;
ll ay, by;
ll xs, ys, t;

vector <pair<ll,ll>> pt;

int main() {
	boost;
	cin >> x >> y >> ax >> bx >> ay >> by >> xs >> ys >> t;
	pt.pb({x, y});
	while(pt.back().fi < INF && pt.back().se < INF) {
		ll X = pt.back().fi * ax + ay;
		ll Y = pt.back().se * bx + by;
		//cout << X << " x " << Y << endl;
		pt.pb({X, Y});
	}
	ll best = 0;
	for (int i = 0; i < ss(pt); ++i) {
		ll mam = 0;
		ll xx = xs;
		ll yy = ys;
		ll T = t;
		for (int j = i; 0 <= j; --j) {
			T -= abs(xx - pt[j].fi) + abs(yy - pt[j].se);
			if(T < 0) break;
			mam++;
			xx = pt[j].fi;
			yy = pt[j].se;
		}
		best = max(best, mam);
		mam = 0;
		xx = xs;
		yy = ys;
		T = t;
		for (int j = i; j < ss(pt); ++j) {
			T -= abs(xx - pt[j].fi) + abs(yy - pt[j].se);
			if(T < 0) break;
			mam++;
			xx = pt[j].fi;
			yy = pt[j].se;
		}
		best = max(best, mam);
	}
	printf("%lld", best);
	
	return 0;
}