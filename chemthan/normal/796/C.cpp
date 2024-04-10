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
const ld EPS = 1e-6;
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

struct RangeQuery {
	static const int maxn = 1e6 + 5;
	static const int magic = 1e3 + 5;
	int a[maxn];
	int b[maxn];
	int block[magic];
	vector<int> his;
	
	void clear() {
		while (his.size()) {
			int k = his.back();
			a[k] = b[k] = block[k / magic] = 0;
			his.pop_back();
		}
	}
	int upd(int n, int val, int limit) {
		if (!(b[n]++)) {
			his.push_back(n);
		}
		a[n] += val;
		block[n / limit] += val;
	}
	int querymax(int limit) {
		for (int i = limit - 1; i >= 0; i--) {
			if (block[i]) {
				for (int j = limit - 1; j >= 0; j--) {
					if (a[i * limit + j]) {
						return i * limit + j;
					}
				}
			}
		}
		return 0;
	}
} rq;

const int maxn = 3e5 + 5;
int n;
int a[maxn];
vi adj[maxn];
int f[maxn][3];

void solve() {
	scanf("%d", &n);
	vi v;
	FOR(i, 0, n) scanf("%d", a + i), v.pb(a[i]), v.pb(a[i] + 1), v.pb(a[i] + 2);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	sort(all(v)), uni(v);
	int limit = isqrt(sz(v)) + 5;
	FOR(i, 0, n) {
		FOR(j, 0, 3) f[i][j] = lower_bound(all(v), a[i] + j) - v.begin();
	}
	multiset<int> st;
	FOR(i, 0, n) rq.upd(f[i][2], 1, limit);
	int ans = INF + INF;
	FOR(i, 0, n) {
		rq.upd(f[i][2], -1, limit);
		rq.upd(f[i][0], 1, limit);
		FOR(j, 0, sz(adj[i])) {
			int k = adj[i][j];
			rq.upd(f[k][2], -1, limit);
			rq.upd(f[k][1], 1, limit);
		}
		chkmin(ans, v[rq.querymax(limit)]);
		FOR(j, 0, sz(adj[i])) {
			int k = adj[i][j];
			rq.upd(f[k][1], -1, limit);
			rq.upd(f[k][2], 1, limit);
		}
		rq.upd(f[i][0], -1, limit);
		rq.upd(f[i][2], 1, limit);
	}
	printf("%d\n", ans);
}

int main() {
	int JUDGE_ONLINE = 0;
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        JUDGE_ONLINE = 1;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    if (!JUDGE_ONLINE) {
    	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}