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
const int maxm = 30010;
int n, m, s, t;
vii adj[maxn];
int w[maxm];
int d[maxm];
int del[maxm];
pi from[maxn];
int vis[maxm];
int num[maxn];
int low[maxn];
int cnt;

vector<int> getpath() {
	fill_n(vis, m, 0); fill_n(from, n, mp(-1, -1));
	queue<int> q; q.push(s); vis[s] = 1;
	while (sz(q)) {
		int u = q.front();
		q.pop();
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].fi;
			int id = adj[u][i].se;
			if (!vis[v] && !del[id]) {
				vis[v] = 1;
				from[v] = mp(u, id);
				q.push(v);
			}
		}
	}
	vector<int> res;
	if (!~from[t].fi) {
		return res;
	}
	int cur = t;
	while (cur != s) {
		res.pb(from[cur].se);
		cur = from[cur].fi;
	}
	reverse(all(res));
	return res;
}

void dfs(int u, int prv = -1) {
	num[u] = low[u] = ++cnt;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int id = adj[u][i].se;
		if (!del[id]) {
			if (!num[v]) {
				dfs(v, id);
				chkmin(low[u], low[v]);
				if (low[v] > num[u]) {
					d[id] = 1;
				}
			}
			else if (id != prv) {
				chkmin(low[u], num[v]);
			}
		}
	}
}

pair<long long, int> work() {
	fill_n(d, m, 0); fill_n(num, n, 0); fill_n(low, n, 0); cnt = 0;
	dfs(s);
	vector<int> path = getpath();
	if (!sz(path)) {
		return mp(0, -1);
	}
	pair<long long, int> res = mp(LINF, -1);
	FOR(i, 0, sz(path)) {
		int e = path[i];
		if (d[e]) {
			chkmin(res, mp((long long) w[e], e));
		}
	}
	return res;
}

void solve() {
	cin >> n >> m >> s >> t; s--; t--;
	FOR(i, 0, m) {
		int u, v; cin >> u >> v >> w[i]; u--; v--;
		adj[u].pb(mp(v, i)); adj[v].pb(mp(u, i));
	}
	vector<int> path = getpath();
	if (!sz(path)) {
		cout << 0 << "\n";
		cout << 0 << "\n";
		return;
	}
	pair<long long, pi> ans = mp(LINF, mp(-1, -1));
	FOR(i, 0, sz(path)) {
		int e = path[i];
		del[e] = 1;
		pair<long long, int> r = work();
		chkmin(ans, mp(w[e] + r.fi, mp(e, r.se)));
		del[e] = 0;
	}
	if (ans.fi == LINF) {
		cout << -1 << "\n";
		return;
	}
	cout << ans.fi << "\n";
	if (~ans.se.se) {
		cout << 2 << "\n";
		cout << ans.se.fi + 1 << " ";
		cout << ans.se.se + 1 << "\n";
	}
	else {
		cout << 1 << "\n";
		cout << ans.se.fi + 1 << "\n";
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