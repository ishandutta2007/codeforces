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
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MOD1 = MOD;
const int MOD2 = (int) 1e8 + 7;
const int MOD3 = 1004535809;

const int maxn = 200010;
int n, k;
int a[maxn];
int HASH1, HASH2, HASH3;

int getmod(int k, int mod) {
	return (k % mod + mod) % mod;
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n + 1) {
		scanf("%d", a + i);
		int x = getmod(a[i], MOD1);
		addmod(HASH1, mult(x, fpow(2, i, MOD1), MOD1), MOD1);
		x = getmod(a[i], MOD2);
		addmod(HASH2, mult(x, fpow(2, i, MOD2), MOD2), MOD2);
		x = getmod(a[i], MOD3);
		addmod(HASH3, mult(x, fpow(2, i, MOD3), MOD3), MOD3);
	}
	int ans = 0;
	FOR(i, 0, n + 1) {
		int tot1 = HASH1, tot2 = HASH2, tot3 = HASH3;
		int x1 = getmod(a[i], MOD1);
		submod(tot1, mult(x1, fpow(2, i, MOD1), MOD1), MOD1);
		int x2 = getmod(a[i], MOD2);
		submod(tot2, mult(x2, fpow(2, i, MOD2), MOD2), MOD2);
		int x3 = getmod(a[i], MOD3);
		submod(tot3, mult(x3, fpow(2, i, MOD3), MOD3), MOD3);
		int y = mult(MOD1 - tot1, fpow(inv(2, MOD1), i, MOD1), MOD1);
		int t2 = tot2, t3 = tot3;
		if (abs(y) <= k) {
			if (i != n || y) {
				int y2 = getmod(y, MOD2);
				int y3 = getmod(y, MOD3);
				addmod(tot2, mult(y2, fpow(2, i, MOD2), MOD2), MOD2);
				addmod(tot3, mult(y3, fpow(2, i, MOD3), MOD3), MOD3);
				if (!tot2 && !tot3) {
					ans++;
				}
			}
		}
		tot2 = t2; tot3 = t3;
		y = y - MOD1;
		if (abs(y) <= k) {
			if (i != n || y) {
				int y2 = getmod(y, MOD2);
				int y3 = getmod(y, MOD3);
				addmod(tot2, mult(y2, fpow(2, i, MOD2), MOD2), MOD2);
				addmod(tot3, mult(y3, fpow(2, i, MOD3), MOD3), MOD3);
				if (!tot2 && !tot3) {
					ans++;
				}
			}
		}
	}
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