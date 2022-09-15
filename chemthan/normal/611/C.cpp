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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 510;
int n, m;
int a[maxn][maxn];
char s[maxn];
int f[maxn][maxn];
int g[maxn][maxn];

int calcf(int n, int l, int r) {
	if (!l) return f[n][r];
	int res = f[n][r] - f[n][l - 1];
	if (a[n][l] && a[n][l - 1]) res--;
	return res;
}

int calcg(int m, int l, int r) {
	if (!l) return g[m][r];
	int res = g[m][r] - g[m][l - 1];
	if (a[l][m] && a[l - 1][m]) res--;
	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) a[i][j] = s[j] == '.';
	}
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (j) f[i][j] = f[i][j - 1];
			if (j && a[i][j] && a[i][j - 1]) f[i][j]++;
		}
	}
	FOR(i, 0, m) {
		FOR(j, 0, n) {
			if (j) g[i][j] = g[i][j - 1];
			if (j && a[j][i] && a[j - 1][i]) g[i][j]++;
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		int x, y, z, t; scanf("%d%d%d%d", &x, &y, &z, &t); x--; y--; z--; t--;
		int ans = 0;
		FOR(i, x, z + 1) {
			ans += calcf(i, y, t);
		}
		FOR(i, y, t + 1) {
			ans += calcg(i, x, z);
		}
		printf("%d\n", ans);
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}