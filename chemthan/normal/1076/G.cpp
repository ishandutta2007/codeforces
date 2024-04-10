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
    int L, R;
    int val1[1 << 5];
    int val2[1 << 5];
    int fi[5];
    int ls[5];
    int lz;
    node_t() {
        L = R = -1;
        ms(val1, 0), ms(val2, 0);
        lz = 0;
    }
};

const int maxn = 2e5 + 5;
int n, m, q;
int a[maxn];
int b[maxn];
int f[10][10];

int fen[maxn];
void upd(int p) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] ^= 1;
    }
}
int query(int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res ^= fen[p];
    }
    return res;
}

int dp[10][1 << 10][(1 << 5) + 1][2];
int ff(int id, int l, int r, int msk, int flag) {
    int& res = dp[r - l][id][msk + 1][flag];
    if (~res) return res;
    assert(r - l + 1 <= m + m);
    res = 0;
    FORd(i, r + 1, l) {
        if (r - i < m && msk != -1) {
            res |= msk & (1 << r - i);
        }
        else {
            int k = min(m, r - i);
            if (k && (res & f[r - i - k][r - i - 1]) != f[r - i - k][r - i - 1]) {
                res |= 1 << r - i;
            }
            else if (!(b[i] ^ flag)) {
                res |= 1 << r - i;
            }
        }
    }
    return res;
}

node_t st[maxn << 2];
node_t join(node_t x, node_t y) {
    if (x.L == -1) return y;
    if (y.L == -1) return x;
    node_t res;
    res.L = x.L, res.R = y.R;
    res.lz = 0;
    FOR(i, 0, min(m, x.R - x.L + 1)) res.fi[i] = x.fi[i];
    FOR(i, min(m, x.R - x.L + 1), m) res.fi[i] = y.fi[i - min(m, x.R - x.L + 1)];
    FOR(i, 0, min(m, y.R - y.L + 1)) res.ls[i] = y.ls[i];
    FOR(i, min(m, y.R - y.L + 1), m) res.ls[i] = x.ls[i - min(m, y.R - y.L + 1)];
    if (x.R - x.L + 1 < m && y.R - y.L + 1 < m) {
        int id = 0;
        FOR(i, x.L, y.R + 1) {
            if (i <= x.R) {
                b[i] = x.ls[x.R - i];
            }
            else {
                b[i] = x.fi[i - y.L];
            }
            id = id << 1 | b[i];
        }
        FOR(msk, 0, 1 << m) {
            res.val1[msk] = ff(id, x.L, y.R, msk, 0) >> max(0, y.R - x.L + 1 - m);
            res.val2[msk] = ff(id, x.L, y.R, msk, 1) >> max(0, y.R - x.L + 1 - m);
        }
        return res;
    }
    if (y.R - y.L + 1 < m) {
        int id = 0;
        FOR(i, x.R - m + 1, y.R + 1) {
            if (i <= x.R) {
                b[i] = x.ls[x.R - i];
            }
            else {
                b[i] = x.fi[i - y.L];
            }
            id = id << 1 | b[i];
        }
        FOR(msk, 0, 1 << m) {
            int val = ff(id, x.R - m + 1, y.R, msk, 0);
            res.val1[msk] = x.val1[val >> y.R - y.L + 1];
            val = ff(id, x.R - m + 1, y.R, msk, 1);
            res.val2[msk] = x.val2[val >> y.R - y.L + 1];
        }
        return res;
    }
    if (x.R - x.L + 1 < m) {
        int id = 0;
        FOR(i, x.L, y.L + m) {
            if (i <= x.R) {
                b[i] = x.ls[x.R - i];
            }
            else {
                b[i] = x.fi[i - y.L];
            }
            id = id << 1 | b[i];
        }
        FOR(msk, 0, 1 << m) {
            int val = ff(id, x.L, y.L + m - 1, y.val1[msk], 0);
            res.val1[msk] = val >> x.R - x.L + 1;
            val = ff(id, x.L, y.L + m - 1, y.val2[msk], 1);
            res.val2[msk] = val >> x.R - x.L + 1;
        }
        return res;
    }
    int lo = x.R - m + 1;
    int hi = y.L + m - 1;
    int id = 0;
    FOR(i, lo, hi + 1) {
        if (i <= x.R) {
            b[i] = x.ls[x.R - i];
        }
        else {
            b[i] = x.fi[i - y.L];
        }
        id = id << 1 | b[i];
    }
    FOR(msk, 0, 1 << m) {
        int val = ff(id, lo, hi, y.val1[msk], 0);
        res.val1[msk] = x.val1[val >> m];
        val = ff(id, lo, hi, y.val2[msk], 1);
        res.val2[msk] = x.val2[val >> m];
    }
    return res;
}

void upd(int p, int L, int R) {
    int id = 0;
    FOR(i, L, R + 1) b[i] = a[i] ^ query(i), id = id << 1 | b[i];
    FOR(msk, 0, 1 << m) {
        st[p].val1[msk] = ff(id, L, R, msk, 0) >> max(0, R - L + 1 - m);
        st[p].val2[msk] = ff(id, L, R, msk, 1) >> max(0, R - L + 1 - m);
    }
}

void build(int p, int L, int R) {
    st[p].L = L, st[p].R = R;
    if (L == R) {
        upd(p, L, R);
        st[p].fi[0] = st[p].ls[0] = a[L];
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}

void push(int p, int L, int R) {
    if (st[p].lz) {
        FOR(i, 0, min(m, R - L + 1)) {
            st[p].fi[i] ^= 1;
            st[p].ls[i] ^= 1;
        }
        FOR(msk, 0, 1 << m) {
            swap(st[p].val1[msk], st[p].val2[msk]);
        }
        if (L < R) {
            FOR(i, 0, 2) {
                st[p << 1 | i].lz ^= 1;
            }
        }
        st[p].lz = 0;
    }
}
void upd(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        st[p].lz = 1;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}
node_t query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (r < L || R < l) return node_t();
    if (l <= L && R <= r) {
        return st[p];
    }
    return join(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void chemthan() {
    FOR(i, 0, 10) FOR(j, i, 10) {
        FOR(k, i, j + 1) {
            f[i][j] |= 1 << k;
        }
    }
    cin >> n >> m >> q;
    FOR(i, 0, n) {
        long long x; cin >> x;
        a[i] = x & 1;
    }
    ms(dp, -1);
    build(1, 0, n - 1);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; long long d; cin >> l >> r >> d; l--, r--, d &= 1;
            if (d) {
                upd(l), upd(r + 1);
                upd(1, l, r, 0, n - 1);
            }
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            if (r - l + 1 < m) {
                int id = 0;
                FOR(i, l, r + 1) b[i] = a[i] ^ query(i), id = id << 1 | b[i];
                int res = ff(id, l, r, -1, 0);
                cout << 2 - bit(res, r - l) << "\n";
                continue;
            }
            node_t res = query(1, l, r, 0, n - 1);
            int id = 0;
            FOR(i, r - m + 1, r + 1) b[i] = a[i] ^ query(i), id = id << 1 | b[i];
            int t = ff(id, r - m + 1, r, -1, 0);
            cout << 2 - bit(res.val1[t], m - 1) << "\n";
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