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

const int maxn = 410;
int n, m;
vi adj[maxn];
int d[maxn][maxn];
vi g[maxn];
ld p[maxn];
ld q[maxn];
ld r[maxn];

void solve() {
	cin>>n>>m;
	ms(d, 0x3f);
	FOR(i, 0, m) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		d[u][v] = d[v][u] = 1;
	}
	FOR(i, 0, n) d[i][i] = 0;
	FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) chkmin(d[i][j], d[i][k] + d[k][j]);
	ld ans = 0;
	FOR(i, 0, n) {
		FOR(j, 0, n) g[j].clear();
		FOR(j, 0, n) g[d[i][j]].pb(j);
		ld tot = 0;
		FOR(j, 0, n) if (sz(g[j])) {
			ms(p, 0); vi ver;
			FOR(k, 0, sz(g[j])) {
				int l = g[j][k];
				FOR(u, 0, sz(adj[l])) {
					int v = adj[l][u];
					if (p[v] == 0) {
						ver.pb(v);
					}
					p[v] += 1.0 / sz(adj[l]);
				}
			}
			ld tmp = 0;
			FOR(k, 0, n) {
				FOR(l, 0, sz(ver)) {
					int v = ver[l];
					chkmax(q[d[k][v]], p[v]);
					r[d[k][v]] += p[v];
				}
				ld z = 0;
				FOR(l, 0, sz(ver)) {
					int v = ver[l];
					if (q[d[k][v]] != 0) {
						z += q[d[k][v]];
						q[d[k][v]] = 0;
					}
				}
				chkmax(tmp, z);
			}
			tot += max((ld) 1.0, tmp) / n;
		}
		chkmax(ans, tot);
	}
	cout<<prec(9)<<ans<<"\n";
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