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
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
int n, m;
int l, s, t;
vii edge;
vii adj[maxn];
long long x[maxn];
long long y[maxn];
long long d[maxn];
pi from[maxn];

void dijkstra() {
	priority_queue<pair<long long, int> > pq;
	fill_n(d, n, LINF);
	d[s] = 0; pq.push(mp(-d[s], s));
	while (sz(pq)) {
		int u = pq.top().se;
		long long tt = -pq.top().fi;
		pq.pop();
		if (d[u] != tt) continue;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].fi;
			int ix = adj[u][i].se;
			long long w = x[ix];
			if (!w) w = y[ix];
			if (chkmin(d[v], d[u] + w)) {
				pq.push(mp(-d[v], v));
				from[v] = mp(u, ix);
			}
		}
	}
}

int work() {
	dijkstra();
	if (d[t] > l) {
		cout << "NO\n";
		exit(0);
	}
	int cur = t;
	vi v;
	while (cur != s) {
		int ix = from[cur].se;
		if (!x[ix]) {
			v.pb(ix);
		}
		cur = from[cur].fi;
	}
	if (d[t] < l && !sz(v)) {
		cout << "NO\n";
		exit(0);
	}
	int fir = 1;
	FOR(i, 0, sz(v)) {
		int ix = v[i];
		if (fir) {
			fir = 0;
			y[ix] += l - d[t];
		}
	}
	if (d[t] == l) {
		return 0;
	}
	else {
		return 1;
	}
}

void solve() {
	cin >> n >> m >> l >> s >> t;
	FOR(i, 0, m) {
		int u, v, w; cin >> u >> v >> x[i];
		adj[u].pb(mp(v, i)), adj[v].pb(mp(u, i));
		edge.pb(mp(u, v));
		if (!x[i]) y[i] = 1;
	}
	while (work());
	FOR(i, 0, m) if (!x[i]) x[i] = y[i];
	cout << "YES\n";
	FOR(i, 0, m) {
		cout << edge[i].fi << " " << edge[i].se << " " << x[i] << "\n";
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