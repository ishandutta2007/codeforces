#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100010;
int n;
int a[maxn];
vi adj[maxn];
ll f[maxn];
ll g[maxn];
ll ans;

void fdfs(int u, int p = -1) {
	vector<ll> vx;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			fdfs(v, u);
			vx.pb(f[v]);
			setmax(f[u], f[v]);
			setmax(g[u], g[v]);
		}
	}
	sort(all(vx));
	ll tot = 0;
	int cnt = 0;
	while (cnt < 2 && sz(vx)) {
		tot += vx.back();
		vx.pop_back();
		cnt++;
	}
	setmax(g[u], tot + a[u]);
	f[u] += a[u];
}

void dfs(int u, int p = -1, ll x = 0) {
	setmax(ans, g[u] + x);
	vi vt;
	vector<ll> vx;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			vt.pb(v);
			vx.pb(f[v]);
		}
	}
	vector<ll> pref = vx, suff = vx;
	FOR(i, 1, sz(pref)) {
		setmax(pref[i], pref[i - 1]);
	}
	FORd(i, sz(suff) - 1, 0) {
		setmax(suff[i], suff[i + 1]);
	}
	multiset<ll> st;
	vector<pair<ll, int> > vy;
	FOR(i, 0, sz(vt)) {
		int v = vt[i];
		ll y = x;
		if (i) setmax(y, pref[i - 1]);
		if (i < sz(vt) - 1) setmax(y, suff[i + 1]);
		dfs(v, u, y + a[u]);
		st.insert(f[v]);
		vy.pb(mp(g[v], v));
	}
	sort(all(vy));
	vi vz;
	while (sz(vz) < 3 && sz(vy)) {
		vz.pb(vy.back().se);
		vy.pop_back();
	}
	st.insert(x);
	FOR(i, 0, sz(vz)) {
		int v = vz[i];
		vector<ll> his;
		st.erase(st.find(f[v])); his.pb(f[v]);
		ll tot = 0;
		int cnt = 0;
		while (cnt < 2 && sz(st)) {
			ll x = *st.rbegin();
			tot += x; cnt++;
			st.erase(st.find(x)); his.pb(x);
		}
		setmax(ans, g[v] + tot + a[u]);
		FOR(j, 0, sz(his)) {
			st.insert(his[j]);
		}
	}
	ll tot = 0;
	FOR(i, 0, min(2, sz(vz))) {
		int v = vz[i];
		tot += g[v];
	}
	setmax(ans, tot);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	fdfs(0); dfs(0);
	printf("%I64d", ans);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}