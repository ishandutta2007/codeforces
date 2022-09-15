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

struct Node {
	long long emn, omn, dif;
	Node() : emn(LINF), omn(LINF), dif(0) {}
	Node(const Node& rhs) : emn(rhs.emn), omn(rhs.omn), dif(rhs.dif) {}
} nil;

Node merge(Node a, Node b) {
	if (a.emn == nil.emn) return b;
	if (b.emn == nil.emn) return a;
	Node res;
	res.emn = b.emn + a.dif;
	res.omn = b.omn - a.dif;
	chkmin(res.emn, a.emn);
	chkmin(res.omn, a.omn);
	res.dif = a.dif + b.dif;
	return res;
}

const int maxn = 200000 + 10;
int n, q;
int a[maxn];

Node st[maxn << 2];
long long lz[maxn << 2];
void build(int p, int L, int R) {
	if (L == R) {
		if (!(L & 1)) {
			st[p].emn = a[L];
			st[p].omn = 0;
			st[p].dif = a[L];
		}
		else {
			st[p].emn = 0;
			st[p].omn = a[L];
			st[p].dif = -a[L];
		}
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
void updlz(int p, int L, int R) {
	if (lz[p]) {
		if (!(L & 1)) {
			st[p].emn += lz[p];
		}
		else {
			st[p].omn += lz[p];
		}
		if ((R - L + 1) & 1) {
			if (!(L & 1)) {
				st[p].dif += lz[p];
			}
			else {
				st[p].dif -= lz[p];
			}
		}
		if (L < R) {
			lz[p << 1] += lz[p];
			lz[p << 1 | 1] += lz[p];
		}
		lz[p] = 0;
	}
}
void upd(int p, int l, int r, int L, int R, int val) {
	updlz(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[p] += val;
		updlz(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
Node query(int p, int l, int r, int L, int R) {
	updlz(p, L, R);
	if (l > R || r < L) return nil;
	if (l <= L && r >= R) return st[p];
	return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	build(1, 0, n - 1);
	cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, v, k; cin >> u >> v >> k;
			upd(1, u, v, 0, n - 1, k);
		}
		else {
			int u, v; cin >> u >> v;
			Node x = query(1, u, v, 0, n - 1);
			if (u & 1) {
				x.omn--;
			}
			else {
				x.emn--;
			}
			if (!((v - u + 1) & 1)) {
				if (x.dif != 0) {
					cout << 0 << "\n";
					continue;
				}
			}
			else {
				if (v & 1) {
					x.dif *= -1;
				}
				if (x.dif != 1) {
					cout << 0 << "\n";
					continue;
				}
			}
			if (x.omn < 0 || x.emn < 0) {
				cout << 0 << "\n";
			}
			else {
				cout << 1 << "\n";
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