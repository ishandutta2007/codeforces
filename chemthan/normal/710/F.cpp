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

const int MAXN = 4000000 + 10;
const int LOGN = 20;
const int MAXC = 26;
struct Node {
	Node* parent;
	Node* child[MAXC];
	Node* bfail;
	Node* gfail;
	int key;
	char val;
	int cnt;
	Node() {
		bfail = 0;
		key = -1;
	}
	void clear() {
		parent = 0;
		for (int i = 0; i < MAXC; i++) {
			child[i] = 0;
		}
		bfail = gfail = 0;
		key = -1;
		cnt = 0;
	}
};
Node mem[MAXN];
int ptr;
Node* q[MAXN];
struct Ahocorasick {
	Node *root;
	vector<string> vs;
	void init() {
		root = mem + (ptr++);
		vs.clear();
	}
	Node* insert(Node* x, string s) {
		vs.push_back(s);
		for (int i = 0; i < s.size(); i++) {
			int c = s[i] - 'a';
			if (!x->child[c]) {
				x->child[c] = mem + (ptr++);
				x->child[c]->val = c;
				x->child[c]->parent = x;
			}
			x = x->child[c];
		}
		x->key = 0;
		x->cnt++;
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
				x->cnt += x->bfail->cnt;
			}
		}
	}
	int query(string s) {
		int res = 0;
		Node* cur = root;
		for (int i = 0; i < s.size(); i++) {
			while (cur != root && !cur->child[s[i] - 'a']) cur = cur->bfail;
			cur = cur->child[s[i] - 'a'];
			if (!cur) cur = root;
			res += cur->cnt;
		}
		return res;
	}
} aho;

struct DynamicAhocorasick {
	Ahocorasick aho[LOGN];
	void add(string s) {
		int ix = -1;
		for (int i = 0; i < LOGN; i++) {
			if (aho[i].vs.size() == 0) {
				ix = i;
				break;
			}
		}
		assert(~ix);
		aho[ix].init();
		aho[ix].insert(aho[ix].root, s);
		for (int i = 0; i < ix; i++) {
			for (int j = 0; j < aho[i].vs.size(); j++) {
				aho[ix].insert(aho[ix].root, aho[i].vs[j]);
			}
			aho[i].init();
		}
		aho[ix].pushlink(aho[ix].root);
	}
	int query(string s) {
		int res = 0;
		for (int i = 0; i < LOGN; i++) if (aho[i].vs.size()) {
			res += aho[i].query(s);
		}
		return res;
	}
} daho[2];

void solve() {
	int q; cin >> q;
	while (q--) {
		int op; string s; cin >> op >> s;
		if (op == 1) {
			daho[0].add(s);
		}
		else if (op == 2) {
			daho[1].add(s);
		}
		else if (op == 3) {
			cout << daho[0].query(s) - daho[1].query(s) << "\n";
			cout.flush();
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