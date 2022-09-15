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

const int maxn = 20;
const int maxc = 26;
int n;
int a[maxn][maxn];
int f[maxn << 1][1 << maxn];
bitset<1> vis[maxn << 1][1 << maxn];
int dx[] = {1, 0};
int dy[] = {0, 1};

int inside(int u, int v) {
	if (!(u >= 0 && u < n)) return 0;
	if (!(v >= 0 && v < n)) return 0;
	return 1;
}

int calc(int pos, int msk) {
	if (pos == 2 * n - 2) return 0;
	int& res = f[pos][msk];
	if (vis[pos][msk][0]) return res;
	vis[pos][msk][0] = 1;
	int nmsk[26] = {};
	FOR(i, 0, n) if (bit(msk, i)) {
		int r = i;
		int c = pos - i;
		FOR(j, 0, 2) {
			int nr = r + dx[j];
			int nc = c + dy[j];
			if (inside(nr, nc)) {
				nmsk[a[nr][nc] - 'a'] |= 1 << nr;
			}
		}
	}
	if (!(pos & 1)) {
		res = +INF;
		FOR(i, 0, 26) if (nmsk[i]) {
			int val = 0;
			if (i == 0) val = +1;
			if (i == 1) val = -1;
			chkmin(res, calc(pos + 1, nmsk[i]) + val);
		}
	}
	else {
		res = -INF;
		FOR(i, 0, 26) if (nmsk[i]) {
			int val = 0;
			if (i == 0) val = +1;
			if (i == 1) val = -1;
			chkmax(res, calc(pos + 1, nmsk[i]) + val);
		}
	}
	return res;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) {
		string s; cin >> s;
		FOR(j, 0, n) a[i][j] = s[j];
	}
	int val = 0;
	if (a[0][0] == 'a') val = +1;
	if (a[0][0] == 'b') val = -1;
	int res = calc(0, 1) + val;	
	if (res > 0) {
		cout << "FIRST\n";
	}
	else if (res < 0) {
		cout << "SECOND\n";
	}
	else {
		cout << "DRAW\n";
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