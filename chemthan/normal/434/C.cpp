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

const int MAXN = 100010;
const int MAXC = 30;
struct Node {
	Node* parent;
	Node* child[MAXC];
	Node* bfail;
	Node* gfail;
	int key;
	char val;
	int sum;
	Node() {
		bfail = 0;
		key = -1;
		sum = 0;
	}
} node[MAXN];
Node* alloc = node;
Node* q[MAXN];
Node* root = alloc++;
Node* insert(Node* x, int* a, int size, int key, int sum) {
	for (int i = 0; i < size; i++) {
		int c = a[i];
		if (!x->child[c]) {
			x->child[c] = alloc++;
			x->child[c]->val = c;
			x->child[c]->parent = x;
		}
		x = x->child[c];
	}
	x->key = key;
	x->sum += sum;
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
		} else {
			x->bfail = x->parent->bfail;
			while (x->bfail != root && !x->bfail->child[x->val]) x->bfail = x->bfail->bfail;
			if (x->bfail->child[x->val]) x->bfail = x->bfail->child[x->val];
			if (x->bfail->key != -1) x->gfail = x->bfail;
			else x->gfail = x->bfail->gfail;
			x->sum += x->bfail->sum;
		}
	}
}

const int maxn = 210;
const int maxk = 510;
int n, m, k;
int na, nb;
int a[maxn];
int b[maxn];
int x[maxn];
int f[maxn][maxn][maxk][2][2];

int calc(int cur, int pos, int r, int fa, int fb) {
	if (pos == maxn) {
		return 1;
	}
	int& res = f[cur][pos][r][fa][fb];
	if (~res) return res;
	res = 0;
	int lo = 0, hi = m - 1;
	if (!fa) chkmax(lo, a[pos]);
	if (!fb) chkmin(hi, b[pos]);
	FOR(i, lo, hi + 1) {
		int nxt = cur;
		while (nxt && !node[nxt].child[i]) {
			nxt = node[nxt].bfail - node;
		}
		if (node[nxt].child[i]) {
			nxt = node[nxt].child[i] - node;
		}
		if (r >= node[nxt].sum) {
			addmod(res, calc(nxt, pos + 1, r - node[nxt].sum, fa | i > a[pos], fb | i < b[pos]));
		}
	}
	return res;
}

void solve() {
	cin>>n>>m>>k;
	cin>>na; FOR(i, 0, na) cin>>a[maxn - na + i];
	cin>>nb; FOR(i, 0, nb) cin>>b[maxn - nb + i];
	FOR(i, 0, n) {
		int size; cin>>size;
		FOR(j, 0, size) cin>>x[j];
		int val; cin>>val;
		insert(root, x, size, i, val);
	}
	pushlink(root);
	ms(f, -1);
	int ans = 0, fb = 0;
	FOR(i, 0, maxn) {
		int lo = max(1, a[i]), hi = m - 1;
		if (!fb) chkmin(hi, b[i]);
		FOR(j, lo, hi + 1) {
			int nxt = root->child[j] ? root->child[j] - node : 0;
			if (k >= node[nxt].sum) {
				addmod(ans, calc(nxt, i + 1, k - node[nxt].sum, j > a[i], fb | j < b[i]));
			}
		}
		if (a[i]) break;
		fb |= b[i] > 0;
	}
	cout<<ans<<"\n";
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