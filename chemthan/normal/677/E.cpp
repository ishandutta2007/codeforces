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

#define T int
struct GridModule {
	int n, m;
	vector<vector<int> > a;
	vector<vector<T> > row, col;
	vector<vector<T> > dig[2];
	void init(vector<vector<int> >& x, int k) {
		a = x; n = a.size();
		if (n) m = a[0].size(); else m = 0;
		row.resize(n);
		for (int i = 0; i < n; i++) {
			row[i].clear();
			T tot = 0;
			for (int j = 0; j < m; j++) {
				tot += a[i][j] == k;
				row[i].push_back(tot);
			}
		}
		col.resize(m);
		for (int j = 0; j < m; j++) {
			col[j].clear();
			T tot = 0;
			for (int i = 0; i < n; i++) {
				tot += a[i][j] == k;
				col[j].push_back(tot);
			}
		}
		dig[0].resize(n + m - 1);
		for (int i = 0; i < m; i++) {
			dig[0][i].clear();
			T tot = 0;
			for (int j = 0; j < min(i + 1, n); j++) {
				tot += a[j][i - j] == k;
				dig[0][i].push_back(tot);
			}
		}
		for (int i = 1; i < n; i++) {
			dig[0][i + m - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(n - i, m); j++) {
				tot += a[i + j][m - j - 1] == k;
				dig[0][i + m - 1].push_back(tot);
			}
		}
		dig[1].resize(n + m - 1);
		for (int i = m - 1; i >= 0; i--) {
			dig[1][m - i - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(m - i, n); j++) {
				tot += a[j][i + j] == k;
				dig[1][m - i - 1].push_back(tot);
			}
		}
		for (int i = 1; i < n; i++) {
			dig[1][i + m - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(n - i, m); j++) {
				tot += a[i + j][j] == k;
				dig[1][i + m - 1].push_back(tot);
			}
		}
	}
	T rowsum(int x, int y, int z) {
		if (y > z) swap(y, z);
		return row[x][z] - (y ? row[x][y - 1] : 0);
	}
	T colsum(int x, int y, int z) {
		if (y > z) swap(y, z);
		return col[x][z] - (y ? col[x][y - 1] : 0);
	}
	T diagonal(int x, int y, int z, int t) {
		if (x > z) {
			swap(x, z);
			swap(y, t);
		}
		if (x + y == z + t) {
			int u = x + y;
			if (u >= m) {
				x = m - y - 1;
				z = m - t - 1;
			}
			return dig[0][u][z] - (x ? dig[0][u][x - 1] : 0);
		}
		else if (x - y == z - t) {
			int u = m + x - y - 1;
			if (u >= m) {
				x = y;
				z = t;
			}
			return dig[1][u][z] - (x ? dig[1][u][x - 1] : 0);
		}
		return 0;
	}
} gr[4];

const int maxn = 2010;
int n;
char s[maxn];
int row[maxn];
int col[maxn];
ld p2[maxn];
ld p3[maxn];
int pp2[maxn];
int pp3[maxn];

void solve() {
	p2[0] = p3[0] = 1;
	FOR(i, 1, maxn) p2[i] = p2[i - 1] * 2, p3[i] = p3[i - 1] * 3;
	pp2[0] = pp3[0] = 1;
	FOR(i, 1, maxn) pp2[i] = mult(pp2[i - 1], 2), pp3[i] = mult(pp3[i - 1], 3);
	scanf("%d", &n);
	vector<vi> a(n, vi(n, 0));
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, n) a[i][j] = s[j] - '0';
	}
	FOR(i, 0, 4) gr[i].init(a, i);
	pair<ld, int> ans;
	FOR(i, 0, n) FOR(j, 0, n) if (a[i][j]) {
		int lo = 0, hi = i;
		chkmin(hi, n - i - 1);
		chkmin(hi, j);
		chkmin(hi, n - j - 1);
		while (lo < hi) {
			int mi = lo + hi + 1 >> 1;
			if (!gr[0].rowsum(i, j - mi, j + mi) && !gr[0].colsum(j, i - mi, i + mi)) {
				lo = mi;
			}
			else {
				hi = mi - 1;
			}
		}
		int n2 = gr[2].rowsum(i, j - lo, j + lo) + gr[2].colsum(j, i - lo, i + lo);
		int n3 = gr[3].rowsum(i, j - lo, j + lo) + gr[3].colsum(j, i - lo, i + lo);
		if (a[i][j] == 2) n2--;
		if (a[i][j] == 3) n3--;
		chkmax(ans, mp(p2[n2] * p3[n3], mult(pp2[n2], pp3[n3])));
		lo = 0, hi = i;
		chkmin(hi, n - i - 1);
		chkmin(hi, j);
		chkmin(hi, n - j - 1);
		while (lo < hi) {
			int mi = lo + hi + 1 >> 1;
			if (!gr[0].diagonal(i - mi, j - mi, i + mi, j + mi) && !gr[0].diagonal(i - mi, j + mi, i + mi, j - mi)) {
				lo = mi;
			}
			else {
				hi = mi - 1;
			}
		}
		n2 = gr[2].diagonal(i - lo, j - lo, i + lo, j + lo) + gr[2].diagonal(i - lo, j + lo, i + lo, j - lo);
		n3 = gr[3].diagonal(i - lo, j - lo, i + lo, j + lo) + gr[3].diagonal(i - lo, j + lo, i + lo, j - lo);
		if (a[i][j] == 2) n2--;
		if (a[i][j] == 3) n3--;
		chkmax(ans, mp(p2[n2] * p3[n3], mult(pp2[n2], pp3[n3])));
	}
	printf("%d\n", ans.se);
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