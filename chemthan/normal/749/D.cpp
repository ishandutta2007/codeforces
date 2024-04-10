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

const int maxn = 200000 + 10;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
vi g[maxn];

inline int query(int ix, int l, int r) {
	return upper_bound(all(g[ix]), r) - upper_bound(all(g[ix]), l);
}

void solve() {
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i] >> b[i], a[i]--;
		g[a[i]].pb(i);
		chkmax(c[a[i]], b[i]);
	}
	set<pi> heap;
	FOR(i, 0, n) heap.insert(mp(c[i], i));
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		vi v(k);
		FOR(i, 0, k) {
			cin >> v[i], v[i]--;
			heap.erase(mp(c[v[i]], v[i]));
		}
		if (!sz(heap) || heap.rbegin()->fi == 0) {
			cout << 0 << " " << 0 << "\n";
		}
		else {
			int ix = heap.rbegin()->se;
			if (sz(g[ix]) == 1) {
				cout << ix + 1 << " " << c[ix] << "\n";
			}
			else {
				int l = -1, r = sz(g[ix]) - 2;
				while (l < r) {
					int m = l + r + 1 >> 1;
					int tot = 0;
					FOR(i, 0, k) {
						tot += query(v[i], g[ix][m], g[ix].back());
					}
					if (tot < g[ix].back() - g[ix][m] - (sz(g[ix]) - m) + 1) {
						l = m;
					}
					else {
						r = m - 1;
					}
				}	
				cout << ix + 1 << " " << b[g[ix][l + 1]] << "\n";
			}
		}
		FOR(i, 0, k) {
			heap.insert(mp(c[v[i]], v[i]));
		}
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