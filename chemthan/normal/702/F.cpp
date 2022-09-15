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

const int MAXN = 5000000 + 10;
int ptr;
struct Node {
	Node *l, *r;
	int key, id, size, lz, lz2;
	int cnt;
} mem[MAXN], *nil = mem + (ptr++);
void init() {
	srand(time(NULL));
	nil->l = nil->r = nil;
	nil->size = nil->cnt = 0;
}
int rd() {
	static int seed = 0;
	seed = (seed * 1001 + 100621) % 999983;
	return seed;
}
void pushup(Node* x) {
	if (x == nil) return;
	x->size = x->l->size + 1 + x->r->size;
}
Node* newNode(int key, int id, Node* l = nil, Node* r = nil) {
	Node* x = mem + (ptr++);
	x->l = l, x->r = r, x->key = key, x->id = id;
	x->lz = x->lz2 = 0;
	pushup(x);
	return x;
}
void updlz(Node* x, int val) {
	if (x == nil) return;
	x->key += val;
	x->lz += val;
}
void updlz2(Node* x, int val) {
	if (x == nil) return;
	x->cnt += val;
	x->lz2 += val;
}
void pushdown(Node* x) {
	if (x->lz) {
		updlz(x->l, x->lz);
		updlz(x->r, x->lz);
		x->lz = 0;
	}
	if (x->lz2) {
		updlz2(x->l, x->lz2);
		updlz2(x->r, x->lz2);
		x->lz2 = 0;
	}
}
Node* join(Node* l, Node* r) {
	if (l == nil) return r;
	if (r == nil) return l;
	if (rand() % (l->size + r->size) < l->size) {
		pushdown(l);
		l->r = join(l->r, r);
		pushup(l);
		return l;
	}
	pushdown(r);
	r->l = join(l, r->l);
	pushup(r);
	return r;
}
pair<Node*, Node*> splitkey(Node* x, int key) {
	if (x == nil) return make_pair(nil, nil);
	pushdown(x);
	if (x->key < key) {
		pair<Node*, Node*> res = splitkey(x->r, key);
		x->r = res.first;
		pushup(x);
		return make_pair(x, res.second);
	}
	else {
		pair<Node*, Node*> res = splitkey(x->l, key);
		x->l = res.second;
		pushup(x);
		return make_pair(res.first, x);
	}
}
int mintree(Node* x) {
	if (x == nil) return +INF;
	pushdown(x);
	if (x->l != nil) return min(x->key, mintree(x->l));
	return x->key;
}
int maxtree(Node* x) {
	if (x == nil) return -INF;
	pushdown(x);
	if (x->r != nil) return max(x->key, maxtree(x->r));
	return x->key;
}

const int maxn = 200000 + 10;
int n, k;
int c[maxn];
int q[maxn];
int b[maxn];
int ans[maxn];
Node* root = nil;

int compare(int i, int j) {
	if (q[i] != q[j]) return q[i] > q[j];
	if (c[i] != c[j]) return c[i] < c[j];
	return i < j;
}

void upd(int val) {
	pair<Node*, Node*> r = splitkey(root, val);
	Node* x = r.fi;
	Node* y = r.se;
	updlz(y, -val);
	updlz2(y, 1);
	int mn;
	while (maxtree(x) > (mn = mintree(y))) {
		pair<Node*, Node*> r1 = splitkey(y, mn + 1);
		pair<Node*, Node*> r2 = splitkey(x, mn);
		x = join(join(r2.fi, r1.fi), r2.se);
		y = r1.se;
	}
	root = join(x, y);
}

void trace(Node* x) {
	if (x == nil) return;
	pushdown(x);
	ans[x->id] = x->cnt;
	trace(x->l);
	trace(x->r);
}

void solve() {
	init();
	cin >> n;
	vi v;
	FOR(i, 0, n) cin >> c[i] >> q[i], v.pb(i);
	sort(all(v), compare);
	cin >> k;
	vii vv;
	FOR(i, 0, k) {
		cin >> b[i];
		vv.pb(mp(b[i], i));
	}
	sort(all(vv));
	FOR(i, 0, k) {
		int key = vv[i].fi;
		int id = vv[i].se;
		root = join(root, newNode(key, id));
	}
	FOR(j, 0, sz(v)) {
		int i = v[j];
		upd(c[i]);
	}
	trace(root);
	FOR(i, 0, k) cout << ans[i] << " \n"[i == k - 1];
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