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

int n, m, k, h, w, mtm[2 * ma];
vector<pair<pair<int, int>, pair<int, int> > > a;

deque<pair<ll, int> > q[ma];

int get_min(int nu, int l, int r, int k, int c) {
	if (l + 1 == r) {
		if (nu - ma < k)
			re -1;
		re nu - ma;
	}
	if (r - ma <= k)
		re -1;
	int mid = (l + r) / 2, ans = -1;
	if (mtm[2 * nu] <= c)
		ans = get_min(2 * nu, l, mid, k, c);
	if (ans == -1)
		ans = get_min(2 * nu + 1, mid, r, k, c);
	re ans;
}

void add_(int nu, ll k, int tm) {
	int nk = nu + ma;
	mtm[nk] = tm;
	while (nk / 2) {
		nk /= 2;
		mtm[nk] = min(mtm[2 * nk], mtm[2 * nk + 1]);
	}
	q[nu].push_back(mp(k, tm));
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d%d", &h, &w, &n);
	a.resize(n);
	forn (i, n) {
		scanf("%d%d%d%d", &a[i].fi.fi, &a[i].se.fi, &a[i].se.se, &a[i].fi.se);
		a[i].fi.se = min(a[i].fi.fi + a[i].fi.se, h + 1);
		a[i].se.fi--;
	}
	forn (i, 2 * ma)
		mtm[i] = -1;
	forn (i, w) {
		q[i].push_back(mp(1, h + 1));
		mtm[i + ma] = h + 1;
	}
	//exit(0);
	for (int i = ma - 1; i; i--)
		mtm[i] = min(mtm[2 * i], mtm[2 * i + 1]);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll ans = w;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		int l = a[i].se.fi;
		while (true) {
			l = get_min(1, ma, 2 * ma, l, a[i].fi.se);
			// << l << " " << sum << "\n";
			//exit(0);
			if (l >= a[i].se.se)
				break;
			while (!q[l].empty() && q[l].back().se <= a[i].fi.se) {
				sum += q[l].back().fi;
				q[l].pop_back();
			}
			ll nt = ll(1e9) + 1000LL;
			if (!(q[l].empty()))
				nt = (q[l].back().se);
			int nu = l + ma;
			mtm[nu] = nt;
			while (nu / 2) {
				nu /= 2;
				mtm[nu] = min(mtm[2 * nu], mtm[2 * nu + 1]);
			}
			
			//exit(0);
			l++;
		}
		sum %= mod;
		ans = (ans + sum) % mod;
		if (a[i].se.fi) {
			add_(a[i].se.fi - 1, sum, a[i].fi.fi);
		} else {
			add_(a[i].se.se, sum, a[i].fi.fi);
		}
		if (a[i].se.se < w) {
			add_(a[i].se.se, sum, a[i].fi.fi);
		} else {
			add_(a[i].se.fi - 1, sum, a[i].fi.fi);
		}
		//cout << ans << '\n';
	}
	cout << ans;
}