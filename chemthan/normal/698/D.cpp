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

const int maxn = 1010;
const int maxk = 10;
int k, n;
int ax[maxn];
int ay[maxn];
int mx[maxn];
int my[maxn];
map<pi, vector<pair<pi, int> > > g[maxk];
map<pi, vector<pair<pi, int> > > h[maxk];
int f[maxn];

int solve(vector<int>& vv, vector<int>& vu) {
	if (!sz(vu)) return 1;
	if (sz(vv) < sz(vu)) {
		return 0;
	}
	FOR(i, 0, sz(vv)) {
		int l = vv[i];
		vector<int> nvv = vv;
		nvv.erase(nvv.begin() + i);
		int z = vu.back();
		vector<int> nvu = vu;
		nvu.pop_back();
		int x = mx[z] - ax[l];
		int y = my[z] - ay[l];
		int w = abs(gcd(x, y));
		if (mp(x, y) > mp(0, 0)) {
			vector<pair<pi, int> >& vr = g[l][mp(x / w, y / w)];
			int d = lower_bound(all(vr), mp(mp(+mx[z], +my[z]), z)) - vr.begin();
			vi his;
			FOR(j, 0, d) {
				int p = vr[j].se;
				if (!f[p]) {
					nvu.pb(p);
					his.pb(p);
					f[p] = 1;
				}
				if (sz(nvu) > sz(nvv)) {
					break;
				}
			}
			if (solve(nvv, nvu)) {
				return 1;
			}
			FOR(j, 0, sz(his)) {
				f[his[j]] = 0;
			}
		}
		else {
			vector<pair<pi, int> >& vr = h[l][mp(x / w, y / w)];
			int d = lower_bound(all(vr), mp(mp(-mx[z], -my[z]), z)) - vr.begin();
			vi his;
			FOR(j, 0, d) {
				int p = vr[j].se;
				if (!f[p]) {
					nvu.pb(p);
					his.pb(p);
					f[p] = 1;
				}
				if (sz(nvu) > sz(nvv)) {
					break;
				}
			}
			if (solve(nvv, nvu)) {
				return 1;
			}
			FOR(j, 0, sz(his)) {
				f[his[j]] = 0;
			}
		}
	}
	return 0;
}

void solve() {
	cin >> k >> n;
	FOR(i, 0, k) cin >> ax[i] >> ay[i];
	FOR(i, 0, n) {
		cin >> mx[i] >> my[i];
		FOR(j, 0, k) {
			int x = mx[i] - ax[j];
			int y = my[i] - ay[j];
			int z = abs(gcd(x, y));
			if (mp(x, y) > mp(0, 0)) {
				g[j][mp(x / z, y / z)].pb(mp(mp(+mx[i], +my[i]), i));
			}
			else {
				h[j][mp(x / z, y / z)].pb(mp(mp(-mx[i], -my[i]), i));
			}
		}
	}
	FOR(i, 0, k) {
		FORall(it, g[i]) {
			sort(all(it->se));
		}
		FORall(it, h[i]) {
			sort(all(it->se));
		}
	}
	vector<int> vv;
	FOR(i, 0, k) vv.pb(i);
	int ans = 0;
	FOR(i, 0, n) {
		vector<int> vu; vu.pb(i);
		fill_n(f, n, 0); f[i] = 1;
		ans += solve(vv, vu);
		f[i] = 0;
	}
	cout << ans << "\n";
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