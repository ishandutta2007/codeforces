#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

typedef vector<int> ROW;
typedef vector<ROW> MATRIX;
int MatrixDeterminant(MATRIX a, ROW& r, int mod = (int) 1e9 + 7) {
	int i, j, k, n = a.size(), m = a[0].size();
	int res = 1;
	for (i = 0; i < n; i++) {
		if (!a[i][i]) {
			for (j = i + 1; j < n; j++) {
				if (a[j][i]) {
					for (k = 0; k < m; k++) {
						a[i][k] = a[i][k] + a[j][k];
						if (a[i][k] >= mod) a[i][k] -= mod;
					}
					break;
				}
			}
			if (j == n) return 0;
		}
		int tmp = a[i][i], itmp = inv(tmp, mod);
		for (k = 0; k < m; k++) a[i][k] = (long long) a[i][k] * itmp % mod;
		res = (long long) res * tmp % mod;
		for (j = 0; j < n; j++) {
			if (j == i) continue;
			tmp = a[j][i];
			for (k = 0; k < m; k++) {
				a[j][k] -= (long long) a[i][k] * tmp % mod;
				if (a[j][k] < 0) a[j][k] += mod;
			}
		}
	}
	r.clear();
	for (int i = 0; i < n; i++) {
		r.push_back(a[i][n]);
	}
	return res;
}

const int maxn = 200 + 5;
int n;
int a[maxn][maxn];
int b[maxn][maxn];
int f[maxn];

void chemthan() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        a[u][v]++, a[v][u]++;
        b[u][v]--, b[v][u]--;
    }
    FOR(i, 0, n) FOR(j, 0, n) if (i != j) {
        b[i][j]++;
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) if (i != j) addmod(a[i][i], a[i][j]);
        FOR(j, 0, n) if (i != j) addmod(b[i][i], b[i][j]);
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) if (i != j) a[i][j] = (MOD - a[i][j]) % MOD;
        FOR(j, 0, n) if (i != j) b[i][j] = (MOD - b[i][j]) % MOD;
    }
    FOR(k, 0, n) {
        MATRIX mat(n - 1, ROW(n - 1, 0));
        FOR(i, 0, n - 1) FOR(j, 0, n - 1) {
            mat[i][j] = a[i][j];
            addmod(mat[i][j], mult(b[i][j], k));
        }
        ROW r; f[k] = MatrixDeterminant(mat, r);
    }
    MATRIX mat(n, ROW(n + 1, 0));
    FOR(i, 0, n) {
        FOR(j, 0, n) mat[i][j] = fpow(i, j);
        mat[i][n] = f[i];
    }
    ROW r; MatrixDeterminant(mat, r);
    FOR(i, 0, n) cout << r[n - i - 1] << " \n"[i == n - 1];
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}