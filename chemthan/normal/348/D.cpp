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

const int maxn = 3000 + 10;
int n, m;
int a[maxn][maxn];
char s[maxn];
int f[maxn][maxn];
int dx[] = {1, 0};
int dy[] = {0, 1};

inline int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < m)) return 0;
	return a[u][v] != '#';
}

int calc(int stx, int sty, int edx, int edy) {
	if (stx >= edx) return 0;
	if (sty >= edy) return 0;
	if (a[stx][sty] == '#') return 0;
	if (a[edx - 1][edy - 1] == '#') return 0;
	ms(f, 0);
	FORd(i, edx, stx) FORd(j, edy, sty) {
		if (i == edx - 1 && j == edy - 1) {
			f[i][j] = 1;
		}
		else {
			f[i][j] = 0;
			FOR(k, 0, 2) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (inside(ni, nj)) {
					addmod(f[i][j], f[ni][nj]);
				}
			}
		}
	}
	return f[stx][sty];
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) a[i][j] = s[j];
	}
	int t1 = calc(1, 0, n, m - 1);
	int t2 = calc(0, 1, n - 1, m);
	int t3 = calc(1, 0, n - 1, m);
	int t4 = calc(0, 1, n, m - 1);
	int ans = mult(t1, t2);
	submod(ans, mult(t3, t4));
	printf("%d\n", ans);
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