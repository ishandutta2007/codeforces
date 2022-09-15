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
void setmin(int& a, int val) {if (a > val) a = val;}
void setmax(int& a, int val) {if (a < val) a = val;}

const int maxn = 2010;
int n, m, d;
char s[maxn];
char t[maxn];
int a[maxn];
int b[maxn];
int f[maxn][maxn][2][2];

int calc(int pos, int r, int fa, int fb) {
	if (pos == n) {
		return r == 0;
	}
	int& res = f[pos][r][fa][fb];
	if (~res) return res;
	res = 0;
	int lo = 0, hi = 9;
	if (pos & 1) lo = hi = d;
	if (!fa) lo = max(lo, a[pos]);
	if (!fb) hi = min(hi, b[pos]);
	FOR(i, lo, hi + 1) {
		if ((pos & 1) && i != d) continue;
		if (!(pos & 1) && i == d) continue;
		addmod(res, calc(pos + 1, (r * 10 + i) % m, fa | i > a[pos], fb | i < b[pos]));
	}
	return res;
}

void solve() {
	scanf("%d%d", &m, &d);
	scanf("%s%s", s, t);
	n = strlen(s);
	FOR(i, 0, n) {
		a[i] = s[i] - '0';
		b[i] = t[i] - '0';
	}
	ms(f, -1);
	cout<<calc(0, 0, 0, 0);
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