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
int n, m, s;
int a[maxn];
int b[maxn];
int c[maxn];
vector<pair<int, int> > va;
vector<pair<int, int> > vb;
int d[maxn];
int ans[maxn];

int check(int mi) {
	fill_n(d, n, 0);
	set<pair<int, int> > st;
	int ptr = 0;
	long long tot = 0;
	FOR(i, 0, m) {
		while (ptr < n && vb[ptr].fi >= va[i].fi) {
			int idx = vb[ptr].se;
			st.insert(mp(c[idx], idx));
			ptr++;
		}
		if (!sz(st)) return 0;
		int u = st.begin()->se;
		tot += st.begin()->fi;
		st.erase(st.begin());
		ans[va[i].se] = u;
		if (++d[u] < mi) {
			st.insert(mp(0, u));
		}
	}
	return tot <= s;
}

void solve() {
	cin >> n >> m >> s;
	FOR(i, 0, m) cin >> a[i];
	FOR(i, 0, n) cin >> b[i];
	FOR(i, 0, n) cin >> c[i];
	FOR(i, 0, m) va.pb(mp(a[i], i));
	FOR(i, 0, n) vb.pb(mp(b[i], i));
	sort(all(va)); reverse(all(va));
	sort(all(vb)); reverse(all(vb));
	int lo = 0, hi = INF;
	while (lo < hi) {
		int mi = lo + hi >> 1;
		if (!check(mi)) lo = mi + 1; else hi = mi;
	}
	if (!check(lo)) cout << "NO\n";
	else {
		cout << "YES\n";
		FOR(i, 0, m) cout << ans[i] + 1 << " \n"[i == m - 1];
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