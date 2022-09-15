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
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
const int maxk = 40 + 1;
int n, m;
int k[maxn];
int a[maxn][maxk];
vector<pair<int, pi> > g[maxn];
vector<int> dvs[maxk];
map<int, int> hs[maxk];

void clear() {
	FOR(i, 0, maxk) hs[i].clear();
}
void add(int k, int r) {
	FOR(i, 0, sz(dvs[k])) {
		int d = dvs[k][i];
		hs[d][r % d]++;
	}
}
void rem(int k, int r) {
	FOR(i, 0, sz(dvs[k])) {
		int d = dvs[k][i];
		if (!(--hs[d][r % d])) {
			hs[d].erase(r % d);
		}
	}
}
int check() {
	FOR(i, 0, maxk) {
		if (sz(hs[i]) > 1) {
			return 0;
		}
	}
	return 1;
}

int solve(vector<pair<int, pi> > v) {
	clear();
	int res = 0, ptr = 0, st = -1;
	FOR(i, 0, sz(v)) {
		int ix = v[i].fi;
		int k = v[i].se.fi;
		int r = v[i].se.se;
		if (ix != st + 1) {
			ptr = i;
			clear();
		}
		st = ix;
		add(k, r);
		while (!check()) {
			rem(v[ptr].se.fi, v[ptr].se.se);
			ptr++;
		}
		chkmax(res, i - ptr + 1);
	}
	return res;
}

void solve() {
	FOR(i, 1, maxk) {
		for (int j = i; j < maxk; j += i) {
			dvs[j].pb(i);
		}
	}
	cin >> n >> m;
	FOR(i, 0, n) {
		cin >> k[i];
		FOR(j, 0, k[i]) {
			int x; cin >> x;
			g[x].pb(mp(i, mp(k[i], j)));
		}
	}
	FOR(i, 1, m + 1) {
		cout << solve(g[i]) << "\n";
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