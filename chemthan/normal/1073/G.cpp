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

struct SuffixArray {
    static const int maxn = 2e5 + 5;
    static const char SEP = '$';

    int n;
    char s[maxn];
    int sa[maxn], ra[2][maxn];
    int lcp[maxn];

    void build(char* t) {
        strcpy(s, t), n = strlen(s);
        for (int i = 0; i < n; i++) {
            sa[i] = i, ra[0][i] = 0, ra[1][i] = s[i] + 1;
        }
        for (int d = 1; radixsort(); d <<= 1) {
            for (int i = 0; i < n; i++) {
                if (i + d < n) {
                    ra[1][i] = ra[0][i + d] + 1;
                }
                else {
                    ra[1][i] = 0;
                }
            }
        }
        buildlcp();
    }

    int radixsort() {
        static int p[maxn];
        static int tmpsa[maxn];
        static int tmpra[maxn];
        int mx = max(256, n) + 1;
        for (int step = 1; step >= 0; step--) {
            fill_n(p, mx, 0);
            for (int i = 0; i < n; i++) {
                p[ra[step][i] + 1]++;
                tmpsa[i] = sa[i];
            }
            partial_sum(p, p + mx, p);
            for (int i = 0; i < n; i++) {
                sa[p[ra[step][tmpsa[i]]]++] = tmpsa[i];
            }
        }
        int ptr = 0;
        tmpra[sa[0]] = ptr;
        for (int i = 1; i < n; i++) {
            int u = sa[i - 1];
            int v = sa[i];
            if (ra[0][u] < ra[0][v] || ra[1][u] < ra[1][v]) {
                ptr++;
            }
            tmpra[v] = ptr;
        }
        for (int i = 0; i < n; i++) ra[0][i] = tmpra[i];
        return ptr < n - 1;
    }

    void buildlcp() {
        for (int i = 0, k = 0; i < n; i++) {
            if (!ra[0][i]) lcp[ra[0][i]] = 0;
            else {
                for (int j = sa[ra[0][i] - 1]; s[i + k] == s[j + k] && s[i + k] != SEP; k++);
                lcp[ra[0][i]] = k;
                k = max(k - 1, 0);
            }
        }
    }
} sa;

template<class T, class cmp = less<T> > struct RMQ {
    int n;
    vector<T> a;
    vector<vector<T> > f;

    T best(T a, T b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int n) {
        this->n = n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    void upd(int u, T x) {
        a[u] = x;
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    T query(int a, int b) {
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int> rmq;

const int maxn = 2e5 + 5;
const int magic = 1000;
int n, q;
string s;
int dj[maxn];
int dx[maxn];
int dy[maxn];
long long dd[maxn];
int fx[maxn];
int fy[maxn];

int query(int u, int v) {
    if (u == v) return n - u;
    u = sa.ra[0][u], v = sa.ra[0][v];
    if (u > v) swap(u, v);
    return rmq.query(u + 1, v);
}

int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v, int val) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        dd[q] += (long long) dx[p] * dy[q] * val;
        dd[q] += (long long) dx[q] * dy[p] * val;
        dx[q] += dx[p];
        dy[q] += dy[p];
        dd[q] += dd[p];
    }
}

void chemthan() {
    cin >> n >> q >> s;
    sa.build((char *) s.data());
    rmq.init(n);
    FOR(i, 0, n) rmq.upd(i, sa.lcp[i]);
    rmq.build();
    vii vals;
    FOR(i, 1, n) vals.pb(mp(sa.lcp[i], i));
    sort(all(vals), greater<pi>());
    while (q--) {
        int u, v; cin >> u >> v;
        vi va(u), vb(v);
        for (int& x : va) cin >> x, x--;
        for (int& y : vb) cin >> y, y--;
        if (sz(va) < magic) {
            long long res = 0;
            for (int x : va) {
                for (int y : vb) {
                    res += query(x, y);
                }
            }
            cout << res << "\n";
        }
        else {
            for (int x : va) fx[sa.ra[0][x]] = 1;
            for (int y : vb) fy[sa.ra[0][y]] = 1;
            FOR(i, 0, n) {
                dj[i] = i, dx[i] = fx[i], dy[i] = fy[i];
                dd[i] = 0;
                if (fx[i] && fy[i]) {
                    dd[i] = n - sa.sa[i];
                }
            }
            for (pi p : vals) {
                int u = p.fi;
                int v = p.se;
                join(v, v - 1, u);
            }
            int rt = find(0);
            cout << dd[rt] << "\n";
            for (int x : va) fx[sa.ra[0][x]] = 0;
            for (int y : vb) fy[sa.ra[0][y]] = 0;
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