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

const int maxm = 100000 + 10;
int n, m;
int x[maxm];
int y[maxm];
vii gx[maxm];
vii gy[maxm];
map<pi, int> hs;
map<int, int> dcx, dcy;
int vis[maxm];
int found;

void dfs(int u) {
	if (x[u] == 1 || y[u] == n) found = 1;
	if (found) return;
	vis[u] = 1;
	FOR(i, -1, 2) FOR(j, -1, 2) {
		int nx = x[u] + i;
		int ny = y[u] + j;
		if (hs.count(mp(nx, ny))) {
			int v = hs[mp(nx, ny)];
			if (!vis[v]) {
				dfs(v);
			}
		}
	}
	int xx = dcx[x[u]];
	int yy = dcy[y[u]];
	int k = lower_bound(all(gx[xx]), mp(y[u], -INF)) - gx[xx].begin();
	if (k--) {
		int v = gx[xx][k].se;
		if (!vis[v]) dfs(v);
	}
	k = upper_bound(all(gy[yy]), mp(x[u], INF)) - gy[yy].begin();
	if (k < sz(gy[yy])) {
		int v = gy[yy][k].se;
		if (!vis[v]) dfs(v);
	}
	if (dcx.count(x[u] - 1)) {
		xx = dcx[x[u] - 1];
		k = lower_bound(all(gx[xx]), mp(y[u], -INF)) - gx[xx].begin();
		if (k--) {
			int v = gx[xx][k].se;
			if (!vis[v]) dfs(v);
		}
	}
	if (dcy.count(y[u] + 1)) {
		yy = dcy[y[u] + 1];
		k = upper_bound(all(gy[yy]), mp(x[u], INF)) - gy[yy].begin();
		if (k < sz(gy[yy])) {
			int v = gy[yy][k].se;
			if (!vis[v]) dfs(v);
		}
	}
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, m) {
		cin >> x[i] >> y[i];
		if (x[i] == n && y[i] == n) {
			found = 1;
		}
		hs[mp(x[i], y[i])] = i;
		dcx[x[i]], dcy[y[i]];
	}
	int cnt;
	cnt = 0; FORall(it, dcx) it->se = cnt++;
	cnt = 0; FORall(it, dcy) it->se = cnt++;
	FOR(i, 0, m) {
		gx[dcx[x[i]]].pb(mp(y[i], i));
		gy[dcy[y[i]]].pb(mp(x[i], i));
	}
	FOR(i, 0, maxm) {
		sort(all(gx[i]));
		sort(all(gy[i]));
	}
	FOR(i, 0, m) {
		if (x[i] == n || y[i] == 1) {
			dfs(i);
		}
	}
	if (found) {
		cout << -1 << "\n";
	}
	else {
		cout << 2 * (n - 1) << "\n";
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