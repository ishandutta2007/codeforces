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
const ld EPS = 1e-6;
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
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

const int maxn = 1e4 + 5;
const int maxc = 14;
struct node_t {
    node_t* p;
    node_t* c[maxc];
    node_t *bf, *gf;
    int key;
    char val;
    long long info;
    node_t();
    void clear();
} pool[maxn], *ptr = pool;
node_t::node_t() {
    clear();
}
void node_t::clear() {
    p = 0;
    for (int i = 0; i < maxc; i++) c[i] = 0;
    bf = gf = 0, key = -1, val = 0, info = 0;
}
void clear() {
    node_t* st = pool;
    while (st != ptr) {
        st->clear();
        st++;
    }
    ptr = pool;
}
node_t* insert(node_t* x, char* s, int key, int cost) {
    while (*s) {
        int k = *s - 'a';
        if (!x->c[k]) {
            x->c[k] = ptr++;
            x->c[k]->p = x;
            x->c[k]->val = k;
        }
        x = x->c[k];
        s++;
    }
    x->key = key;
    x->info += cost;
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
            x->info += x->bf->info;
        }
    }
}

void chemthan() {
    int k; cin >> k;
    node_t* rt = ptr++;
    FOR(i, 0, k) {
        string s; cin >> s;
        int c; cin >> c;
        insert(rt, (char*) s.data(), i, c);
    }
    pushlink(rt);
    int total = ptr - pool;
    vector<vi> nxt_state(total, vi(14));
    FOR(i, 0, total) {
        FOR(c, 0, 14) {
            node_t* cur = pool + i;
            while (cur != rt && !cur->c[c]) cur = cur->bf;
            cur = cur->c[c];
            if (!cur) cur = rt;
            nxt_state[i][c] = cur - pool;
        }
    }
    string s; cin >> s;
    int n = sz(s);
    vector<vector<long long>> dp(total, vector<long long>(1 << 14, -LINF * 2));
    vector<vector<long long>> ndp(total, vector<long long>(1 << 14, -LINF * 2));
    dp[0][0] = 0;
    int num = 0;
    FOR(i, 0, n) {
        if (s[i] != '?') {
            vector<pair<int, long long>> f(total);
            FOR(k, 0, total) f[k].fi = k;
            int j = i;
            while (j < n && s[j] != '?') {
                int c = s[j] - 'a';
                FOR(k, 0, total) {
                    int t = f[k].fi;
                    f[k].fi = nxt_state[t][c];
                    f[k].se += pool[f[k].fi].info;
                }
                j++;
            }
            FOR(msk, 0, 1 << 14) if (bitcount(msk) == num) {
                FOR(k, 0, total) {
                    ndp[k][msk] = -LINF * 2;
                }
                FOR(k, 0, total) {
                    int nk = f[k].fi;
                    chkmax(ndp[nk][msk], dp[k][msk] + f[k].se);
                }
                FOR(k, 0, total) {
                    dp[k][msk] = ndp[k][msk];
                }
            }
            i = j - 1;
        }
        else {
            FOR(msk, 0, 1 << 14) if (bitcount(msk) == num) {
                FOR(c, 0, 14) if (!bit(msk, c)) {
                    FOR(k, 0, total) {
                        int nk = nxt_state[k][c];
                        chkmax(dp[nk][msk | (1 << c)], dp[k][msk] + pool[nk].info);
                    }
                }
            }
            num++;
        }
    }
    int x = 0;
    for (char c : s) if (c == '?') x++;
    long long res = -LINF * 2;
    FOR(i, 0, total) FOR(msk, 0, 1 << 14) if (bitcount(msk) == x) chkmax(res, dp[i][msk]);
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