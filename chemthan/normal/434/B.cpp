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

const int maxn = 1010;
int n, m, q;
int a[maxn][maxn];

struct Fenwick {
	int fen[maxn];
	void update(int p, int val) {
		for (; p < maxn; p += p & -p) {
			fen[p] += val;
		}
	}
	int query(int p) {
		int res = 0;
		for (; p > 0; p -= p & -p) {
			res += fen[p];
		}
		return res;
	}
} row[maxn], col[maxn];

int queryrow(int u, int x, int y) {
	return row[u].query(y) - row[u].query(x - 1);
}

int querycol(int u, int x, int y) {
	return col[u].query(y) - col[u].query(x - 1);
}

void solve() {
	cin>>n>>m>>q;
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		cin>>a[i][j]; a[i][j] ^= 1;
		row[i].update(j, a[i][j]);
		col[j].update(i, a[i][j]);
	}
	while (q--) {
		int op, x, y; cin>>op>>x>>y;
		if (op == 1) {
			row[x].update(y, -a[x][y]);
			col[y].update(x, -a[x][y]);
			a[x][y] ^= 1;
			row[x].update(y, a[x][y]);
			col[y].update(x, a[x][y]);
		}
		else {
			if (a[x][y]) {
				cout<<0<<"\n";
			}
			else {
				int _up = x, _down = x, _left = y, _right = y;
				while (_up <= n && !a[_up][y]) _up++; _up--;
				while (_down && !a[_down][y]) _down--; _down++;
				while (_right <= m && !a[x][_right]) _right++; _right--;
				while (_left && !a[x][_left]) _left--; _left++;
				int res = max(_up - _down + 1, _right - _left + 1);
				int up = _up, down = _down;
				FOR(i, y + 1, m + 1) {
					while (up >= x && querycol(i, x, up)) up--;
					if (up < x) break;
					while (down <= x && querycol(i, down, x)) down++;
					if (down > x) break;
					chkmax(res, (up - down + 1) * (i - y + 1));
				}
				up = _up, down = _down;
				FORd(i, y, 1) {
					while (up >= x && querycol(i, x, up)) up--;
					if (up < x) break;
					while (down <= x && querycol(i, down, x)) down++;
					if (down > x) break;
					chkmax(res, (up - down + 1) * (y - i + 1));
				}
				int right = _right, left = _left;
				FOR(i, x + 1, n + 1) {
					while (right >= y && queryrow(i, y, right)) right--;
					if (right < y) break;
					while (left <= y && queryrow(i, left, y)) left++;
					if (left > y) break;
					chkmax(res, (right - left + 1) * (i - x + 1));
				}
				right = _right, left = _left;
				FORd(i, x, 1) {
					while (right >= y && queryrow(i, y, right)) right--;
					if (right < y) break;
					while (left <= y && queryrow(i, left, y)) left++;
					if (left > y) break;
					chkmax(res, (right - left + 1) * (x - i + 1));
				}
				cout<<res<<"\n";
			}
		}
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