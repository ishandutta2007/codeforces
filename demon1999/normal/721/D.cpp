#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll n, k, x, ans[1000000];
vector<pair<ll, ll> > qq; 

void sh(int p) {
	set<pair<ll, ll> > as;
	ll mi = k + 1;;
	forn (i, sz(qq)) {
		ans[i] = qq[i].fi;
		as.insert(mp(abs(ans[i]), i));
	}
	forn (i, k) {
		if (p == 0) {
			pll qq = (*as.begin());
			as.erase(as.begin());
			if (ans[qq.se] < 0)
				ans[qq.se] -= x;
			else ans[qq.se] += x;
			as.insert(mp(abs(ans[qq.se]), qq.se));
		}
		else {
			auto it = as.begin();
			pll qq = (*it);
			as.erase(it);
			if (ans[qq.se] < 0) {
				ans[qq.se] += x;
			}
			else {
				ans[qq.se] -= x;
			}
			as.insert(mp(abs(ans[qq.se]), qq.se));
		}
	}
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> k >> x;
	ll cc = 0, cq = 0;
	qq.resize(n);
	forn (i, n) {
		cin >> qq[i].fi;
		ans[i] = qq[i].fi;
		qq[i].se = i;
		if (qq[i].fi < 0) {
			cc++;
		}	
		if (qq[i].fi == 0)
			cq++;
	}
	if (cq <= k) {
		k -= cq;
		forn (i, n) {
			if (qq[i].fi == 0) {
				if (cc % 2 == 0) {
					cc++;
					qq[i].fi = -x;
				}
				else
					qq[i].fi = x;
			}
		}
		if (cc % 2 == 0) {
			//cout << "Hay\n";
			ll p = 0;
			forn (i, n) {
				if (abs(qq[p].fi) > abs(qq[i].fi))
					p = i;
			}
			if (k >= (abs(qq[p].fi) + x) / x) {
				ll kk = (abs(qq[p].fi) + x) / x;
				k -= kk;
				//cout << kk << abs(qq[p].fi) + x << endl;
				if (qq[p].fi < 0)
					qq[p].fi += kk * x;
				else
					qq[p].fi -= kk * x;
				//cout << "HUY\n";
				//cout << qq[p].fi << endl;
				sh(0);
			}
			else {
				sh(1);
			}
		}
		else
			sh(0);
	}
	forn (i, n)
		cout << ans[i] << " ";
	re 0;
}