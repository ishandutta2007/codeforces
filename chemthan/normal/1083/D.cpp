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

struct node_t {
    int mn_x, mx_y;
    int sumx, sumy, sumyi, sumxy;
    int lzx, lzy;
    
    node_t() {
        sumx = sumy = sumyi = sumxy = 0;
        lzx = lzy = -1;
    }
};

node_t join(node_t a, node_t b) {
    node_t c;
    c.mn_x = min(a.mn_x, b.mn_x);
    c.mx_y = max(a.mx_y, b.mx_y);
    c.sumx = a.sumx;
    addmod(c.sumx, b.sumx);
    c.sumy = a.sumy;
    addmod(c.sumy, b.sumy);
    c.sumyi = a.sumyi;
    addmod(c.sumyi, b.sumyi);
    c.sumxy = a.sumxy;
    addmod(c.sumxy, b.sumxy);
    return c;
}

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int g[maxn];
int cnt[maxn];
int nxt[maxn];
int prv[maxn];

inline int f1(int l, int r) {
    return (long long) (l + r) * (r - l + 1) / 2 % MOD;
}

node_t st[maxn << 2];
void push(int p, int L, int R) {
    if (st[p].lzx != -1) {
        st[p].mn_x = st[p].lzx;
        st[p].sumx = mult(st[p].lzx, R - L + 1);
        st[p].sumxy = mult(st[p].lzx, st[p].sumy);
        if (L < R) {
            FOR(i, 0, 2) {
                st[p << 1 | i].lzx = st[p].lzx;
            }
        }
        st[p].lzx = -1;
    }
    if (st[p].lzy != -1) {
        st[p].mx_y = st[p].lzy;
        st[p].sumy = mult(st[p].lzy, R - L + 1);
        st[p].sumxy = mult(st[p].lzy, st[p].sumx);
        st[p].sumyi = mult(st[p].lzy, f1(L, R));
        if (L < R) {
            FOR(i, 0, 2) {
                st[p << 1 | i].lzy = st[p].lzy;
            }
        }
        st[p].lzy = -1;
    }
}
void updx(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        st[p].lzx = val;
        push(p, L, R);
        return;
    }
    updx(p << 1, l, r, L, L + R >> 1, val);
    updx(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}
void updy(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        st[p].lzy = val;
        push(p, L, R);
        return;
    }
    updy(p << 1, l, r, L, L + R >> 1, val);
    updy(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}
node_t query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return node_t();
    if (l <= L && R <= r) return st[p];
    return join(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

int queryx(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return r + 1;
    if (l <= L && R <= r) {
        if (st[p].mn_x <= val) {
            if (L == R) {
                return L;
            }
            push(p, L, R);
            if (st[p << 1].mn_x <= val) {
                return queryx(p << 1, l, r, L, L + R >> 1, val);
            }
            else {
                return queryx(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
            }
        }
        return r + 1;
    }
    int x = queryx(p << 1, l, r, L, L + R >> 1, val);
    if (x <= r) return x;
    return queryx(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
}

int queryy(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return r + 1;
    if (l <= L && R <= r) {
        if (st[p].mx_y >= val) {
            if (L == R) {
                return L;
            }
            push(p, L, R);
            if (st[p << 1].mx_y >= val) {
                return queryy(p << 1, l, r, L, L + R >> 1, val);
            }
            else {
                return queryy(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
            }
        }
        return r + 1;
    }
    int x = queryy(p << 1, l, r, L, L + R >> 1, val);
    if (x <= r) return x;
    return queryy(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
}

int findx(int l, int r, int val) {
    return queryx(1, l, r, 0, n - 1, val);
}

int findy(int l, int r, int val) {
    return queryy(1, l, r, 0, n - 1, val);
}

void chemthan() {
    vi dc;
    cin >> n;
    FOR(i, 0, n) cin >> a[i], dc.pb(a[i]);
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) a[i] = lower_bound(all(dc), a[i]) - dc.begin();
    int ptr = n - 1;
    static int lst[maxn];
    fill_n(lst, n, n);
    FORd(i, n, 0) {
        while (ptr >= 0 && !cnt[a[ptr]]) {
            cnt[a[ptr--]] = 1;
        }
        g[i] = ptr + 1;
        cnt[a[i]] = 0;
        nxt[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    fill_n(lst, n, -1);
    FOR(i, 0, n) {
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    int res = 0;
    FOR(i, 0, n) {
        updx(1, i, i, 0, n - 1, prv[i] + 1);
        updy(1, i, i, 0, n - 1, nxt[i] - 1);
        int x = findx(g[i], i, prv[i] + 1);
        int y = findy(g[i], i, nxt[i] - 1);
        updx(1, x, i, 0, n - 1, prv[i] + 1);
        updy(1, y, i, 0, n - 1, nxt[i] - 1);
        node_t r = query(1, g[i], i, 0, n - 1);
        addmod(res, r.sumyi);
        submod(res, r.sumxy);
        submod(res, mult(i, f1(g[i], i)));
        addmod(res, mult(i, r.sumx));
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