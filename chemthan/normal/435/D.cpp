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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

typedef int T;
struct GridModule {
	int n, m;
	vector<vector<int> > a;
	vector<vector<int> > sum;
	vector<vector<T> > row, col;
	vector<vector<T> > dig[2];
	void init(vector<vector<int> >& x) {
		a = x; n = a.size();
		if (n) m = a[0].size(); else m = 0;
		sum.resize(n);
		for (int i = 0; i < n; i++) {
			sum[i].clear();
			for (int j = 0; j < m; j++) {
				T t = a[i][j];
				if (i) {
					t += sum[i - 1][j];
				}
				if (j) {
					t += sum[i][j - 1];
				}
				if (i && j) {
					t -= sum[i - 1][j - 1];
				}
				sum[i].push_back(t);
			}
		}
		row.resize(n);
		for (int i = 0; i < n; i++) {
			row[i].clear();
			T tot = 0;
			for (int j = 0; j < m; j++) {
				tot += a[i][j];
				row[i].push_back(tot);
			}
		}
		col.resize(m);
		for (int j = 0; j < m; j++) {
			col[j].clear();
			T tot = 0;
			for (int i = 0; i < n; i++) {
				tot += a[i][j];
				col[j].push_back(tot);
			}
		}
		dig[0].resize(n + m - 1);
		for (int i = 0; i < m; i++) {
			dig[0][i].clear();
			T tot = 0;
			for (int j = 0; j < min(i + 1, n); j++) {
				tot += a[j][i - j];
				dig[0][i].push_back(tot);
			}
		}
		for (int i = 1; i < n; i++) {
			dig[0][i + m - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(n - i, m); j++) {
				tot += a[i + j][m - j - 1];
				dig[0][i + m - 1].push_back(tot);
			}
		}
		dig[1].resize(n + m - 1);
		for (int i = m - 1; i >= 0; i--) {
			dig[1][m - i - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(m - i, n); j++) {
				tot += a[j][i + j];
				dig[1][m - i - 1].push_back(tot);
			}
		}
		for (int i = 1; i < n; i++) {
			dig[1][i + m - 1].clear();
			T tot = 0;
			for (int j = 0; j < min(n - i, m); j++) {
				tot += a[i + j][j];
				dig[1][i + m - 1].push_back(tot);
			}
		}
	}
	T getsum(int x, int y, int z, int t) {
		if (x > z) {
			swap(x, z);
			swap(y, t);
		}
		T res = sum[z][t];
		if (x) {
			res -= sum[x - 1][t];
		}
		if (y) {
			res -= sum[z][y - 1];
		}
		if (x && y) {
			res += sum[x - 1][y - 1];
		}
		return res;
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
} gm;

const int maxn = 410;
int n, m;
vector<vi> a;

void solve() {
	cin>>n>>m;
	a.resize(n, vi(m, 0));
	FOR(i, 0, n) {
		string s; cin>>s;
		FOR(j, 0, m) a[i][j] = s[j] == '1';
	}
	gm.init(a);
	int ans = 0;
	FOR(i, 0, n) FOR(j, 0, m) {
		FOR(k, 1, n) {
			if (i - k < 0 || j - k < 0 || j + k >= m) {
				break;
			}
			if (!gm.rowsum(i - k, j - k, j + k) && !gm.diagonal(i, j, i - k, j - k) && !gm.diagonal(i, j, i - k, j + k)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i + k >= n || j - k < 0 || j + k >= m) {
				break;
			}
			if (!gm.rowsum(i + k, j - k, j + k) && !gm.diagonal(i, j, i + k, j - k) && !gm.diagonal(i, j, i + k, j + k)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i + k >= n || i - k < 0 || j - k < 0) {
				break;
			}
			if (!gm.colsum(j - k, i - k, i + k) && !gm.diagonal(i, j, i - k, j - k) && !gm.diagonal(i, j, i + k, j - k)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i - k < 0 || i + k >= n || j + k >= m) {
				break;
			}
			if (!gm.colsum(j + k, i - k, i + k) && !gm.diagonal(i, j, i - k, j + k) && !gm.diagonal(i, j, i + k, j + k)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i - k < 0 || j - k < 0) {
				break;
			}
			if (!gm.rowsum(i, j - k, j) && !gm.colsum(j, i - k, i) && !gm.diagonal(i, j - k, i - k, j)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i - k < 0 || j + k >= m) {
				break;
			}
			if (!gm.rowsum(i, j, j + k) && !gm.colsum(j, i - k, i) && !gm.diagonal(i - k, j, i, j + k)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i + k >= n || j - k < 0) {
				break;
			}
			if (!gm.rowsum(i, j - k, j) && !gm.colsum(j, i, i + k) && !gm.diagonal(i, j - k, i + k, j)) {
				ans++;
			}
		}
		FOR(k, 1, n) {
			if (i + k >= n || j + k >= m) {
				break;
			}
			if (!gm.rowsum(i, j, j + k) && !gm.colsum(j, i, i + k) && !gm.diagonal(i, j + k, i + k, j)) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
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