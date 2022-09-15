#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

int MAXN = 256;
struct Matrix {
    long long x[256][256];

    Matrix() {
        FOR(i, 0, MAXN) FOR(j, 0, MAXN) x[i][j] = LINF;
    }
    long long* operator [] (int r) {
        return x[r];
    }
    static Matrix unit() {
        Matrix res;
        FOR(i, 0, MAXN) FOR(j, 0, MAXN) res[i][j] = 0;
        return res;
    }
    friend Matrix operator * (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                chkmin(res[i][j], A[i][k] + B[k][j]);
            }
        }
        return res;
    }
    friend Matrix operator ^ (Matrix A, long long k) {
        if (!k) return unit();
        Matrix res, tmp;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = tmp[i][j] = A[i][j];
        }
        k--;
        while (k) {
            if (k & 1) res = res * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return res;
    }
};

const int maxn = 123;
int x, k, n, q;
int c[maxn];
map<int, int> hs;
map<int, int> hs2;

int query(int msk) {
    if (hs2.count(msk)) return hs2[msk];
    int res = sz(hs2);
    return hs2[msk] = res;
}

vector<long long> jump(vector<long long> vals, int len) {
    Matrix mat;
    FOR(msk, 0, 1 << k) if (bitcount(msk) == x) {
        if (!(msk & 1)) {
            mat[query(msk)][query(msk >> 1)] = 0;
        }
        else {
            FOR(i, 1, k + 1) if (!bit(msk, i)) {
                chkmin(mat[query(msk)][query((msk >> 1) | (1 << i - 1))], (long long) c[i]);
            }
        }
    }
    mat = mat ^ len;
    Matrix tmp;
    FOR(msk, 0, 1 << k) if (bitcount(msk) == x) tmp[0][query(msk)] = vals[query(msk)];
    mat = tmp * mat;
    vector<long long> res;
    FOR(i, 0, MAXN) res.pb(mat[0][i]);
    return res;
}
vector<long long> jumpone(vector<long long> vals, int pos) {
    vector<long long> res(MAXN, LINF);
    FOR(msk, 0, 1 << k) if (bitcount(msk) == x) {
        if (!(msk & 1)) {
            chkmin(res[query(msk >> 1)], vals[query(msk)]);
        }
        else {
            FOR(i, 1, k + 1) if (!bit(msk, i)) {
                chkmin(res[query((msk >> 1) | (1 << i - 1))], vals[query(msk)] + c[i] + (hs.count(pos + i) ? hs[pos + i] : 0));
            }
        }
    }
    return res;
}

void chemthan() {
    cin >> x >> k >> n >> q;
    FOR(msk, 0, 1 << k) if (bitcount(msk) == x) {
        query(msk);
    }
    MAXN = sz(hs2);
    n -= x - 1;
    FOR(i, 1, k + 1) cin >> c[i];
    vii vals;
    FOR(i, 0, q) {
        int u, w; cin >> u >> w;
        hs[u] = w;
        vals.pb(mp(u, w));
    }
    sort(all(vals));
    int st = 1;
    vector<long long> res(MAXN, LINF);
    res[query((1 << x) - 1)] = 0;
    while (st < n) {
        int d = upper_bound(all(vals), mp(st, INF + INF)) - vals.begin();
        int nst = n;
        if (d < sz(vals)) {
            chkmin(nst, vals[d].fi);
        }
        if (st < nst - k) {
            int len = nst - k - st;
            res = jump(res, len);
            st += len;
        }
        while (st < nst) {
            res = jumpone(res, st);
            st++;
        }
    }
    cout << res[query((1 << x) - 1)] << "\n";
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