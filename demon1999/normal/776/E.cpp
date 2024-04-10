#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 256 * 1024;

ll n, k;

vector<pair<ll, ll> > qq, new_qq, j;
map<ll, vector<pair<ll, ll> > > pq;

void make_(ll n) {
	vector<pair<ll, ll> > qq;
	ll c = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			qq.push_back(mp(i, 0));
			while (n % i == 0) {
				qq[sz(qq) - 1].se++;
				n /= i;
			}
		}
	}
	if (n > 1)
		qq.push_back(mp(n, 1));
	pq[c] = qq;
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> k;
	k--;
	ll p = 1 + k / 2LL;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			qq.push_back(mp(i, 0));
			while (n % i == 0) {
				qq[sz(qq) - 1].se++;
				n /= i;
			}
		}
	}
	if (n > 1)
		qq.push_back(mp(n, 1));
	for (ll rj = 0; rj < p; rj++) {
		if (qq.empty()) break;
		new_qq.resize(0);
		forn (i, sz(qq)) {
			if (qq[i].se > 1)
				new_qq.push_back(mp(qq[i].fi, qq[i].se - 1));
			if (pq.find(qq[i].fi - 1LL) == pq.end()) {
				make_(qq[i].fi - 1LL);
			}
			j = pq[qq[i].fi - 1LL];
			for (auto v : j)
				new_qq.push_back(v);
		}
		qq.resize(0);
		sort(new_qq.begin(), new_qq.end());
		forn (i, sz(new_qq)) {
			if (sz(qq) == 0 || qq[sz(qq) - 1].fi != new_qq[i].fi)
				qq.push_back(new_qq[i]);
			else
				qq[sz(qq) - 1].se += new_qq[i].se;
		}
	}
	ll ans = 1;
	forn (i, sz(qq)) {
		forn (j, qq[i].se)
			ans *= qq[i].fi;
	}
	cout << (ans % ll(1000000007));
}