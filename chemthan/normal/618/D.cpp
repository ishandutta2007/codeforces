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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
template<class T> gcd(T a, T b) {T r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
template<class T> lcm(T a, T b) {return a / gcd(a, b) * b;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 200010;
int n, x, y;
vi adj[maxn];
int f[maxn][2];

int dfs(int u, int flag = 0, int p = -1) {
	int& res = f[u][flag];
	if (~res) return res;
	res = 0;
	vi val1, val2;
	int tot1 = 0, tot2 = 0;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			val1.pb(dfs(v, 0, u));
			val2.pb(dfs(v, 1, u));
			tot1 += val1.back();
			tot2 += val2.back();
		}
	}
	if (!flag) {
		vi t;
		FOR(i, 0, sz(val1)) {
			t.pb(val2[i] - val1[i]);
		}
		sort(all(t));
		if (sz(t) == 1) {
			res = max(res, tot2 + 1);
		}
		if (sz(t) >= 2) {
			res = max(res, tot1 + t[sz(t) - 1] + t[sz(t) - 2] + 2);
		}
		res = max(res, tot1);
	}
	else {
		FOR(i, 0, sz(val1)) {
			res = max(res, tot1 - val1[i] + val2[i] + 1);
		}
		res = max(res, tot1);
	}
	return res;
}

void solve() {
	ms(f, -1);
	cin>>n>>x>>y;
	FOR(i, 0, n - 1) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int d = dfs(0);
	if (x <= y) {
		cout<<((ll) d * x + (ll) (n - d - 1) * y);
	}
	else {
		int flag = 0;
		FOR(i, 0, n) if (sz(adj[i]) == n - 1) flag = 1;
		if (!flag) cout<<(ll) (n - 1) * y;
		else cout<<x + (ll) (n - 2) * y;
	}
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