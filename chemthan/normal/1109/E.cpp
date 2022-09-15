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

template<typename num_t>
pair<num_t, num_t> euclid(num_t a, num_t b) {
    if (!b) return make_pair(1, 0);
    pair<num_t, num_t> r = euclid(b, a % b);
    return make_pair(r.second, r.first - a / b * r.second);
}

int invert(long long a, long long p) {
    return (euclid(a, p).fi % p + p) % p;
}

const int maxn = 1e5 + 5;
int n, mod, q;
int a[maxn];

int st[maxn << 2];
int lz[maxn << 2];
void push(int p, int L, int R) {
    if (lz[p] != 1) {
        st[p] = mult(st[p], lz[p], mod);
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i] = mult(lz[p << 1 | i], lz[p], mod);
            }
        }
        lz[p] = 1;
    }
}
void upd(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1];
    addmod(st[p], st[p << 1 | 1], mod);
}
void upd(int p, int i, int L, int R, int val) {
    push(p, L, R);
    if (R < i || i < L) return;
    if (L == R) {
        st[p] = val;
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1];
    addmod(st[p], st[p << 1 | 1], mod);
}
int query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return 0;
    if (l <= L && R <= r) return st[p];
    return (query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R)) % mod;
}

int fen[20][maxn];
void upd(int fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] = mult(fen[p], val, mod);
    }
}
int query(int fen[], int p) {
    p++;
    int res = 1;
    for (; p > 0; p -= p & -p) {
        res = mult(res, fen[p], mod);
    }
    return res;
}
void upd2(int fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query2(int fen[], int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void chemthan() {
    cin >> n >> mod;
    map<int, int> hs;
    int t = mod;
    for (int i = 2; i * i <= t; i++) {
        while (t % i == 0) hs[i]++, t /= i;
    }
    if (1 < t) hs[t]++;
    vi pr;
    for (auto& e : hs) {
        pr.pb(e.fi);
    }
    fill_n(fen[0], maxn, 1);
    FOR(i, 0, n) {
        cin >> a[i];
        upd(1, i, 0, n - 1, a[i] % mod);
        int ptr = 0;
        for (auto e : hs) {
            ptr++;
            int cnt = 0;
            while (a[i] % e.fi == 0) cnt++, a[i] /= e.fi;
            if (cnt) {
                upd2(fen[ptr], i, cnt);
                upd2(fen[ptr], i + 1, -cnt);
            }
        }
        upd(fen[0], i, a[i] % mod);
        upd(fen[0], i + 1, invert(a[i] % mod, mod));
    }
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            upd(1, l, r, 0, n - 1, x % mod);
            int ptr = 0;
            for (auto e : hs) {
                ptr++;
                int cnt = 0;
                while (x % e.fi == 0) cnt++, x /= e.fi;
                if (cnt) {
                    upd2(fen[ptr], l, cnt);
                    upd2(fen[ptr], r + 1, -cnt);
                }
            }
            upd(fen[0], l, x % mod);
            upd(fen[0], r + 1, invert(x % mod, mod));
        }
        else if (op == 2) {
            int u, x; cin >> u >> x; u--;
            int g = 1;
            for (int p : pr) {
                while (x % p == 0) {
                    g *= p;
                    x /= p;
                }
            }
            int r = query(fen[0], u);
            int t = 1;
            FOR(i, 0, sz(pr)) {
                int c = query2(fen[i + 1], u), total = 0;
                while (g % pr[i] == 0) {
                    c--, total++, g /= pr[i];
                }
                t = mult(t, fpow(pr[i], c, mod), mod);
                upd2(fen[i + 1], u, -total);
                upd2(fen[i + 1], u + 1, +total);
            }
            assert(g == 1);
            t = mult(t, r, mod);
            int ix = invert(x % mod, mod);
            upd(fen[0], u, ix);
            upd(fen[0], u + 1, x);
            t = mult(t, ix, mod);
            upd(1, u, 0, n - 1, t);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            cout << query(1, l, r, 0, n - 1) << "\n";
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