#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
	#define cout cerr
#endif
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 1000 + 5;
const int maxk = 300000 + 5;
const int maxc = 26;
int n, m, k;
int a[maxn][maxn];
int x[maxk];
int y[maxk];
int z[maxk];
int t[maxk];
char e[maxk];
long long f[maxn][maxn];
long long cnt[maxc][maxn][maxn];
long long tot[maxn][maxn];

inline long long query(long long ar[maxn][maxn], int x, int y, int z, int t) {
	return ar[z][t] - ar[x - 1][t] - ar[z][y - 1] + ar[x - 1][y - 1];
}

void solve() {
	cin >> n >> m >> k;
	FOR(i, 1, n + 1) {
		string s; cin >> s;
		FOR(j, 1, m + 1) a[i][j] = s[j - 1];
	}
	FOR(i, 0, k) {
		cin >> x[i] >> y[i] >> z[i] >> t[i] >> e[i];
		f[x[i]][y[i]]++;
		f[x[i]][t[i] + 1]--;
		f[z[i] + 1][y[i]]--;
		f[z[i] + 1][t[i] + 1]++;
		int ix = e[i] - 'a';
		cnt[ix][x[i]][y[i]]++;
		cnt[ix][x[i]][t[i] + 1]--;
		cnt[ix][z[i] + 1][y[i]]--;
		cnt[ix][z[i] + 1][t[i] + 1]++;
	}
	FOR(l, 0, maxc) {
		FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
			cnt[l][i][j] += cnt[l][i][j - 1] + cnt[l][i - 1][j] - cnt[l][i - 1][j - 1];
		}
	}
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
		int ix = a[i][j] - 'a';
		cnt[ix][i][j] += k - f[i][j];
		FOR(l, 0, maxc) {
			tot[i][j] += abs(ix - l) * cnt[l][i][j];
			cnt[l][i][j] += cnt[l][i][j - 1] + cnt[l][i - 1][j] - cnt[l][i - 1][j - 1];
		}
	}
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		tot[i][j] += tot[i][j - 1] + tot[i - 1][j] - tot[i - 1][j - 1];
	}
	long long ans = LINF;
	FOR(i, 0, k) {
		long long tmp = tot[n][m] - query(tot, x[i], y[i], z[i], t[i]);
		FOR(j, 0, maxc) {
			tmp += abs(e[i] - 'a' - j) * query(cnt[j], x[i], y[i], z[i], t[i]);
		}
		chkmin(ans, tmp);
	}
	cout << ans << "\n";
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