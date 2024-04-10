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

int n;
int cnt;
int x[2], y[2], u[2], v[2];

int ask(int x1, int y1, int x2, int y2) {
	if (x1 < 1 || x1 > n || y1 < 1 || y1 > n || x2 < 1 || x2 > n || y2 < 1 || y2 > n) {
		return 0;
	}
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	cout.flush();
	int k; cin >> k;
	return k;
}

void find1(int p, int q) {
	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;
		int k = ask(p, 1, q, m);
		if (k) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	int z = l;
	l = 1, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		int k = ask(p, m, q, z);
		if (k) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	x[cnt] = p;
	y[cnt] = l;
	u[cnt] = q;
	v[cnt] = z;
	cnt++;
}

void find2(int p, int q) {
	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;
		int k = ask(1, p, m, q);
		if (k) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	int z = l;
	l = 1, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		int k = ask(m, p, z, q);
		if (k) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	x[cnt] = l;
	y[cnt] = p;
	u[cnt] = z;
	v[cnt] = q;
	cnt++;
}

pi find11(int l, int r) {
	int w = l;
	while (l < r) {
		int m = l + r >> 1;
		if (ask(w, 1, m, n)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	int z = l;
	l = w, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (ask(m, 1, z, n)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return mp(l, z);
}

pi find22(int l, int r) {
	int w = l;
	while (l < r) {
		int m = l + r >> 1;
		if (ask(1, w, n, m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	int z = l;
	l = w, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (ask(1, m, n, z)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return mp(l, z);
}

void work1() {
	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;
		if (ask(1, 1, m, n)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	if (!ask(l + 1, 1, n, n)) {
		return;
	}
	int z = l;
	l = 1, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (ask(m, 1, z, n)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	find1(l, z);
	pi rr = find11(l + 1, n);
	find1(rr.fi, rr.se);
}

void work2() {
	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;
		if (ask(1, 1, n, m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	if (!ask(1, l + 1, n, n)) {
		return;
	}
	int z = l;
	l = 1, r = z;
	while (l < r) {
		int m = l + r + 1 >> 1;
		if (ask(1, m, n, z)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	find2(l, z);
	pi rr = find22(l + 1, n);
	find2(rr.fi, rr.se);
}

void solve() {
	cin >> n;
	work1();
	if (!cnt) work2();
	cout << "!";
	FOR(i, 0, 2) {
		cout << " " << x[i] << " " << y[i] << " " << u[i] << " " << v[i];
	}
	cout << "\n";
	cout.flush();
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