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
const int FFTMOD = 1007681537;
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

struct SegTree {
    static const int maxn = 4e5 + 5;
    int st[maxn << 2];
    int lz[maxn << 2];

    SegTree() {
        ms(lz, -1);
    }
    void push(int p, int L, int R) {
        if (~lz[p]) {
            st[p] = mult(lz[p], R - L + 1);
            if (L < R) {
                lz[p << 1] = lz[p];
                lz[p << 1 | 1] = lz[p];
            }
            lz[p] = -1;
        }
    }
    void pull(int p) {
        st[p] = st[p << 1] + st[p << 1 | 1];
        st[p] -= st[p] >= MOD ? MOD : 0;
    }
    void upd(int p, int l, int r, int L, int R, int val) {
        push(p, L, R);
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            lz[p] = val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        pull(p);
    }
    int query(int p, int l, int r, int L, int R) {
        push(p, L, R);
        if (r < L || R < l) return 0;
        if (l <= L && R <= r) return st[p];
        int res = query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
        res -= res >= MOD ? MOD : 0;
        return res;
    }
} seg[2];

const int maxn = 4e5 + 5;
int k, n, m;
int l[maxn];
int r[maxn];
vi g[maxn];

void chemthan() {
    cin >> k >> n >> m;
    vi dc;
    dc.pb(1), dc.pb(k + 1);
    FOR(i, 0, n + m) {
        cin >> l[i] >> r[i], r[i]++;
        dc.pb(l[i]), dc.pb(r[i]);
    }
    sort(all(dc)), uni(dc);
    FOR(i, 0, n + m) {
        l[i] = lower_bound(all(dc), l[i]) - dc.begin();
        r[i] = lower_bound(all(dc), r[i]) - dc.begin();
        g[l[i]].pb(i);
    }
    FOR(i, 0, 1) {
        seg[i].upd(1, sz(dc) - 1, sz(dc) - 1, 0, sz(dc) - 1, 1);
    }
    FOR(i, 0, sz(dc) - 1) {
        vector<pair<pi, int> > events;
        vii events2;
        FOR(j, 0, 2) {
            int mn = sz(dc) - 1;
            for (int x : g[i]) {
                if ((x < n ? 0 : 1) != j) {
                    chkmin(mn, r[x] - 1);
                }
            }
            events.pb(mp(mp(j ^ 1, mn), seg[j].query(1, i, sz(dc) - 1, 0, sz(dc) - 1)));
            events.pb(mp(mp(j ^ 1, mn), seg[j ^ 1].query(1, mn, sz(dc) - 1, 0, sz(dc) - 1)));
            events2.pb(mp(j ^ 1, mn));
        }
        int num = fpow(2, dc[i + 1] - dc[i]);
        submod(num, 2);
        int tmp = 0;
        FOR(j, 0, 2) {
            addmod(tmp, seg[j].query(1, i, sz(dc) - 1, 0, sz(dc) - 1));
        }
        events.pb(mp(mp(0, sz(dc) - 1), mult(num, tmp)));
        for (auto it : events2) {
            int ix = it.fi;
            int mn = it.se;
            seg[ix].upd(1, mn, sz(dc) - 1, 0, sz(dc) - 1, 0);
        }
        map<int, int> hs[2];
        for (auto it : events) {
            int ix = it.fi.fi;
            int u = it.fi.se;
            int v = it.se;
            addmod(hs[ix][u], v);
        }
        FOR(ix, 0, 2) {
            for (auto it : hs[ix]) {
                int u = it.fi;
                int v = it.se;
                seg[ix].upd(1, u, u, 0, sz(dc) - 1, v);
            }
        }
    }
    int res = 0;
    FOR(i, 0, 2) {
        addmod(res, seg[i].query(1, sz(dc) - 1, sz(dc) - 1, 0, sz(dc) - 1)); 
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