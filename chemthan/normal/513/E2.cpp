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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
template<class T> void setmin(T& a, T val) {a = min(a, val);}
template<class T> void setmax(T& a, T val) {a = max(a, val);}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 30010;
const int maxk = 210;
int n, k;
int a[maxn];
int f[2][maxn];
int g[2][maxn];
int u[2][maxn];
int v[2][maxn];

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	int cnt = 0, tot = 0, dmin = 0, dmax = 0;
	FOR(i, 0, n) {
		tot += a[i];
		f[cnt][i] = 2 * tot - dmin;
		g[cnt][i] = dmax - 2 * tot;
		dmin = min(dmin, tot);
		dmax = max(dmax, tot);
	}
	FOR(i, 2, k) {
		FOR(j, 0, n) f[cnt ^ 1][j] = g[cnt ^ 1][j] = -INF;
		tot = 0;
		FOR(j, 0, n - 1) {
			tot += a[j];
			u[0][j] = f[cnt][j] + tot;
			u[1][j] = f[cnt][j] - tot;
			v[0][j] = g[cnt][j] + tot;
			v[1][j] = g[cnt][j] - tot;
			if (j) {
				setmax(u[0][j], u[0][j - 1]);
				setmax(u[1][j], u[1][j - 1]);
				setmax(v[0][j], v[0][j - 1]);
				setmax(v[1][j], v[1][j - 1]);
			}
		}
		tot = 0;
		FOR(j, 0, n) {
			tot += a[j];
			if (j) {
				setmax(f[cnt ^ 1][j], u[1][j - 1] + tot);
				setmax(f[cnt ^ 1][j], v[1][j - 1] + 3 * tot);
				setmax(g[cnt ^ 1][j], u[0][j - 1] - 3 * tot);
				setmax(g[cnt ^ 1][j], v[0][j - 1] - tot);
			}
		}
		cnt ^= 1;
	}
	int ans = 0; tot = 0;
	FOR(i, 0, n) {
		tot += a[i];
		if (i) {
			setmax(ans, f[cnt][i - 1] - tot);
			setmax(ans, g[cnt][i - 1] + tot);
			setmax(f[cnt][i], f[cnt][i - 1]);
			setmax(g[cnt][i], g[cnt][i - 1]);
		}
	}
	printf("%d", ans);
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