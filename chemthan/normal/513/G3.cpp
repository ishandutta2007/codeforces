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

const int maxn = 110;
int n, k;
int a[maxn];
ld f[2][maxn][maxn];
ld x[maxn][maxn];
ld y[maxn][maxn];
ld z[maxn][maxn];

void solve() {
	scanf("%d%d", &n, &k);
	k = min(k, 2000);
	FOR(i, 0, n) scanf("%d", a + i);
	int cnt = 0;
	FOR(i, 0, n) FOR(j, i + 1, n) {
		f[cnt][i][j] = a[i] > a[j];
	}
	FOR(t, 0, k) {
		FOR(i, 0, n) FOR(j, i + 1, n) {
			f[cnt][j][i] = 1 - f[cnt][i][j];
		}
		FOR(j, 0, n) FOR(i, 0, n) {
			if (!i) x[i][j] = f[cnt][i][j];
			else x[i][j] = x[i - 1][j] + f[cnt][i][j];
		}
		FOR(j, 0, n) FOR(i, 1, n) {
			x[i][j] += x[i - 1][j];
		}
		FOR(i, 0, n) FOR(j, 0, n) {
			if (!j) y[i][j] = f[cnt][i][j];
			else y[i][j] = y[i][j - 1] + f[cnt][i][j];
		}
		FOR(i, 0, n) FOR(j, 1, n) {
			y[i][j] += y[i][j - 1];
		}
		FOR(i, 0, n) FOR(j, 0, i + 1) {
			if (!j) z[i][j] = f[cnt][i][j];
			else z[i][j] = z[i - 1][j - 1] + f[cnt][i][j];
		}
		FOR(i, 1, n) FOR(j, 1, i + 1) {
			z[i][j] += z[i - 1][j - 1];
		}
		FOR(i, 0, n) FOR(j, i + 1, n) {
			f[cnt ^ 1][i][j] = (j - 1 >= 0 ? x[j - 1][j] : 0) - (j - i - 2 >= 0 ? x[j - i - 2][j] : 0) - (i - 1 >= 0 ? x[i - 1][j] : 0);
			f[cnt ^ 1][i][j] += y[i][n - 1] - y[i][n - 1 + i - j] - (j - 1 >= 0 ? y[i][j - 1] : 0) + (i - 1 >= 0 ? y[i][i - 1] : 0);
			f[cnt ^ 1][i][j] += z[n - 1][n - 1 + i - j] - (n - 1 - j - 1 >= 0 ? z[n - 1 - i - 1][n - 1 - j - 1] : 0) - (i - 1 >= 0 ? z[j - 1][i - 1] : 0);
			f[cnt ^ 1][i][j] += ((ld) (i + 1) * i / 2 + (ld) (n - j - 1) * (n - j) / 2 + (ld) (j - i - 1) * (j - i) / 2) * f[cnt][i][j];
			f[cnt ^ 1][i][j] /= n * (n + 1) / 2;
		}
		cnt ^= 1;
	}
	ld ans = 0;
	FOR(i, 0, n) FOR(j, i + 1, n) ans += f[cnt][i][j];
	cout<<prec(12)<<ans;
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