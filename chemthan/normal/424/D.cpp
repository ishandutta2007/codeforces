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

const int maxn = 310;
int n, m, t;
int tp, tu, td;
int a[maxn][maxn];
int row[2][maxn][maxn];
int col[2][maxn][maxn];

void solve() {
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d", &tp, &tu, &td);
	FOR(i, 0, n) FOR(j, 0, m) scanf("%d", &a[i][j]);
	FOR(i, 0, n) {
		FOR(j, 1, m) {
			row[0][i][j] = row[0][i][j - 1];
			row[0][i][j] += a[i][j] == a[i][j - 1] ? tp : a[i][j] > a[i][j - 1] ? tu : td;
			row[1][i][j] = row[1][i][j - 1];
			row[1][i][j] += a[i][j] == a[i][j - 1] ? tp : a[i][j] < a[i][j - 1] ? tu : td;
		}
	}
	FOR(j, 0, m) {
		FOR(i, 1, n) {
			col[0][j][i] = col[0][j][i - 1];
			col[0][j][i] += a[i][j] == a[i - 1][j] ? tp : a[i][j] > a[i - 1][j] ? tu : td;
			col[1][j][i] = col[1][j][i - 1];
			col[1][j][i] += a[i][j] == a[i - 1][j] ? tp : a[i][j] < a[i - 1][j] ? tu : td;
		}
	}
	int dmin = INF << 1; vi ans;
	FOR(i, 0, m) FOR(j, i + 2, m) {
		vii vx; vi vy;
		vx.pb(mp(0, 0)); vy.pb(0);
		FOR(l, 0, n - 1) {
			int t = row[0][l + 1][j] - row[0][l + 1][i];
			t -= row[0][l][j] - row[0][l][i];
			t -= a[l + 1][j] == a[l][j] ? tp : a[l + 1][j] > a[l][j] ? tu : td;
			t -= a[l + 1][i] == a[l][i] ? tp : a[l + 1][i] < a[l][i] ? tu : td;
			vx.pb(mp(t, l + 1));
			t = row[0][0][j] - row[0][0][i];
			t += col[0][j][l + 1] - col[0][j][0];
			t += row[1][l + 1][j] - row[1][l + 1][i];
			t += col[1][i][l + 1] - col[1][i][0];
			vy.pb(t);
		}
		FOR(l, 0, sz(vx) - 1) {
			vx[l + 1].fi += vx[l].fi;
		}
		set<pi> st;
		FOR(l, 2, n) {
			st.insert(vx[l - 2]);
			set<pi>::iterator it = st.lower_bound(mp(t - vy[l], -INF));
			if (it != st.end()) {
				if (chkmin(dmin, abs(vy[l] + it->fi - t))) {
					ans.clear();
					ans.pb(it->se); ans.pb(i);
					ans.pb(l); ans.pb(j);
				}
			}
			if (it != st.begin()) {
				it--;
				if (chkmin(dmin, abs(vy[l] + it->fi - t))) {
					ans.clear();
					ans.pb(it->se); ans.pb(i);
					ans.pb(l); ans.pb(j);
				}
			}
		}
	}
	FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
	printf("\n");
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