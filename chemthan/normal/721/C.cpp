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

const int maxn = 5000 + 10;
int n, m, t;
vii adj[maxn];
int d[maxn][maxn];
int from[maxn][maxn];

void solve() {
	cin >> n >> m >> t;
	FOR(i, 0, m) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u].pb(mp(v, w));
	}
	priority_queue<pair<int, pi> > pq;
	FOR(i, 0, n) FOR(j, 1, n + 1) d[i][j] = INF << 1;
	d[0][1] = 0; pq.push(mp(-d[0][1], mp(0, 1)));
	while (sz(pq)) {
		int u = pq.top().se.fi;
		int x = pq.top().se.se;
		int p = -pq.top().fi;
		pq.pop();
		if (d[u][x] != p) continue;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se;
			if (chkmin(d[v][x + 1], d[u][x] + w) && d[u][x] + w <= t) {
				pq.push(mp(-d[v][x + 1], mp(v, x + 1)));
				from[v][x + 1] = u;
			}
		}
	}
	int ans = 0;
	FOR(i, 1, n + 1) if (d[n - 1][i] <= t) {
		ans = i;
	}
	cout << ans << "\n";
	int cur = n - 1, k = ans;
	vi res;
	FOR(i, 0, ans) {
		res.pb(cur);
		cur = from[cur][k];
		k--;
	}
	FORd(i, sz(res), 0) cout << res[i] + 1 << " \n"[i == 0];
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