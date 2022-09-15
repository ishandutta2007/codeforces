#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
const int maxc = 10;
struct node_t {
    node_t* p;
    node_t* c[maxc];
    node_t *bf, *gf;
    int key;
    char val;
    vector<int> info;
    node_t();
    void clear();
} pool[maxn], *ptr = pool;
node_t::node_t() {
    clear();
}
void node_t::clear() {
    p = 0;
    for (int i = 0; i < maxc; i++) c[i] = 0;
    bf = gf = 0, key = -1, val = 0;
}
void clear() {
    node_t* st = pool;
    while (st != ptr) {
        st->clear();
        st++;
    }
    ptr = pool;
}
node_t* insert(node_t* x, char* s, int key, int len) {
    while (*s) {
        int k = *s - '0';
        if (!x->c[k]) {
            x->c[k] = ptr++;
            x->c[k]->p = x;
            x->c[k]->val = k;
        }
        x = x->c[k];
        s++;
    }
    x->key = key;
    x->info.push_back(len);
    return x;
}
void pushlink(node_t* rt) {
    static node_t* q[maxn];
    int b = 0, e = 0;
    q[e++] = rt;
    while (b < e) {
        node_t* x = q[b++];
        for (int i = 0; i < maxc; i++) {
            if (x->c[i]) q[e++] = x->c[i];
        }
        if (x == rt || x->p == rt) {
            x->bf = rt;
            x->gf = 0;
        }
        else {
            x->bf = x->p->bf;
            while (x->bf != rt && !x->bf->c[x->val]) x->bf = x->bf->bf;
            if (x->bf->c[x->val]) x->bf = x->bf->c[x->val];
            if (x->bf->key != -1) x->gf = x->bf;
            else x->gf = x->bf->gf;
            for (int e : x->bf->info) {
                x->info.push_back(e);
            }
            sort(x->info.begin(), x->info.end());
        }
    }
}

string l, r;
int n;
node_t* rt;
vector<vi> f;
vector<vi> dp;

int mem[maxn][10];
int func(int u, int k) {
    int& res = mem[u][k];
    if (~res) return res;
    node_t* cur = pool + u;
    while (cur != rt && !cur->c[k]) {
        cur = cur->bf;
    }
    return res = cur - pool;
}

int calc(int u, int v) {
    if (u == n) return 0;
    int& res = dp[u][v];
    if (~res) return res;
    res = 0;
    FOR(i, 0, 10) {
        node_t* cur = pool + func(v, i);
        int cost = f[n - u][i], nv = cur - pool;
        if (cur->c[i]) {
            cur = cur->c[i];
            nv = cur - pool;
            if (cur->key == -1) {
                cur = cur->gf;
            }
            if (cur) {
                cost += upper_bound(all(cur->info), n - u) - cur->info.begin();
            }
        }
        chkmax(res, calc(u + 1, nv) + cost);
    }
    return res;
}

void chemthan() {
    cin >> l >> r >> n;
    vector<vi> g(10);
    if (sz(l) < sz(r)) {
        FOR(i, 1, r[0] - '0') {
            g[i].pb(sz(r));
        }
        FOR(i, sz(l) + 1, sz(r)) {
            FOR(j, 1, 10) {
                g[j].pb(i);
            }
        }
        FOR(i, l[0] - '0' + 1, 10) {
            g[i].pb(sz(l));
        }
    }
    else {
        FOR(i, l[0] - '0' + 1, r[0] - '0') {
            g[i].pb(sz(r));
        }
    }
    FOR(i, 1, 10) sort(all(g[i]));
    f.resize(n + 1, vi(10));
    FOR(i, 1, n + 1) FOR(j, 1, 10) {
        f[i][j] = upper_bound(all(g[j]), i) - g[j].begin();
    }
    rt = ptr++;
    int flag = sz(l) < sz(r) || l[0] < r[0];
    FOR(i, 1, sz(r)) {
        FOR(j, 0, r[i] - '0') {
            if (flag || l[i] - '0' < j) {
                insert(rt, (char *) (r.substr(0, i) + char('0' + j)).data(), 0, sz(r) - i);
            }
        }
        if (!flag) {
            flag |= l[i] < r[i];
        }
    }
    flag = sz(l) < sz(r) || l[0] < r[0];
    FOR(i, 1, sz(l)) {
        FOR(j, l[i] - '0' + 1, 10) {
            if (flag) {
                insert(rt, (char *) (l.substr(0, i) + char('0' + j)).data(), 0, sz(l) - i);
            }
        }
        if (!flag) {
            flag |= l[i] < r[i];
        }
    }
    insert(rt, (char *) l.data(), 0, 1);
    if (l < r) {
        insert(rt, (char *) r.data(), 0, 1);
    }
    pushlink(rt);
    dp.resize(n + 1);
    for (auto& e : dp) e.resize(ptr - pool, -1);
    ms(mem, -1);
    int mx = calc(0, 0);
    cout << mx << "\n";
    string res;
    int u = 0, v = 0;
    FOR(it, 0, n) {
        FOR(i, 0, 10) {
            node_t* cur = pool + func(v, i);
            int cost = f[n - u][i], nv = cur - pool;
            if (cur->c[i]) {
                cur = cur->c[i];
                nv = cur - pool;
                if (cur->key == -1) {
                    cur = cur->gf;
                }
                if (cur) {
                    cost += upper_bound(all(cur->info), n - u) - cur->info.begin();
                }
            }
            if (calc(u + 1, nv) + cost == mx) {
                res += char('0' + i);
                mx -= cost;
                u++, v = nv;
                break;
            }
        }
    }
    cout << res << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}