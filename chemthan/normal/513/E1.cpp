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
void add(int& a, int val, int p = (int) 1e9 + 7) {if ((a = a + val) >= p) a -= p;}
void setmin(int& a, int val) {a = min(a, val);}
void setmax(int& a, int val) {a = max(a, val);}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 410;
const int maxk = 60;
int n, k;
int a[maxn];
int f[2][maxn];
int g[2][maxn];

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	int cnt = 0;
	FOR(i, 1, k) {
		FOR(j, 0, n) f[cnt ^ 1][j] = g[cnt ^ 1][j] = -INF;
		FOR(j, 0, n) {
			int tot = 0;
			FORd(l, j + 1, 0) {
				tot += a[l];
				if (i == 1) {
					setmax(f[cnt ^ 1][j], tot);
					setmax(g[cnt ^ 1][j], -tot);
				}
				else if (l) {
					setmax(f[cnt ^ 1][j], f[cnt][l - 1] - tot + tot);
					setmax(f[cnt ^ 1][j], g[cnt][l - 1] + tot + tot);
					setmax(g[cnt ^ 1][j], f[cnt][l - 1] - tot - tot);
					setmax(g[cnt ^ 1][j], g[cnt][l - 1] + tot - tot);
				}
			}
		}
		cnt ^= 1;
	}
	int ans = 0;
	FOR(i, 0, n) {
		int tot = 0;
		FORd(j, i + 1, 1) {
			tot += a[j];
			setmax(ans, f[cnt][j - 1] - tot);
			setmax(ans, g[cnt][j - 1] + tot);
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