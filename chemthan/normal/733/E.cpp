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

const int maxn = 1000000 + 10;
int n;
string s;
int cnt[2][maxn];
long long sum[2][maxn];
int nxtD[maxn];
int prvU[maxn];

void solve() {
	cin >> n >> s;
	int a = 0, b = 0;
	long long s0 = 0, s1 = 0;
	int tmp = -1;
	FOR(i, 0, n) {
		prvU[i] = tmp;
		if (s[i] == 'U') {
			tmp = i;
		}
	}
	tmp = -1;
	FORd(i, n, 0) {
		nxtD[i] = tmp;
		if (s[i] == 'D') {
			tmp = i;
		}
	}
	int fu = -1, ld = -1;
	FOR(i, 0, n) {
		if (s[i] == 'U') {
			fu = i;
			break;
		}
	}
	FORd(i, n, 0) {
		if (s[i] == 'D') {
			ld = i;
			break;
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, 2) cnt[j][i + 1] = cnt[j][i];
		if (s[i] == 'U') {
			cnt[0][i + 1]++;
			s0 += i;
			sum[0][++a] = s0;
		}
		else {
			cnt[1][i + 1]++;
			s1 += i;
			sum[1][++b] = s1;
		}
	}
	FOR(i, 0, n) {
		int nl = cnt[0][i];
		int nr = cnt[1][n] - cnt[1][i + 1];
		long long ans = 0;
		if (s[i] == 'U') {
			if (nr > nl) {
				ans += 2 * (sum[1][cnt[1][i + 1] + nl + 1] - sum[1][cnt[1][i + 1]]);
				ans -= 2 * sum[0][nl];
				ans -= i;
			}
			else {
				ans += 2 * (sum[1][cnt[1][i + 1] + nr] - sum[1][cnt[1][i + 1]]);
				ans -= 2 * (sum[0][nl] - sum[0][nl - nr]);
				ans -= i;
				ans += n - 1;
			}
		}
		else {
			if (nr < nl) {
				ans += 2 * (sum[1][cnt[1][i + 1] + nr] - sum[1][cnt[1][i + 1]]);
				ans -= 2 * (sum[0][nl] - sum[0][nl - nr - 1]);
				ans += i;
				ans += n - 1;
			}
			else {
				ans += 2 * (sum[1][cnt[1][i + 1] + nl] - sum[1][cnt[1][i + 1]]);
				ans -= 2 * sum[0][nl];
				ans += i;
			}
		}
		cout << ans + 1 << " \n"[i == n - 1];
	}
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