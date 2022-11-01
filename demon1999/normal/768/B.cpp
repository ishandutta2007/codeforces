#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int MAXN = 5 * 100 * 1000,/* ma = 128 * 1024,*/ mod = 1000 * 1000 * 1000 + 7;

ll n, l, r;
vector<pair<ll, ll> > a;

ll get_(ll n) {
	if (n < 2) {
		a.push_back(mp(n, 1LL));
		re 1;
	}
	ll k = 2LL * get_(n / 2LL) + 1LL;
	a.push_back(mp(n, k));
	re k;
}

ll get_element(ll n, ll pos, int ps1) {
	//cout << n << " " << pos << " " << ps1 << " " << a[ps1 - 1].se << "\n";
	if (ps1 == 0) {
		re a[ps1].fi;
	} 
	if (pos <= a[ps1 - 1].se) {
		re get_element(n / 2LL, pos, ps1 - 1);
	}
	if (pos == a[ps1 - 1].se + 1LL) {
		re n % 2LL;
	}
	get_element(n / 2LL, pos - a[ps1 - 1].se - 1LL, ps1 - 1); 
}
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> l >> r;
	get_(n);
	ll ans = 0;
//	forn (i, 15)
//		cout << get_element(n, i + 1, sz(a) - 1) << "\n";
	for (ll i = l; i <= r; i++) {
		ans += get_element(n, i, sz(a) - 1);
		//cout << get_element(n, i, sz(a) - 1) << " ";
	}
	cout << ans;
}