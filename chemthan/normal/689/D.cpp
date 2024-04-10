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

const int MAXN = 200010;
const int MAXE = 20;

struct RMQ {
	int n;
	int a[MAXN];
	int f[MAXN][MAXE];
	void build() {
		for (int i = 0; i < n; i++) f[i][0] = a[i];
		for (int l = 0, k; (k = 1 << l) < n; l++) {
			for (int i = 0; i + k < n; i++) {
				f[i][l + 1] = min(f[i][l], f[i + k][l]);
			}
		}
	}
	int query(int a, int b) {
		int l = a == b ? 0 : __lg(b - a);
		return min(f[a][l], f[b - (1 << l) + 1][l]);
	}
} rmq;

const int maxn = 200010;
int n;
int a[maxn];
int b[maxn];
int l[maxn];
int r[maxn];
int LL[maxn];
int rr[maxn];
int xx[maxn];
int yy[maxn];
map<int, int> lst;

void processleft(int u) {
	int l = 0, r = u + 1;
	while (l < r) {
		int m = l + r >> 1;
		if (rmq.query(m, u) < a[u]) l = m + 1; else r = m;
	}
	LL[u] = l;
}

void prcessright(int u) {
	int l = u - 1, r = n - 1;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (rmq.query(u, m) >= a[u]) l = m; else r = m - 1;
	}
	rr[u] = l;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	rmq.n = n;
	FOR(i, 0, n) {
		cin >> b[i];
		rmq.a[i] = b[i];
	}
	rmq.build();
	FOR(i, 0, n) l[i] = r[i] = i;
	FOR(i, 1, n) {
		int cur = i;
		while (cur && a[i] >= a[cur - 1]) cur = l[cur - 1];
		l[i] = cur;
	}
	FORd(i, n - 1, 0) {
		int cur = i;
		while (cur < n - 1 && a[i] > a[cur + 1]) cur = r[cur + 1];
		r[i] = cur;
	}
	FOR(i, 0, n) {
		processleft(i);
		prcessright(i);
	}
	FOR(i, 0, n) {
		lst[b[i]] = i;
		if (lst.count(a[i])) {
			int k = lst[a[i]];
			if (rmq.query(k, i) == a[i]) {
				xx[i] = k;
			}
			else {
				xx[i] = i + 1;
			}
		}
		else {
			xx[i] = i + 1;
		}
	}
	lst.clear();
	FORd(i, n, 0) {
		lst[b[i]] = i;
		if (lst.count(a[i])) {
			int k = lst[a[i]];
			if (rmq.query(i, k) == a[i]) {
				yy[i] = k;
			}
			else {
				yy[i] = i - 1;
			}
		}
		else {
			yy[i] = i - 1;
		}
	}
	long long ans = 0;
	FOR(i, 0, n) {
		if (LL[i] > i) continue;
		if (rr[i] < i) continue;
		chkmax(LL[i], l[i]);
		chkmin(rr[i], r[i]);
		if (xx[i] <= i && xx[i] >= l[i] && yy[i] >= i && yy[i] <= r[i]) {
			ans += (long long) (i - LL[i] + 1) * (rr[i] - yy[i] + 1);
			ans += (long long) (xx[i] - LL[i] + 1) * (rr[i] - i + 1);
			ans -= (long long) (xx[i] - LL[i] + 1) * (rr[i] - yy[i] + 1);
		}
		else if (xx[i] <= i && xx[i] >= l[i]) {
			ans += (long long) (xx[i] - LL[i] + 1) * (rr[i] - i + 1);
		}
		else if (yy[i] >= i && yy[i] <= r[i]) {
			ans += (long long) (i - LL[i] + 1) * (rr[i] - yy[i] + 1);
		}
	}
	cout << ans << "\n";
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