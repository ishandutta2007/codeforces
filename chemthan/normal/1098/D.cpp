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
template<class T> inline void addmod(T& a, T val, T p = MOD) {if ((a = (a + val)) >= p) a -= p;}
template<class T> inline void submod(T& a, T val, T p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 5e5 + 5;
int q;

pair<long long, int> st[maxn << 2];
long long lz[maxn << 2];

void build(int p, int L, int R) {
    if (L == R) {
        st[p] = mp(-LINF, L);
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[p] = max(st[p << 1], st[p << 1 | 1]);
}
void push(int p, int L, int R) {
    if (lz[p]) {
        st[p].fi += lz[p];
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i] += lz[p];
            }
        }
        lz[p] = 0;
    }
}
void upd(int p, int i, int L, int R, long long val) {
    push(p, L, R);
    if (R < i || i < L) return;
    if (L == R) {
        st[p] = mp(val, L);
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = max(st[p << 1], st[p << 1 | 1]);
}
void upd(int p, int l, int r, int L, int R, long long val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] += val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = max(st[p << 1], st[p << 1 | 1]);
}

long long fen[maxn];
void upd(int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
long long query(int p) {
    p++;
    long long res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void chemthan() {
    cin >> q;
    vector<pair<char, int> > que;
    vii dc;
    FOR(i, 0, q) {
        char op; int x; cin >> op >> x;
        que.pb(mp(op, x));
        if (op == '+') {
            dc.pb(mp(x, i));
        }
    }
    sort(all(dc)), uni(dc);
    build(1, 0, sz(dc) - 1);
    int sum = 0;
    map<int, vi> hs;
    FOR(i, 0, q) {
        char op = que[i].fi;
        if (op == '+') {
            hs[que[i].se].pb(i);
            int x = lower_bound(all(dc), mp(que[i].se, i)) - dc.begin();
            upd(1, x, 0, sz(dc) - 1, que[i].se - 2 * query(x - 1));
            upd(1, x + 1, sz(dc) - 1, 0, sz(dc) - 1, -2 * que[i].se);
            upd(x, +que[i].se);
            sum++;
        }
        else {
            int x = lower_bound(all(dc), mp(que[i].se, hs[que[i].se].back())) - dc.begin();
            hs[que[i].se].pop_back();
            upd(1, x, 0, sz(dc) - 1, -LINF);
            upd(1, x + 1, sz(dc) - 1, 0, sz(dc) - 1, +2 * que[i].se);
            upd(x, -que[i].se);
            sum--;
        }
        int res = 0;
        vector<pair<long long, int> > vals;
        while (st[1].fi > 0) {
            vals.pb(st[1]);
            upd(1, st[1].se, 0, sz(dc) - 1, -LINF);
        }
        cout << sum - sz(vals) << "\n";
        for (auto it : vals) {
            upd(1, it.se, 0, sz(dc) - 1, it.fi);
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