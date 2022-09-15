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

const int MAXN = 10000000 + 10;
struct Node {
	Node *l, *r;
	int L, R, rev, cnt;
	Node();
} mem[MAXN], *nil = mem + MAXN - 1;
Node::Node() {
	l = r = nil;
	L = R = -1;
	rev = cnt = 0;
}
inline Node* alloc() {
	static int cur = 0;
	return mem + (cur++);
}
inline Node* build(int L, int R) {
	Node* node = alloc();
	node->L = L; node->R = R;
	if (L == R) return node;
	node->l = build(L, (L + R) >> 1);
	node->r = build(((L + R) >> 1) + 1, R);
	return node;
}
inline Node* reverse(Node* node) {
	if (node == nil) return nil;
	Node* x = alloc();
	x->L = node->L; x->R = node->R;
	x->l = node->l; x->r = node->r;
	x->rev = node->rev ^ 1;
	x->cnt = node->R - node->L + 1 - node->cnt;
	return x;
}
inline void pushdown(Node* node) {
	if (node->rev) {
		node->l = reverse(node->l);
		node->r = reverse(node->r);
		node->rev = 0;
	}
}
inline Node* update(Node* node, int i, int val) {
	if (node->L > i || node->R < i) return node;
	Node* x = alloc();
	x->L = node->L; x->R = node->R;
	x->l = node->l; x->r = node->r;
	x->rev = node->rev;
	x->cnt = node->cnt;
	if (node->L == node->R) {
		x->cnt = val;
		return x;
	}
	pushdown(x);
	x->l = update(x->l, i, val);
	x->r = update(x->r, i, val);
	x->cnt = x->l->cnt + x->r->cnt;
	return x;
}
inline Node* reverse(Node* node, int l, int r) {
	if (node->L > r || node->R < l) return node;
	if (l <= node->L && r >= node->R) {
		return reverse(node);
	}
	Node* x = alloc();
	x->L = node->L; x->R = node->R;
	x->l = node->l; x->r = node->r;
	x->rev = node->rev;
	x->cnt = node->cnt;
	pushdown(x);
	x->l = reverse(x->l, l, r);
	x->r = reverse(x->r, l, r);
	x->cnt = x->l->cnt + x->r->cnt;
	return x;
}

const int maxn = 100000 + 10;
int n, m, q;
Node* root[maxn];

void solve() {
	cin >> n >> m >> q;
	root[0] = build(0, n * m - 1);
	int ans = 0;
	FOR(i, 1, q + 1) {
		int op; cin >> op;
		if (op == 1) {
			int u, v; cin >> u >> v; u--, v--;
			root[i] = update(root[i - 1], u * m + v, 1);
		}
		else if (op == 2) {
			int u, v; cin >> u >> v; u--, v--;
			root[i] = update(root[i - 1], u * m + v, 0);
		}
		else if (op == 3) {
			int u; cin >> u; u--;
			root[i] = reverse(root[i - 1], u * m, u * m + m - 1);
		}
		else if (op == 4) {
			int k; cin >> k;
			root[i] = root[k];
		}
		cout << root[i]->cnt << "\n";
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