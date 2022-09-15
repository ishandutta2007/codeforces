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
const int MOD2 = 1007681537;
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
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxm = 1e7 + 5;
int ptr;
struct Node {
    Node *l, *r;
    int val;
    Node(Node* l = 0, Node* r = 0, int val = 0) : l(l), r(r), val(val) {}
} mem[maxm];

Node* newNode(Node *l = 0, Node *r = 0, int val = 0) {
    Node* res = mem + (ptr++);
    res->l = l, res->r = r, res->val = val;
    return res;
}

Node* getl(Node* p) {return p ? p->l : 0;}
Node* getr(Node* p) {return p ? p->r : 0;}
int getv(Node *p) {return p ? p->val : 0;}

Node* upd(Node* p, int i, int L, int R, int val) {
    if (i < L || i > R) return p;
    if (L == R) {
        return newNode(getl(p), getr(p), getv(p) + val);
    }
    Node* res = newNode(getl(p), getr(p), getv(p));
    res->l = upd(res->l, i, L, L + R >> 1, val);
    res->r = upd(res->r, i, (L + R >> 1) + 1, R, val);
    res->val = getv(res->l) + getv(res->r);
    return res;
}

int kth(Node* x, Node* y, int L, int R, int k) {
    if (L == R) return L + R >> 1;
    int tot = 0;
    tot += (y && y->l) ? y->l->val : 0;
    tot -= (x && x->l) ? x->l->val : 0;
    if (tot >= k) return kth(getl(x), getl(y), L, L + R >> 1, k);
    return kth(getr(x), getr(y), (L + R >> 1) + 1, R, k - tot);
}

int query(Node* p, int i, int L, int R) {
    if (!p) return 0;
    if (i < L || i > R) return 0;
    if (L == R) return p->val;
    return query(p->l, i, L, L + R >> 1) + query(p->r, i, (L + R >> 1) + 1, R);
}

const int maxn = 3e5 + 5;
int n, q;
int a[maxn];
Node* f[maxn];

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) {
        cin >> a[i], a[i]--;
        f[i + 1] = upd(f[i], a[i], 0, n - 1, 1);
    }
    while (q--) {
        int l, r, k; cin >> l >> r >> k; l--, r--;
        int dif = (r - l + 1) / k + 1;
        int mn = INF;
        for (int i = l; i <= r; i += dif) {
            int x = kth(f[l], f[r + 1], 0, n - 1, i - l + 1);
            int cnt = query(f[r + 1], x, 0, n - 1) - query(f[l], x, 0, n - 1);
            if (cnt >= dif) {
                chkmin(mn, x);
            }
        }
        if (mn == INF) mn = -2;
        cout << mn + 1 << "\n";
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}