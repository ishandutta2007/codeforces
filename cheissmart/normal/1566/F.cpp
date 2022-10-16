#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;
const ll oo = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(ALL(a));

	V<pi> b(m);
	for(int i = 0; i < m; i++)
		cin >> b[i].F >> b[i].S;

	auto remove_good = [&] () -> V<pi> {
		V<array<int, 3>> c;
		for(int i = 0; i < m; i++)
			c.PB({b[i].F, b[i].S, 1});
		for(int i = 0; i < n; i++)
			c.PB({a[i], a[i], 0});
		sort(ALL(c), [&] (array<int, 3> x, array<int, 3> y) {
			x[1] *= -1, x[2] *= -1;
			y[1] *= -1, y[2] *= -1;
			return x < y;
		});
		int mnr = INF;
		V<pi> ans;
		for(int i = int(c.size()) - 1; i >= 0; i--) {
			if(mnr > c[i][1]) {
				if(c[i][2] == 1) {
					ans.EB(c[i][0], c[i][1]);
				}				
			}
			mnr = min(mnr, c[i][1]);
		}
		return ans;
	};

	b = remove_good();
	m = int(b.size());
	sort(ALL(b));
	for(int i = 1; i < m; i++)
		assert(b[i - 1].F < b[i].F && b[i - 1].S < b[i].S);
	V<V<pi>> aux;
	{
		int j = 0;
		for(int i = 0; i < n; i++) {
			V<pi> tt;
			while(j < m && b[j].S < a[i])
				tt.PB(b[j++]);
			aux.PB(tt);
		}
		V<pi> tt;
		while(j < m)
			tt.PB(b[j++]);
		aux.PB(tt);
	}
	assert(int(aux.size()) == n + 1);

	auto trans = [&] (V<ll> dp, int x, V<pi> l, V<pi> r) -> V<ll> {
		assert(int(dp.size()) == int(l.size()) + 1);
		V<ll> ndp(int(r.size() + 1), oo);
		V<pair<ll, ll>> aux;
		ll mn = oo;
		for(int i = 0; i < int(dp.size()); i++) {
			ll distl = 0;
			if(i < int(l.size()))
				distl = x - l[i].S;
			assert(distl >= 0);
			mn = min(mn, distl + dp[i]);
			aux.EB(distl, dp[i] + distl * 2);
		}
		ll mn2 = oo;
		for(int i = 0; i < int(ndp.size()); i++) {
			ll distr = 0;
			if(i)
				distr = r[i - 1].F - x;
			assert(distr >= 0);
			ndp[i] = min(ndp[i], mn + distr * 2);
			while(aux.size() && aux.back().F <= distr) {
				mn2 = min(mn2, aux.back().S);
				aux.pop_back();
			}
			ndp[i] = min(ndp[i], mn2 + distr);
		}
		return ndp;
	};

	V<ll> dp(aux[0].size() + 1, oo);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		dp = trans(dp, a[i], aux[i], aux[i + 1]);
	}
	cout << dp.back() << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}