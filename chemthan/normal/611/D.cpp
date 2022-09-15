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
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 5010;
int n;
char s[maxn];
int lcp[maxn][maxn];
int f[maxn][maxn];
int g[maxn][maxn];
int sum[maxn][maxn];

void solve() {
	scanf("%d%s", &n, s);
	FORd(i, n, 0) FORd(j, n, 0) {
		if (s[i] == s[j]) {
			lcp[i][j] = lcp[i + 1][j + 1] + 1;
		}
	}
	FOR(i, 0, n) FOR(j, i, n) {
		int k = 2 * j - i + 1;
		if (k < n) {
			int l = min(lcp[i][j + 1], j - i + 1);
			if (l < j - i + 1 && s[i + l] < s[j + l + 1]) {
				f[i][j] = 1;
			}
		}
	}
	FOR(i, 0, n) g[i][n - 1] = 1;
	sum[n - 1][n - 1] = 1;
	FORd(j, n - 1, 0) {
		FOR(i, 0, j + 1) if (s[j + 1] != '0') {
			int k = 2 * j - i + 1;
			if (!f[i][j]) k++;
			if (k < n) g[i][j] = sum[j + 1][k];
		}
		int t = 0;
		FORd(i, n, j) {
			addmod(t, g[j][i]);
			sum[j][i] = t;
		}
	}
	int ans = 0;
	FOR(i, 0, n) {
		addmod(ans, g[0][i]);
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