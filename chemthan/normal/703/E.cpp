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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 1000 + 10;
const int maxd = 7000 + 10;
int n;
long long k;
long long a[maxn];
vector<long long> dvs;
int hs[maxn * 100];
pair<int, long long> f[maxn][maxd];
int r[maxn][maxd];

void solve() {
	cin >> n >> k;
	for (int i = 1; (long long) i * i <= k; i++) {
		if (k % i == 0) {
			dvs.pb(i);
			if (i < k / i) {
				dvs.pb(k / i);
			}
		}
	}
	sort(all(dvs));
	int magic = 100000;
	while (1) {
		int found = 0;
		FOR(i, 0, sz(dvs)) {
			int u = dvs[i] % magic;
			if (hs[u] == magic) {
				found = 1;
				break;
			}
			hs[u] = magic;
		}
		if (!found) break;
		magic--;
	}
	FOR(i, 0, sz(dvs)) hs[dvs[i] % magic] = i;
	FOR(i, 0, n) cin >> a[i];
	if (k == 1) {
		cout << 1 << "\n";
		int best = 0;
		FOR(i, 1, n) if (a[best] > a[i]) best = i;
		cout << best + 1 << "\n";
		return;
	}
	FOR(i, 0, n + 1) FOR(j, 1, sz(dvs)) f[i][j] = mp(INF, 0);
	FORd(pos, n, 0) FOR(i, 1, sz(dvs)) {
		f[pos][i] = f[pos + 1][i];
		int nxt = hs[dvs[i] / __gcd(dvs[i], a[pos]) % magic];
		if (chkmin(f[pos][i], mp(f[pos + 1][nxt].fi + 1, f[pos + 1][nxt].se + a[pos]))) {
			r[pos][i] = 1;
		}
	}
	k = sz(dvs) - 1;
	int ans = f[0][k].fi;
	if (ans == INF) {
		cout << -1 << "\n";
		return;
	}
	cout << ans << "\n";
	int cur = 0;
	while (cur < n) {
		if (r[cur][k]) {
			cout << cur + 1 << " ";
			k = hs[dvs[k] / __gcd(dvs[k], a[cur]) % magic];
		}
		cur++;
	}
	cout << "\n";
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