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
int n, q;
int a[maxn];
int b[maxn];

struct Node {
	double x, y;
	Node() : x(-1), y(-1) {}
	Node(double x, double y) : x(x), y(y) {}
	Node(const Node& rhs) : x(rhs.x), y(rhs.y) {}
} nil;

Node merge(Node a, Node b) {
	if (a.x == nil.x) return b;
	if (b.x == nil.x) return a;
	Node res;
	res.x = a.x * b.x / (1.0 - a.y + a.y * b.x);
	res.y = b.y + (1.0 - b.y) * a.y * b.x / (1.0 - a.y + a.y * b.x);
	return res;
}

Node st[maxn << 2];
void build(int p, int L, int R) {
	if (L == R) {
		st[p].x = st[p].y = 1.0 * a[L] / b[L];
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
void upd(int p, int i, int L, int R) {
	if (i < L || i > R) return;
	if (L == R) {
		st[p].x = st[p].y = 1.0 * a[L] / b[L];
		return;
	}
	upd(p << 1, i, L, L + R >> 1);
	upd(p << 1 | 1, i, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
Node query(int p, int l, int r, int L, int R) {
	if (l > R || r < L) return nil;
	if (l <= L && r >= R) return st[p];
	return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
	cin >> n >> q;
	FOR(i, 0, n) {
		cin >> a[i] >> b[i];
	}
	build(1, 0, n - 1);
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int ix; cin >> ix; ix--;
			cin >> a[ix] >> b[ix];
			upd(1, ix, 0, n - 1);
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			Node res = query(1, l, r, 0, n - 1);
			cout << prec(9) << res.x << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //ofreopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}