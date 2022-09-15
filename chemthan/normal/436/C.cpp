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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 20;
const int maxk = 1010;
int n, m, k, w;
int a[maxk][maxn][maxn];
int f[maxk][maxk];
vii adj[maxk];

int dj[maxk];
void init() {
	FOR(i, 0, k + 1) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
	int p = find(u);
	int q = find(v);
	dj[p] = q;
}

int calc(int u, int v) {
	int res = 0;
	FOR(i, 0, n) FOR(j, 0, m) {
		res += a[u][i][j] != a[v][i][j];
	}
	return res;
}

void trace(int u, int p = -1) {
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].fi;
		int t = adj[u][i].se;
		if (v != p) {
			if (t < k) {
				cout<<v + 1<<" "<<t + 1<<"\n";
			}
			else {
				cout<<v + 1<<" "<<0<<"\n";
			}
			trace(v, u);
		}
	}
}

void solve() {
	ms(f, -1);
	cin>>n>>m>>k>>w;
	FOR(i, 0, k) {
		FOR(j, 0, n) {
			string s; cin>>s;
			FOR(l, 0, m) {
				a[i][j][l] = s[l];
			}
		}
	}
	priority_queue<pair<int, pi> > pq;
	FOR(i, 0, k) FOR(j, 0, k) {
		f[i][j] = calc(i, j) * w;
		pq.push(mp(-f[i][j], mp(i, j)));
	}
	FOR(i, 0, k) {
		pq.push(mp(-n * m, mp(i, k)));
	}
	init();
	ll ans = 0;
	while (sz(pq)) {
		int u = pq.top().se.fi;
		int v = pq.top().se.se;
		if (find(u) != find(v)) {
			join(u, v);
			ans -= pq.top().fi;
			adj[u].pb(mp(v, u));
			adj[v].pb(mp(u, v));
		}
		pq.pop();
	}
	cout<<ans<<"\n";
	trace(k);
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