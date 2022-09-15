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
const int magic = 320;
int n, m, q;
long long a[maxn];
vector<vector<int> > s;
int id[maxn];
long long sum[maxn];
int f[magic][maxn];
long long g[maxn];

void solve() {
	cin >> n >> m >> q;
	FOR(i, 0, n) cin >> a[i];
	s.resize(m);
	int cnt = 0;
	FOR(i, 0, m) {
		int k; cin >> k;
		s[i].resize(k);
		FOR(j, 0, k) {
			cin >> s[i][j], s[i][j]--;
			sum[i] += a[s[i][j]];
		}
		if (sz(s[i]) > magic) {
			id[i] = ++cnt;
		}
	}
	FOR(i, 0, m) if (id[i]) {
		vi his;
		FOR(j, 0, sz(s[i])) {
			int k = s[i][j];
			g[k] = 1;
			his.pb(k);
		}
		FOR(j, 0, m) {
			FOR(k, 0, sz(s[j])) {
				int l = s[j][k];
				f[id[i]][j] += g[l];
			}
		}
		FOR(j, 0, sz(his)) g[his[j]] = 0;
	}
	vector<pair<string, pi> > que;
	FOR(i, 0, q) {
		string op; cin >> op;
		if (op == "?") {
			int k; cin >> k; k--;
			que.pb(mp(op, mp(k, 0)));
		}
		else {
			int k, x; cin >> k >> x; k--;
			que.pb(mp(op, mp(k, x)));
		}
		if (sz(que) == magic || i == q - 1) {
			FOR(j, 0, sz(que)) {
				string op = que[j].fi;
				if (op == "+") {
					int ix = que[j].se.fi;
					int vv = que[j].se.se;
					if (!id[ix]) {
						FOR(k, 0, sz(s[ix])) {
							int l = s[ix][k];
							g[l] += vv;
						}
					}
				}
				else {
					int ix = que[j].se.fi;
					long long ans = sum[ix];
					if (id[ix]) {
						int ix2 = id[ix];
						FOR(k, 0, j) {
							if (que[k].fi == "+") {
								int ii = que[k].se.fi;
								int vv = que[k].se.se;
								ans += (long long) f[ix2][ii] * vv;
							}
						}
					}
					else {
						FOR(k, 0, j) {
							if (que[k].fi == "+") {
								int ii = que[k].se.fi;
								int vv = que[k].se.se;
								if (id[ii]) {
									int ix2 = id[ii];
									ans += (long long) f[ix2][ix] * vv;
								}
							}
						}
						FOR(k, 0, sz(s[ix])) {
							int l = s[ix][k];
							ans += g[l];
						}
					}
					cout << ans << "\n";
				}
			}
			ms(g, 0);
			vi his;
			FOR(j, 0, sz(que)) {
				if (que[j].fi == "+") {
					int ix = que[j].se.fi;
					int vv = que[j].se.se;
					g[ix] += vv;
					his.pb(ix);
				}
			}
			FOR(j, 0, sz(his)) {
				int ix = his[j];
				if (g[ix]) {
					FOR(k, 0, sz(s[ix])) {
						int l = s[ix][k];
						a[l] += g[ix];
					}
					g[ix] = 0;
				}
			}
			ms(sum, 0);
			FOR(j, 0, m) {
				FOR(k, 0, sz(s[j])) {
					int l = s[j][k];
					sum[j] += a[l];
				}
			}
			que.clear();
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