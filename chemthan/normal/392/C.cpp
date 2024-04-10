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
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

struct matrix {
	static const int MAXN = 2;
	static const int MOD = (int) 1e9 + 7;
	int x[MAXN][MAXN];
	
	matrix() {
		memset(x, 0, sizeof(x));
	}
	matrix unit() {
		matrix res;
		for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
		return res;
	}
	matrix operator + (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = x[i][j] + A.x[i][j];
			if (res.x[i][j] >= MOD) res.x[i][j] -= MOD;
		}
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = (res.x[i][j] + (long long) x[i][k] * A.x[k][j]) % MOD;
		}
		return res;
	}
	matrix operator ^ (long long k) {
		if (!k) return unit();
		matrix res, tmp;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = tmp.x[i][j] = x[i][j];
		}
		k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
	friend matrix sumpower(matrix A, long long k) {
		if (k == 1) return A;
		vector<int> bit;
		while (k) {
			bit.push_back(k & 1);
			k >>= 1;
		}
		matrix res = A, tmp = A;
		for (int i = bit.size() - 2; i >= 0; i--) {
			res = res + (res * tmp);
			tmp = tmp * tmp;
			if (bit[i] & 1) {
				tmp = tmp * A;
				res = res + tmp;
			}
		}
		return res;
	}
} A;

const int maxk = 40 + 10;
long long n;
int k;
int c[maxk][maxk];
int f[maxk];

int calc(int k) {
	if (!k) {
		matrix B = A ^ (n + 2);
		int res = B.x[0][0];
		submod(res, 2);
		return res;
	}
	int& res = f[k];
	if (~res) return res;
	res = 0;
	FOR(i, 0, k) {
		int tmp = fpow(MOD - 1, k - i);
		submod(tmp, fpow(MOD - 2, k - i));
		tmp = mult(tmp, c[i][k]);
		submod(res, mult(tmp, calc(i)));
	}
	matrix B = A ^ (n + 2);
	int tmp = B.x[0][0];
	tmp = mult(tmp, fpow(n % MOD, k));
	submod(tmp, fpow(MOD - 1, k));
	addmod(res, tmp);
	tmp = fpow(n % MOD, k);
	submod(tmp, fpow((n - 1) % MOD, k));
	B = A ^ (n + 1);
	tmp = mult(tmp, B.x[0][0]);
	submod(res, tmp);
	return res;
}

void solve() {
	FOR(i, 0, maxk) c[0][i] = 1;
	FOR(i, 1, maxk) FOR(j, 1, maxk) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD;
	A.x[0][0] = A.x[0][1] = A.x[1][0] = 1;
	cin >> n >> k;
	ms(f, -1);
	cout << calc(k) << "\n";
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