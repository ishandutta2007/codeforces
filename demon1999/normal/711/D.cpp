#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) mp(mp(a, b), mp(c, d))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = ll(1e9) + 7, mod = inf;

ll n, m, k, use[300000], a[300000], uu[300000], st[300000], cc, ans = 1LL;
vector<ll> cycle;
vector<pair<ll, ll> > e[300000];

void dfs(int nu, int k, int pr) {
	use[nu] = k;
	for (auto v : e[nu]) {
		if (use[v.fi]) {
			if (uu[v.fi] || v.se == pr) continue;
			ll len = use[nu] - use[v.fi] + 1LL;
			cc -= len;
			ans = (ans * (st[len] + inf - 2LL)) % inf;
		}
		else {
			dfs(v.fi, k + 1, v.se);
		}
	}
	uu[nu] = 2;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	st[0] = 1;
	cc = n;
	forn (i, n) {
		st[i + 1] = (st[i] * 2LL) % mod;
		cin >> a[i];
		a[i]--;
		e[i].push_back(mp(a[i], i));
		e[a[i]].push_back(mp(i, i));
	}
	forn (i, n) {
		if (!use[i]) {
			dfs(i, 1, -1);
		}
	}
	ans = (ans * st[cc]) % mod;
	cout << ans;
	re 0;
}