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

struct Node {
	Node();
	Node *l, *r, *p;
	int size, root, key, cnt;
	int rev, lz;
	pi val, max;
};
Node* nil = new Node();
Node::Node() {
	l = r = p = nil;
	size = root = cnt = 1;
	key = rev = lz = 0;
	val = max = mp(-1, -1);
}
void init() {
	nil->size = nil->cnt = 0;
}
void setchild(Node* p, Node* c, int l) {
	c->p = p; l ? p->l = c : p->r = c;
}
void updatelz(Node* x, int val) {
	if (x == nil) return;
	x->lz += val;
	x->cnt += val;
}
void pushdown(Node* x) {
	if (x == nil) return;
	Node *u = x->l, *v = x->r;
	if (x->rev) {
		if (u != nil) {swap(u->l, u->r); u->rev ^= 1;}
		if (v != nil) {swap(v->l, v->r); v->rev ^= 1;}
		x->rev = 0;
	}
	if (x->lz) {
		if (u != nil) updatelz(u, x->lz);
		if (v != nil) updatelz(v, x->lz);
		x->lz = 0;
	}
}
void pushup(Node* x) {
	x->size = x->l->size + x->r->size + 1;
	x->max = x->val;
	chkmax(x->max, x->l->max);
	chkmax(x->max, x->r->max);
}
void rotate(Node* x) {
	Node* y = x->p;
	int l = x->p->l == x;
	if (!y->root) {
		setchild(y->p, x, y->p->l == y);
	}
	else {
		x->root = 1;
		y->root = 0;
		x->p = y->p;
	}
	setchild(y, l ? x->r : x->l, l);
	setchild(x, y, !l);
	pushup(y);
}
void splay(Node* x) {
	pushdown(x);
	while (!x->root) {
		pushdown(x->p->p); pushdown(x->p); pushdown(x);
		if (!x->p->root) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
		rotate(x);
	}
	pushup(x);
}
Node* access(Node* x) {
	Node* z = nil;
	for (Node* y = x; y != nil; y = y->p) {
		splay(y);
		y->r->root = 1;
		y->r = z;
		z->root = 0;
		pushup(z = y);
	}
	splay(x);
	return z;
}
void link(Node* x, Node* y) {
	access(y); access(x);
	y->cnt += x->cnt;
	updatelz(y->l, x->cnt);
	x->p = y;
	access(x);
}
void cut(Node* x) {
	access(x);
	x->l->root = 1;
	x->l->p = nil;
	updatelz(x->l, -x->cnt);
	x->l = nil;
	pushup(x);
}
Node* findroot(Node* x) {
	access(x);
	while (x->l != nil) pushdown(x), x = x->l;
	splay(x);
	return x;
}
Node* lca(Node* x, Node* y) {
	if (findroot(x) != findroot(y)) return nil;
	access(x);
	return access(y);
}
void makeroot(Node* x) {
	access(x);
	swap(x->l, x->r);
	x->rev ^= 1;
}
int connected(Node* x, Node* y) {
    if (x == y) return 1;
    access(x); access(y);
    return x->p != nil;
}

const int MAXN = 1000010;
Node node[MAXN];

const int maxn = 500010;
int n;
pi edges[2][maxn];
map<pi, int> hs[2];

int query(Node* x, Node* y) {
	makeroot(x);
	access(y);
	return y->max.se;
}

void cut(int k) {
	int u = edges[0][k].fi;
	int v = edges[0][k].se;
	makeroot(node + u);
	access(node + v);
	cut(node + v);
	access(node + n + k);
	node[n + k].val = node[n + k].max = mp(-1, -1);
}

void solve() {
	scanf("%d", &n);
	FOR(k, 0, 2) FOR(i, 0, n - 1) {
		scanf("%d%d", &edges[k][i].fi, &edges[k][i].se), edges[k][i].fi--, edges[k][i].se--;
		if (edges[k][i].fi > edges[k][i].se) swap(edges[k][i].fi, edges[k][i].se);
		hs[k][edges[k][i]] = 1;
	}
	int w = n;
	FOR(i, 0, n - 1) {
		int u = edges[0][i].fi;
		int v = edges[0][i].se;
		makeroot(node + u);
		link(node + u, node + w);
		link(node + w, node + v);
		if (!hs[1][mp(u, v)]) {
			node[w].val = node[w].max = mp(0, i);
		}
		w++;
	}
	vii ans;
	FOR(i, 0, n - 1) {
		int u = edges[1][i].fi;
		int v = edges[1][i].se;
		if (!hs[0][mp(u, v)]) {
			int r = query(node + u, node + v);
			ans.pb(mp(r, i));
			cut(r);
			makeroot(node + u);
			cut(node + u);
			link(node + u, node + v);
		}
	}
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) {
		int k = ans[i].fi;
		int l = ans[i].se;
		printf("%d %d %d %d\n", edges[0][k].fi + 1, edges[0][k].se + 1, edges[1][l].fi + 1, edges[1][l].se + 1);
	}
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