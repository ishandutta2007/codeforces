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

struct HopcroftKarp {
    static const int MAXV = 2e6 + 5;
    static const int MAXE = 2e6 + 5;
    int nx, ny, E, adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV], matx[MAXV], maty[MAXV];
    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        E = 0, fill_n(lst, nx, -1);
        fill_n(matx, nx, -1), fill_n(maty, ny, -1);
    }
    void add(int x, int y) {
        adj[E] = y, nxt[E] = lst[x], lst[x] = E++;
    }
    int bfs() {
        int qsize = 0;
        for (int x = 0; x < nx; x++) if (matx[x] != -1) lev[x] = 0;
        else {
            lev[x] = 1;
            que[qsize++] = x;
        }
        int found = 0;
        for (int i = 0; i < qsize; i++) {
            for (int x = que[i], e = lst[x]; ~e; e = nxt[e]) {
                int y = adj[e];
                if (!~maty[y]) found = 1;
                else if (!lev[maty[y]]) {
                    lev[maty[y]] = lev[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }
        return found;
    }
    int dfs(int x) {
        for (int& e = ptr[x]; ~e; e = nxt[e]) {
            int y = adj[e];
            if (!~maty[y] || (lev[maty[y]] == lev[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }
    int maxmat() {
        int res = 0;
        while (bfs()) {
            for (int x = 0; x < nx; x++) ptr[x] = lst[x];
            for (int x = 0; x < nx; x++) if (!~matx[x]) res += dfs(x);
        }
        return res;
    }
} hopkarp;

const int MAXN = 1e6 + 5;
const int MAXC = 26;
struct Node {
    Node* p;
    Node* c[MAXC];
    Node *bf;
    int key;
    char val;
    Node();
    void clear();
} mem[MAXN], *ptr = mem;
Node::Node() {
    clear();
}
void Node::clear() {
    p = 0;
    for (int i = 0; i < MAXC; i++) c[i] = 0;
    bf = 0, key = -1, val = 0;
}
void clear() {
    Node* st = mem;
    while (st != ptr) {
        st->clear();
        st++;
    }
    ptr = mem;
}
Node* insert(Node* x, char* s) {
    int st = 0;
    while (*s) {
        int k = *s - 'a';
        if (!x->c[k]) {
            x->c[k] = ptr++;
            x->c[k]->p = x;
            x->c[k]->val = k;
        }
        x = x->c[k];
        x->key = ++st;
        s++;
    }
    return x;
}
void pushlink(Node* rt) {
    static Node* q[MAXN];
    int b = 0, e = 0;
    q[e++] = rt;
    while (b < e) {
        Node* x = q[b++];
        for (int i = 0; i < MAXC; i++) {
            if (x->c[i]) q[e++] = x->c[i];
        }
        if (x == rt || x->p == rt) {
            x->bf = rt;
        }
        else {
            x->bf = x->p->bf;
            while (x->bf != rt && !x->bf->c[x->val]) x->bf = x->bf->bf;
            if (x->bf->c[x->val]) x->bf = x->bf->c[x->val];
            if (x->bf && x->key == x->bf->key + 1) {
                if (x->key & 1) {
                    hopkarp.add(x - mem, x->bf - mem);
                }
                else {
                    hopkarp.add(x->bf - mem, x - mem);
                }
            }
        }
    }
}

const int maxn = 1e6 + 5;
int n;

void solve() {
    int test; scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        clear();
        Node* rt = ptr++;
        FOR(i, 0, n) {
            static char s[maxn];
            scanf("%s", s);
            insert(rt, s);
        }
        hopkarp.init(ptr - mem, ptr - mem);
        pushlink(rt);
        printf("%d\n", (ptr - mem) - 1 - hopkarp.maxmat());
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
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}