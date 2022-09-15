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

const int maxn = 1000000 + 10;
const int mod1 = 1000000007;
const int mod2 = 1004535809;
int n, k;
string s;
int g;
map<pi, int> hs;
int pr1 = 257;
int pw1[maxn];
int rp1[maxn];
int h1[maxn];
int pr2 = 2311;
int pw2[maxn];
int rp2[maxn];
int h2[maxn];
int f[maxn];

int query(int h[], int pw[], int rp[], int l, int r, int mod) {
	if (l <= r) {
		int res = h[r];
		if (l) submod(res, h[l - 1], mod);
		return mult(res, rp[l], mod);
	}
	else {
		int res = h[n * k - 1];
		if (l) submod(res, h[l - 1], mod);
		addmod(res, mult(pw[n * k], h[r], mod), mod);
		return mult(res, rp[l], mod);
	}
}

void work(int ix) {
	vi v;
	FOR(i, 0, n) {
		int l = (i * k + ix) % (n * k);
		int r = (i * k + k - 1 + ix) % (n * k);
		int x1 = query(h1, pw1, rp1, l, r, mod1);
		int x2 = query(h2, pw2, rp2, l, r, mod2);
		if (!hs[mp(x1, x2)]) {
			return;
		}
		v.pb(hs[mp(x1, x2)]);
	}
	int found = 0;
	FOR(i, 0, sz(v)) {
		int ix = v[i];
		if (f[ix]) {
			found = 1;
			break;
		}
		f[ix] = 1;
	}
	FOR(i, 0, sz(v)) {
		int ix = v[i];
		f[ix] = 0;
	}
	if (!found) {
		cout << "YES\n";
		FOR(i, 0, sz(v)) {
			cout << v[i] << " \n"[i == sz(v) - 1];
		}
		exit(0);
	}
}

void solve() {
	pw1[0] = 1; FOR(i, 1, maxn) pw1[i] = mult(pw1[i - 1], pr1);
	rp1[0] = 1; rp1[1] = inv(pr1); FOR(i, 1, maxn) rp1[i] = mult(rp1[i - 1], rp1[1]);
	pw2[0] = 1; FOR(i, 1, maxn) pw2[i] = mult(pw2[i - 1], pr2, mod2);
	rp2[0] = 1; rp2[1] = inv(pr2, mod2); FOR(i, 1, maxn) rp2[i] = mult(rp2[i - 1], rp2[1], mod2);
	cin >> n >> k >> s;
	int t1 = 0, t2 = 0;
	FOR(i, 0, n * k) {
		addmod(t1, mult(pw1[i], s[i], mod1), mod1);
		addmod(t2, mult(pw2[i], s[i], mod2), mod2);
		h1[i] = t1;
		h2[i] = t2;
	}
	cin >> g;
	FOR(i, 0, g) {
		string t; cin >> t;
		int h1 = 0, h2 = 0;
		FORd(j, sz(t), 0) {
			h1 = mult(h1, pr1, mod1);
			h2 = mult(h2, pr2, mod2);
			addmod(h1, t[j], mod1);
			addmod(h2, t[j], mod2);
		}
		hs[mp(h1, h2)] = i + 1;
	}
	FOR(i, 0, k) {
		work(i);
	}
	cout << "NO\n";
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