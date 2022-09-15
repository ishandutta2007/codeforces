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

struct Point {
	int x, y, idx;
	Point() {}
	Point(int x, int y, int idx) : x(x), y(y), idx(idx) {}
	Point(const Point& p) : x(p.x), y(p.y), idx(p.idx) {}
	int operator < (Point rhs) {
		return idx < rhs.idx;
	}
};

Point p[4], ans[4];
int dmin;

void check(Point q[]) {
	FOR(i, 0, 4) FOR(j, i + 1, 4) {
		if (q[i].x == q[j].x && q[i].y == q[j].y) {
			return;
		}
	}
	FOR(i, 0, 4) q[i].idx = i;
	do {
		int ok = 1, r = 0;
		FOR(i, 0, 4) {
			if (p[i].x != q[i].x && p[i].y != q[i].y) {
				ok = 0;
				break;
			}
			chkmax(r, abs(p[i].x - q[i].x) + abs(p[i].y - q[i].y));
		}
		if (ok && chkmin(dmin, r)) {
			
			FOR(i, 0, 4) {
				ans[p[i].idx].x = q[i].x;
				ans[p[i].idx].y = q[i].y;
			}
		}
	}
	while (next_permutation(q, q + 4));
}

void check() {
	if (p[0].x == p[1].x && p[2].x == p[3].x) {
		Point q[4];
		int k = abs(p[0].x - p[2].x);
		vi va;
		va.pb(p[0].y); va.pb(p[1].y - k);
		va.pb(p[2].y); va.pb(p[3].y - k);
		sort(all(va));
		int z = (va[0] + va[3]) / 2;
		int t = z + k;
		q[0].x = p[0].x;
		q[0].y = z;
		q[1].x = p[0].x;
		q[1].y = t;
		q[2].x = p[2].x;
		q[2].y = z;
		q[3].x = p[2].x;
		q[3].y = t;
		check(q);
	}
	else if (p[0].y == p[1].y && p[2].y == p[3].y) {
		Point q[4];
		int k = abs(p[0].y - p[2].y);
		vi va;
		va.pb(p[0].x); va.pb(p[1].x - k); va.pb(p[2].x); va.pb(p[3].x - k);
		sort(all(va));
		int z = (va[0] + va[3]) / 2;
		int t = z + k;
		q[0].x = z;
		q[0].y = p[0].y;
		q[1].x = t;
		q[1].y = p[0].y;
		q[2].x = z;
		q[2].y = p[2].y;
		q[3].x = t;
		q[3].y = p[2].y;
		check(q);
	}
}

void check(int x, int y, int z, int t) {
	if (x == z) {
		Point q[4];
		q[0].x = x;
		q[0].y = y;
		q[1].x = z;
		q[1].y = t;
		q[2].x = x + abs(y - t);
		q[2].y = y;
		q[3].x = z + abs(y - t);
		q[3].y = t;
		check(q);
				
		q[0].x = x;
		q[0].y = y;
		q[1].x = z;
		q[1].y = t;
		q[2].x = x - abs(y - t);
		q[2].y = y;
		q[3].x = z - abs(y - t);
		q[3].y = t;
		check(q);
	}
	else if (y == t) {
		Point q[4];
		q[0].x = x;
		q[0].y = y;
		q[1].x = z;
		q[1].y = t;
		q[2].x = x;
		q[2].y = y + abs(x - z);
		q[3].x = z;
		q[3].y = t + abs(x - z);
		check(q);
		
		q[0].x = x;
		q[0].y = y;
		q[1].x = z;
		q[1].y = t;
		q[2].x = x;
		q[2].y = y - abs(x - z);
		q[3].x = z;
		q[3].y = t - abs(x - z);
		check(q);
	}
}

void solve() {
	int T; cin>>T;
	while (T--) {
		FOR(i, 0, 4) cin>>p[i].x>>p[i].y, p[i].idx = i;
		dmin = INF;
		do {
			check();
			
			int x = p[0].x;
			int y = p[1].y;
			int z = p[0].x;
			int t = p[2].y;
			check(x, y, z, t);
			
			x = p[1].x;
			y = p[0].y;
			z = p[2].x;
			t = p[0].y;
			check(x, y, z, t);
			
			x = p[0].x;
			y = p[1].y;
			z = p[2].x;
			t = p[3].y;
			check(x, y, z, t);
		}
		while (next_permutation(p, p + 4));
		if (dmin == INF) {
			cout<<"-1"<<"\n";
		}
		else {
			cout<<dmin<<"\n";
			FOR(i, 0, 4) cout<<ans[i].x<<" "<<ans[i].y<<"\n";
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