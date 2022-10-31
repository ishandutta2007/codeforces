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

ll n, m;
vector<ll> a, b;

ll ans = 0;

bool ok(ll k) {
	int i = 0, j = 0;
	forn (kk, m) {
		while (i < sz(a) && a[i] + k < b[kk])
			i++;
		while (j < sz(a) && a[j] - k <= b[kk])
			j++;
		if (i == j)
			re false;
	}
	re true;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> m >> n;
	a.resize(n);
	b.resize(m);
	forn (j, m)
		cin >> b[j];
	sort(b.begin(), b.end());
	forn (i, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll lans = -1, rans = 2LL * 1000LL * 1000LL * 1000LL + 10LL;
	while (rans - lans > 1) {
		ll mid = (lans + rans) / 2;
		if (ok(mid))
			rans = mid;
		else
			lans = mid;
	}
	cout << rans;
 	re 0;
}