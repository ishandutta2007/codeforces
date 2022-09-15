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

struct matrix {
	static const int MAXN = 210;
	long long x[MAXN][MAXN];
	
	matrix() {
		memset(x, 0, sizeof(x));
	}
	matrix unit() {
		matrix res;
		for (int i = 0; i < MAXN; i++) res.x[i][i] = 1;
		return res;
	}
	matrix operator * (matrix A) {
		matrix res;
		FOR(i, 0, MAXN) FOR(j, 0, MAXN) res.x[i][j] = -LINF;
		for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
			if (x[i][k] != -LINF && A.x[k][j] != -LINF) {
				chkmax(res.x[i][j], x[i][k] + A.x[k][j]);
			}
		}
		return res;
	}
	matrix operator ^ (long long k) {
		if (!k) return unit();
		matrix res, tmp;
		for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
			res.x[i][j] = tmp.x[i][j] = x[i][j];
		}
		k--;
		while (k) {
			if (k & 1) res = res * tmp;
			tmp = tmp * tmp;
			k >>= 1;
		}
		return res;
	}
};

const int MAXN = 100010;
const int MAXC = 26;
struct Node {
	Node* parent;
	Node* child[MAXC];
	Node* bfail;
	Node* gfail;
	int key, cost, sum;
	char val;
	Node() {
		bfail = 0;
		key = -1, cost = sum = 0;
	}
} node[MAXN];
Node* alloc = node;
Node* q[MAXN];
Node* root = alloc++;
Node* insert(Node* x, string s, int key, int cost) {
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		if (!x->child[c]) {
			x->child[c] = alloc++;
			x->child[c]->val = c;
			x->child[c]->parent = x;
		}
		x = x->child[c];
	}
	x->key = key;
	x->cost += cost;
	return x;
}
void pushlink(Node* root) {
	int b = 0, e = 0;
	q[e++] = root;
	while (b < e) {
		Node* x = q[b++];
		for (int i = 0; i < MAXC; i++) {
			if (x->child[i]) q[e++] = x->child[i];
		}
		if (x == root || x->parent == root) {
			x->bfail = root;
			x->gfail = 0;
		}
		else {
			x->bfail = x->parent->bfail;
			while (x->bfail != root && !x->bfail->child[x->val]) x->bfail = x->bfail->bfail;
			if (x->bfail->child[x->val]) x->bfail = x->bfail->child[x->val];
			if (x->bfail->key != -1) x->gfail = x->bfail;
			else x->gfail = x->bfail->gfail;
		}
	}
}

const int maxn = 210;
int n;
long long l;
int a[maxn];
string s[maxn];
matrix A;

void upd(Node* x) {
	Node* tmp = x;
	while (1) {
		x->sum += tmp->cost;
		if (tmp == root) {
			break;
		}
		tmp = tmp->bfail;
	}
	for (int i = 0; i < MAXC; i++) {
		if (x->child[i]) {
			upd(x->child[i]);
		}
	}
}

void build(Node* x) {
	FOR(i, 0, MAXC) {
		if (x->child[i]) {
			build(x->child[i]);
		}
	}
	Node* tmp = x;
	while (1) {
		FOR(i, 0, MAXC) {
			Node* y = tmp->child[i];
			if (y) {
				int u = x - root;
				int v = y - root;
				A.x[u][v] = y->sum;
			}
		}
		if (tmp == root) {
			break;
		}
		tmp = tmp->bfail;
	}
}

void solve() {
	cin >> n >> l;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n) {
		cin >> s[i];
		insert(root, s[i], i, a[i]);
	}
	FOR(i, 0, A.MAXN) FOR(j, 0, A.MAXN) A.x[i][j] = -LINF;
	pushlink(root);
	upd(root);
	build(root);
	A = A ^ l;
	long long ans = 0;
	FOR(i, 0, A.MAXN) {
		chkmax(ans, A.x[0][i]);
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