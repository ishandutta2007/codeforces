//#include "grader.h"
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
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const ll mod = ll(1e9) + 7;
int n, m;
ll ans[100000], ansk[100000];
vector<pair<int, ll> > e[100000];
vector<pair<int, int> > qq[100000];
string s;

int main() {
	//iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	forn (i, m) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		a--;
		b--;
		e[a].push_back(mp(b, w));
		e[b].push_back(mp(a, w));
	}
	forn (i, n) {
		int k;
		scanf("%d", &k);
		int ltm = 0;
		forn (j, k) {
			int q;
			scanf("%d", &q);
			if (ltm <= q - 1) {
				qq[i].push_back(mp(ltm, q - 1));
			}
			ltm = q + 1;
		}
		qq[i].push_back(mp(ltm, int(2e9)));
		ans[i] = ll(2e9) + 100LL;
		ansk[i] = ll(2e9) + 100LL;
	}
	set<pair<ll, int> > dej;
	ans[0] = qq[0][0].fi;
	ansk[0] = 0;
	forn (i, n) {
		dej.insert(mp(ans[i], i));
	}
	while (!dej.empty() && (dej.begin()->fi) < ll(2e9)) {
		int nu = (dej.begin()->se);
		dej.erase(dej.begin());
		for (auto v : e[nu]) {
			int tm = ans[nu] + v.se;
			ansk[v.fi] = min(ansk[v.fi], ll(tm));
			ll ik = upper_bound(qq[v.fi].begin(), qq[v.fi].end(), mp(tm, int(2e9) + 1)) - qq[v.fi].begin();
			if (ik == 0 || qq[v.fi][ik - 1].se < tm)
				tm = qq[v.fi][ik].fi;
			if (ans[v.fi] > tm) {
				dej.erase(mp(ans[v.fi], v.fi));
				ans[v.fi] = tm;
				dej.insert(mp(ans[v.fi], v.fi));
			}
		}
	}
	if (ansk[n - 1] == ll(2e9) + 100LL)
		cout << -1;
	else
		cout << ansk[n - 1];
}