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

const int maxn = 100000 + 10;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int fa[maxn];
int fb[maxn];
int fc[maxn];
int cnt[3 * maxn];
vi v;

int st[maxn << 2];
int mx[maxn << 2];
int lz[maxn << 2];
void build(int p, int L, int R) {
	if (L == R) {
		st[p] = L;
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = min(st[p << 1], st[p << 1 | 1]);
}
void updlz(int p, int L, int R) {
	if (lz[p]) {
		chkmax(mx[p], lz[p]);
		st[p] = mx[p] + L;
		if (L < R) {
			chkmax(lz[p << 1], lz[p]);
			chkmax(lz[p << 1 | 1], lz[p]);
		}
		lz[p] = 0;
	}
}
void upd(int p, int l, int r, int L, int R, int val) {
	updlz(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[p] = val;
		updlz(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int query(int p, int l, int r, int L, int R) {
	updlz(p, L, R);
	if (l > R || r < L) return INF;
	if (l <= L && r >= R) return st[p];
	return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

int rmq[maxn << 1];
int upd(int p, int n, int val) {
	for (chkmax(rmq[p += n], val); p > 1; ) p >>= 1, rmq[p] = max(rmq[p << 1], rmq[p << 1 | 1]);
}
int query(int l, int r, int n) {
	int res = 0;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) chkmax(res, rmq[l++]);
		if (r & 1) chkmax(res, rmq[--r]);
	}
	return res;
}

void insert(int x, int y) {
	if (query(x, n + 1, n + 2) >= y) return;
	int l = 0, r = x;
	while (l < r) {
		int m = l + r >> 1;
		if (query(m, x, n + 2) >= y) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	upd(x, n + 2, y);
	upd(1, l, x, 0, n + 1, y);
}

int calc() {
	int res = INF;
	FOR(i, 0, n) cnt[a[i]]++;
	build(1, 0, n + 1);
	FOR(i, 0, sz(v)) if (!cnt[i]) {
		int x = fb[i];
		int y = fc[i];
		if (!x && !y) {
			return res;
		}
		else if (!x) {
			insert(n + 1, y);
		}
		else if (!y) {
			insert(x - 1, INF);
		}
		else {
			insert(x - 1, y);
		}
	}
	chkmin(res, st[1] + n);
	FORd(i, n, 0) {
		if (!(--cnt[a[i]])) {
			int x = fb[a[i]];
			int y = fc[a[i]];
			if (!x && !y) {
				return res;
			}
			else if (!x) {
				insert(n + 1, y);
			}
			else if (!y) {
				insert(x - 1, INF);
			}
			else {
				insert(x - 1, y);
			}
		}
		chkmin(res, st[1] + i);
	}
	return res;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i], v.pb(a[i]);
	FOR(i, 0, n) cin >> b[i], v.pb(b[i]);
	FOR(i, 0, n) cin >> c[i], v.pb(c[i]);
	sort(all(v)), uni(v);
	FOR(i, 0, n) {
		a[i] = lower_bound(all(v), a[i]) - v.begin();
		b[i] = lower_bound(all(v), b[i]) - v.begin();
		c[i] = lower_bound(all(v), c[i]) - v.begin();
	}
	FOR(i, 0, n) {
		if (!fa[a[i]]) {
			fa[a[i]] = i + 1;
		}
		if (!fb[b[i]]) {
			fb[b[i]] = i + 1;
		}
		if (!fc[c[i]]) {
			fc[c[i]] = i + 1;
		}
	}
	cout << calc() << "\n";
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