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

const int maxn = 510;
int n, k;
int a[maxn][maxn];
int vis[maxn][maxn];
int id[maxn][maxn];
int cnt = 0;
int sz[maxn * maxn];
int z[maxn * maxn];
int tot, w;

int ar[] = {1, -1, 0, 0};
int br[] = {0, 0, 1, -1};
int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < n)) return 0;
	return 1;
}

void dfs(int u, int v) {
	vis[u][v] = 1;
	sz[id[u][v] = cnt]++;
	FOR(i, 0, 4) {
		int nu = u + ar[i];
		int nv = v + br[i];
		if (inside(nu, nv) && a[nu][nv] && !vis[nu][nv]) {
			dfs(nu, nv);
		}
	}
}

inline void add(int x) {
	if (!(z[x]++)) {
		tot += sz[x];
	}
}

inline void rem(int x) {
	if (!(--z[x])) {
		tot -= sz[x];
	}
}

inline void addrow(int u, int v, int r) {
	if (r < 0 || r >= n) return;
	FOR(i, u, v + 1) add(id[r][i]);
}

inline void remrow(int u, int v, int r) {
	if (r < 0 || r >= n) return;
	FOR(i, u, v + 1) rem(id[r][i]);
}

inline void addcol(int u, int v, int c) {
	if (c < 0 || c >= n) return;
	FOR(i, u, v + 1) add(id[i][c]);
}

inline void remcol(int u, int v, int c) {
	if (c < 0 || c >= n) return;
	FOR(i, u, v + 1) rem(id[i][c]);
}

inline void add(int u, int v) {
	if (inside(u, v)) {
		add(id[u][v]);
	}
}

inline void rem(int u, int v) {
	if (inside(u, v)) {
		rem(id[u][v]);
	}
}

void solve() {
	cin>>n>>k;
	FOR(i, 0, n) {
		string s; cin>>s;
		FOR(j, 0, n) a[i][j] = s[j] == '.', id[i][j] = maxn * maxn - 1;
	}
	FOR(i, 0, n) FOR(j, 0, n) {
		if (a[i][j] && !vis[i][j]) {
			dfs(i, j);
			cnt++;
		}
	}
	int ans = 0;
	FOR(u, 0, n - k + 1) {
		ms(z, 0); tot = w = 0;
		FOR(i, u, u + k) FOR(j, 0, k) {
			if (a[i][j]) {
				add(id[i][j]);
			}
			else {
				w++;
			}
		}
		addrow(0, k - 1, u - 1);
		addrow(0, k - 1, u + k);
		addcol(u, u + k - 1, k);
		chkmax(ans, tot + w);
		FOR(j, k, n) {
			remcol(u, u + k - 1, j - k - 1);
			remcol(u, u + k - 1, j);
			FOR(i, u, u + k) {
				if (a[i][j - k]) {
					rem(id[i][j - k]);
				}
				else {
					w--;
				}
				if (a[i][j]) {
					add(id[i][j]);
				}
				else {
					w++;
				}
			}
			rem(u - 1, j - k);
			rem(u + k, j - k);
			add(u - 1, j);
			add(u + k, j);
			addcol(u, u + k - 1, j + 1);
			addcol(u, u + k - 1, j - k);
			chkmax(ans, tot + w);
		}
	}
	cout<<ans<<"\n";
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