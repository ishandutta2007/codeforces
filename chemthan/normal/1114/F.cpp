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

template<class num_t>
struct RangeFenwick {
    int n;
    vector<num_t> fen[2];
    RangeFenwick(int n) {
        this->n = n;
        fen[0].resize(n + 1, 1);
        fen[1].resize(n + 1, 1);
    }
    void upd(int p, num_t val) {
        assert(p > 0);
        int t = fpow(val, p);
        for (int pp = p; pp <= n; pp += pp & -pp) {
            fen[0][pp] = mult(fen[0][pp], val);
            fen[1][pp] = mult(fen[1][pp], t);
        }
    }
    void upd(int l, int r, num_t val) {
        upd(l, val), upd(r + 1, inv(val));
    }
    num_t query(int p) {
        assert(p <= n);
        num_t u = 1, v = 1;
        for (int pp = p; pp > 0; pp -= pp & -pp) {
            u = mult(u, fen[0][pp]);
            v = mult(v, fen[1][pp]);
        }
        return mult(fpow(u, p + 1), inv(v));
    }
    num_t query(int l, int r) {
        return mult(query(r), inv(query(l - 1)));
    }
};

const int maxn = 300 + 5;
int sp[maxn];
int ff[maxn];
int iv[maxn];
long long msk[maxn];
int n, q;

long long st[1 << 22];
long long lz[1 << 22];
void push(int p, int L, int R) {
    if (lz[p]) {
        st[p] |= lz[p];
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i] |= lz[p];
            }
        }
        lz[p] = 0;
    }
}
void upd(int p, int l, int r, int L, int R, long long val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1] | st[p << 1 | 1];
}
long long query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return 0;
    if (l <= L && R <= r) return st[p];
    return query(p << 1, l, r, L, L + R >> 1) | query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

void chemthan() {
    FOR(i, 1, maxn) sp[i] = i;
    vi pr;
    FOR(i, 2, maxn) if (sp[i] == i) {
        for (int j = i + i; j < maxn; j += i) {
            chkmin(sp[j], i);
        }
        ff[i] = sz(pr);
        pr.pb(i);
    }
    FOR(i, 1, maxn) {
        int t = i;
        while (t > 1) {
            msk[i] |= 1LL << ff[sp[t]];
            t /= sp[t];
        }
        iv[i] = inv(i);
    }
    cin >> n >> q;
    RangeFenwick<int> rf(n);
    FOR(i, 1, n + 1) {
        int a; cin >> a;
        rf.upd(i, i, a);
        upd(1, i - 1, i - 1, 0, n - 1, msk[a]);
    }
    while (q--) {
        string op; cin >> op;
        if (op == "MULTIPLY") {
            int l, r, x; cin >> l >> r >> x;
            rf.upd(l, r, x);
            upd(1, l - 1, r - 1, 0, n - 1, msk[x]);
        }
        else {
            int l, r; cin >> l >> r;
            int res = rf.query(l, r);
            long long msk = query(1, l - 1, r - 1, 0, n - 1);
            FOR(i, 0, sz(pr)) if (bit(msk, i)) {
                res = mult(res, iv[pr[i]]);
                res = mult(res, pr[i] - 1);
            }
            cout << res << "\n";
        }
    }
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