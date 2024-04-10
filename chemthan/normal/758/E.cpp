#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int MAXN = 200000 + 10;
long long st[MAXN << 2];
int mx[MAXN << 2];
void upd(int p, int i, int L, int R, int val) {
	if (i < L || i > R) return;
	if (L == R) {
		if (val < 0) {
			st[p] = -val;
			mx[p] = -1;
		}
		else {
			st[p] = +val;
			mx[p] = i;
		}
		return;
	}
	upd(p << 1, i, L, L + R >> 1, val);
	upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
	st[p] = st[p << 1] + st[p << 1 | 1];
	mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
long long query(int p, int l, int r, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) return st[p];
	return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}
int query2(int p, int l, int r, int L, int R) {
	if (l > R || r < L) return -1;
	if (l <= L && r >= R) return mx[p];
	return max(query2(p << 1, l, r, L, L + R >> 1), query2(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

const int maxn = 200000 + 10;
int n;
int x[maxn];
int y[maxn];
int z[maxn];
int w[maxn];
int p[maxn];
vi adj[maxn];
int tin[maxn];
int tou[maxn];
int ord[maxn];
int tms;
vi ver;

void dfs(int u) {
	ver.pb(ord[tin[u] = tms++] = u);
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		dfs(v);
	}
	tou[u] = tms - 1;
}

long long get(int u) {
	int l = tin[u];
	int r = tou[u];
	return max(0LL, p[z[u]] - query(1, l + 1, r, 0, n - 1));
}

void solve() {
	cin >> n;
	FOR(i, 0, n - 1) {
		cin >> x[i] >> y[i] >> w[i] >> p[i]; x[i]--, y[i]--;
		adj[x[i]].pb(y[i]);
		z[y[i]] = i;
	}
	dfs(0);
	FORd(i, sz(ver), 1) {
		int ix = z[ver[i]];
		int val = min(w[ix] - 1, p[ix]);
		if (!val) {
			upd(1, i, 0, n - 1, -w[ix]);
		}
		else {
			upd(1, i, 0, n - 1, +w[ix]);
		}
	}
	FORd(i, sz(ver), 1) {
		int u = ver[i];
		int l = tin[u];
		int r = tou[u];
		long long sum = query(1, l + 1, r, 0, n - 1) - p[z[u]];
		while (sum > 0) {
			int u = query2(1, l + 1, r, 0, n - 1);
			if (u == -1) {
				cout << -1 << "\n";
				return;
			}
			int ix = z[ord[u]];
			int k = min(min(sum, (long long) min(w[ix] - 1, p[ix])), get(ord[u]));
			if (!k) {
				upd(1, u, 0, n - 1, -w[ix]);
				continue;
			}
			sum -= k, w[ix] -= k, p[ix] -= k;
			int val = min(w[ix] - 1, p[ix]);
			if (!val) {
				upd(1, u, 0, n - 1, -w[ix]);
			}
			else {
				upd(1, u, 0, n - 1, +w[ix]);
			}
		}
	}
	cout << n << "\n";
	FOR(i, 0, n - 1) {
		cout << x[i] + 1 << " " << y[i] + 1 << " " << w[i] << " " << p[i] << "\n";
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