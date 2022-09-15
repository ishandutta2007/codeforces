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

struct Node {
	int val;
	Node *l, *r, *u, *d;
	Node() : val(0), l(0), r(0), u(0), d(0) {}
} mem[1100000];

const int maxn = 1000 + 10;
int n, m, q;
int a[maxn][maxn];
Node* node[maxn][maxn];
int ans[maxn][maxn];

void trace(Node* cur, int i, int j) {
	if (~ans[i][j]) return;
	ans[i][j] = cur->val;
	if (cur->l) trace(cur->l, i, j - 1);
	if (cur->r) trace(cur->r, i, j + 1);
	if (cur->u) trace(cur->u, i - 1, j);
	if (cur->d) trace(cur->d, i + 1, j);
}

Node* query(int u, int v) {
	Node* res = node[0][1];
	for (int i = 0; i < u; i++) res = res->d;
	for (int i = 1; i < v; i++) res = res->r;
	return res;
}

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		scanf("%d", &a[i][j]);
	}
	int ptr = 0;
	FOR(i, 0, n + 2) FOR(j, 0, m + 2) {
		node[i][j] = mem + (ptr++);
		node[i][j]->val = a[i][j];
	}
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
		node[i][j]->l = node[i][j - 1], node[i][j - 1]->r = node[i][j];
		node[i][j]->r = node[i][j + 1], node[i][j + 1]->l = node[i][j];
		node[i][j]->u = node[i - 1][j], node[i - 1][j]->d = node[i][j];
		node[i][j]->d = node[i + 1][j], node[i + 1][j]->u = node[i][j];
	}
	while (q--) {
		int a, b, c, d, h, w; scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
		vector<pair<Node*, Node*> > vl, vr, vu, vd;
		Node *x = query(a, b), *y = query(c, d);
		FOR(i, 0, h) {
			vr.pb(mp(x->l, y->l));
			vl.pb(mp(x, y));
			x = x->d, y = y->d;
		}
		x = query(a, b + w - 1), y = query(c, d + w - 1);
		FOR(i, 0, h) {
			vl.pb(mp(x->r, y->r));
			vr.pb(mp(x, y));
			x = x->d, y = y->d;
		}
		x = query(a, b), y = query(c, d);
		FOR(i, 0, w) {
			vd.pb(mp(x->u, y->u));
			vu.pb(mp(x, y));
			x = x->r, y = y->r;
		}
		x = query(a + h - 1, b), y = query(c + h - 1, d);
		FOR(i, 0, w) {
			vu.pb(mp(x->d, y->d));
			vd.pb(mp(x, y));
			x = x->r, y = y->r;
		}
		FOR(i, 0, sz(vl)) swap(vl[i].fi->l, vl[i].se->l);
		FOR(i, 0, sz(vr)) swap(vr[i].fi->r, vr[i].se->r);
		FOR(i, 0, sz(vu)) swap(vu[i].fi->u, vu[i].se->u);
		FOR(i, 0, sz(vd)) swap(vd[i].fi->d, vd[i].se->d);
	}
	ms(ans, -1); trace(node[0][1], 0, 1);
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) printf("%d%c", ans[i][j], " \n"[j == m]);
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