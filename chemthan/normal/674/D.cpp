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
int n, q;
ll t[maxn];
int f[maxn];
ll g[maxn];
ll h[maxn];
set<pair<ll, int> > st[maxn];
set<pair<ll, int> > mm;

ll query(int u) {
	int v = f[u];
	return t[v] / (sz(st[v]) + 2);
}

void upd(int u, int v, ll val) {
	mm.erase(mp(h[u], u));
	st[v].erase(mp(g[u], u));
	st[v].insert(mp(g[u] = val, u));
}

void upd1(int u) {
	mm.erase(mp(h[u], u));
	mm.insert(mp(h[u] = g[u] + query(u), u));
}

void upd2(int u) {
	if (sz(st[u])) {
		int x = st[u].begin()->se;
		int y = st[u].rbegin()->se;
		upd1(x); upd1(y);
	}
}

void del(int u) {
	if (sz(st[u])) {
		int x = st[u].begin()->se;
		int y = st[u].rbegin()->se;
		mm.erase(mp(h[x], x));
		mm.erase(mp(h[y], y));
	}
}

void solve() {
	cin>>n>>q;
	FOR(i, 0, n) cin>>t[i];
	FOR(i, 0, n) cin>>f[i], f[i]--;
	FOR(i, 0, n) st[f[i]].insert(mp(g[i], i));
	FOR(i, 0, n) {
		g[f[i]] += t[i] / (sz(st[i]) + 2);
		g[i] += t[i] - t[i] / (sz(st[i]) + 2) * (sz(st[i]) + 1);
	}
	FOR(i, 0, n) st[i].clear();
	FOR(i, 0, n) st[f[i]].insert(mp(g[i], i));
	FOR(i, 0, n) upd1(i);
	while (q--) {
		int op; cin>>op;
		if (op == 1) {
			int u, v; cin>>u>>v; u--; v--;
			int w = f[u];
			int x = f[w];
			int y = f[v];
			int z = f[x];
			int r = f[y];
			ll wdif = -t[u] / (sz(st[u]) + 2) + t[w] / (sz(st[w]) + 2) * (sz(st[w]) + 1);
			ll xdif = -t[w] / (sz(st[w]) + 2);
			ll vdif = +t[u] / (sz(st[u]) + 2) + t[v] / (sz(st[v]) + 2) * (sz(st[v]) + 1);
			ll ydif = -t[v] / (sz(st[v]) + 2);
			mm.erase(mp(h[u], u));
			del(w); del(v); del(x); //del(y);
			st[w].erase(mp(g[u], u));
			st[v].insert(mp(g[u], u));
			wdif -= t[w] / (sz(st[w]) + 2) * (sz(st[w]) + 1);
			xdif += t[w] / (sz(st[w]) + 2);
			vdif -= t[v] / (sz(st[v]) + 2) * (sz(st[v]) + 1);
			ydif += t[v] / (sz(st[v]) + 2);
			upd(w, x, g[w] + wdif); upd(x, z, g[x] + xdif);
			upd(v, y, g[v] + vdif); upd(y, r, g[y] + ydif);
			f[u] = v;
			upd2(w); upd2(x); upd2(z);
			upd2(v); upd2(y); upd2(r);
		}
		else if (op == 2) {
			int u; cin>>u; u--;
			cout<<g[u] + query(u)<<"\n";
		}
		else if (op == 3) {
			cout<<mm.begin()->fi<<" "<<mm.rbegin()->fi<<"\n";
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