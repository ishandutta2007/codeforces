#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100010;
const ll oo = (ll) 8 * 1e18;
int n;
ll x[maxn];
ll y[maxn];
ll z[maxn];
ll dmin[4];
ll dmax[4];

pair<pair<ll, ll>, ll> getanseven() {
	pair<pair<ll, ll>, ll> res = mp(mp(-oo, -oo), -oo);
	ll x[4], y[4];
	FOR(i, 0, 4) {
		x[i] = dmin[i];
		y[i] = dmax[i];
		if (x[i] % 2 != 0) x[i]++;
		if (y[i] % 2 != 0) y[i]--;
	}
	FOR(i, 0, 4) {
		if (x[i] > y[i]) {
			return res;
		}
	}
	ll totmin = 0, totmax = 0;
	FOR(i, 0, 3) {
		totmin += x[i];
		totmax += y[i];
	}
	if (totmin > y[3]) {
		return res;
	}
	if (totmax < x[3]) {
		return res;
	}
	res.fi.fi = x[0];
	res.fi.se = x[1];
	res.se = x[2];
	if (totmin >= x[3]) {
		return res;
	}
	for (int i = 0; i < 3; i++) {
		ll t = min(x[3] - totmin, y[i] - x[i]);
		totmin += t;
		if (!i) {
			res.fi.fi += t;
		}
		else if (i == 1) {
			res.fi.se += t;
		}
		else {
			res.se += t;
		}
	}
	return res;
}

pair<pair<ll, ll>, ll> getansodd() {
	pair<pair<ll, ll>, ll> res = mp(mp(-oo, -oo), -oo);
	ll x[4], y[4];
	FOR(i, 0, 4) {
		x[i] = dmin[i];
		y[i] = dmax[i];
		if (x[i] % 2 == 0) x[i]++;
		if (y[i] % 2 == 0) y[i]--;
	}
	FOR(i, 0, 4) {
		if (x[i] > y[i]) {
			return res;
		}
	}
	ll totmin = 0, totmax = 0;
	FOR(i, 0, 3) {
		totmin += x[i];
		totmax += y[i];
	}
	if (totmin > y[3]) {
		return res;
	}
	if (totmax < x[3]) {
		return res;
	}
	res.fi.fi = x[0];
	res.fi.se = x[1];
	res.se = x[2];
	if (x[3] <= totmin) {
		return res;
	}
	for (int i = 0; i < 3; i++) {
		ll t = min(x[3] - totmin, y[i] - x[i]);
		totmin += t;
		if (!i) {
			res.fi.fi += t;
		}
		else if (i == 1) {
			res.fi.se += t;
		}
		else {
			res.se += t;
		}
	}
	return res;
}

int check(ll m) {
	FOR(i, 0, 4) dmin[i] = -oo, dmax[i] = +oo;
	FOR(i, 0, n) {
		chkmax(dmin[0], x[i] + y[i] - z[i] - m);
		chkmax(dmin[1], x[i] - y[i] + z[i] - m);
		chkmax(dmin[2], y[i] + z[i] - x[i] - m);
		chkmax(dmin[3], x[i] + y[i] + z[i] - m);
		chkmin(dmax[0], x[i] + y[i] - z[i] + m);
		chkmin(dmax[1], x[i] - y[i] + z[i] + m);
		chkmin(dmax[2], y[i] + z[i] - x[i] + m);
		chkmin(dmax[3], x[i] + y[i] + z[i] + m);
	}
	FOR(i, 0, 4) if (dmax[i] < dmin[i]) return 0;
	if (getanseven().fi.fi == -oo && getansodd().fi.fi == -oo) {
		return 0;
	}
	return 1;
}

void getans(ll m) {
	FOR(i, 0, 4) dmin[i] = -oo, dmax[i] = +oo;
	FOR(i, 0, n) {
		chkmax(dmin[0], x[i] + y[i] - z[i] - m);
		chkmax(dmin[1], x[i] - y[i] + z[i] - m);
		chkmax(dmin[2], y[i] + z[i] - x[i] - m);
		chkmax(dmin[3], x[i] + y[i] + z[i] - m);
		chkmin(dmax[0], x[i] + y[i] - z[i] + m);
		chkmin(dmax[1], x[i] - y[i] + z[i] + m);
		chkmin(dmax[2], y[i] + z[i] - x[i] + m);
		chkmin(dmax[3], x[i] + y[i] + z[i] + m);
	}
	pair<pair<ll, ll>, ll> res = getanseven();
	if (res.fi.fi != -oo) {
		ll a = res.fi.fi;
		ll b = res.fi.se;
		ll c = res.se;
		cout<<(a + b) / 2<<" "<<(c + a) / 2<<" "<<(b + c) / 2<<"\n";
		return;
	}
	res = getansodd();
	if (res.fi.fi != -oo) {
		ll a = res.fi.fi;
		ll b = res.fi.se;
		ll c = res.se;
		cout<<(a + b) / 2<<" "<<(c + a) / 2<<" "<<(b + c) / 2<<"\n";
		return;
	}
}

void solve() {
	int T; cin>>T;
	while (T--) {
		cin>>n;
		FOR(i, 0, n) cin>>x[i]>>y[i]>>z[i];
		ll l = 0, r = 4 * LINF;
		while (l < r) {
			ll m = l + r >> 1;
			if (!check(m)) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		getans(l);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}