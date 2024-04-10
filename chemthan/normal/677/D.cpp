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

const int maxn = 310;
int n, m, p;
int a[maxn][maxn];
int dst[maxn][maxn];
int tmp[maxn][maxn];
vii g[maxn * maxn];

int ar[] = {1, -1, 0, 0};
int ac[] = {0, 0, 1, -1};

void solve() {
	cin>>n>>m>>p; p--;
	FOR(i, 0, n) FOR(j, 0, m) {
		cin>>a[i][j];
		g[--a[i][j]].pb(mp(i, j));
	}
	ms(dst, 0x3f);
	int u = g[p][0].fi, v = g[p][0].se;
	dst[u][v] = 0;
	int magic = n * m;
	FORd(i, p, 0) {
		if (sz(g[i + 1]) * sz(g[i]) <= magic) {
			FOR(j, 0, sz(g[i + 1])) FOR(k, 0, sz(g[i])) {
				int x = g[i + 1][j].fi;
				int y = g[i + 1][j].se;
				int z = g[i][k].fi;
				int w = g[i][k].se;
				chkmin(dst[z][w], dst[x][y] + abs(x - z) + abs(y - w));
			}
		}
		else {
			ms(tmp, 0x3f);
			queue<pi> q;
			FOR(j, 0, sz(g[i + 1])) {
				int u = g[i + 1][j].fi;
				int v = g[i + 1][j].se;
				q.push(mp(u, v));
				tmp[u][v] = dst[u][v];
			}
			while (sz(q)) {
				int u = q.front().fi;
				int v = q.front().se;
				q.pop();
				FOR(j, 0, 4) {
					int nu = u + ar[j];
					int nv = v + ac[j];
					if (nu >= 0 && nu < n && nv >= 0 && nv < m) {
						if (chkmin(tmp[nu][nv], tmp[u][v] + 1)) {
							q.push(mp(nu, nv));
						}
					}
				}
			}
			FOR(j, 0, sz(g[i])) {
				int u = g[i][j].fi;
				int v = g[i][j].se;
				dst[u][v] = tmp[u][v];
			}
		}
	}
	int ans = INF;
	FOR(i, 0, sz(g[0])) {
		int u = g[0][i].fi;
		int v = g[0][i].se;
		chkmin(ans, dst[u][v] + abs(u) + abs(v));
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