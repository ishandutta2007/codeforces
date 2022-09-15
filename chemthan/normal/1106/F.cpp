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
//const int mod = (int) 1e9 + 7;
const int mod = 119 << 23 | 1;
const int FFTmod = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = mod) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = mod) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = mod) {return (ll) a * b % p;}
inline int inv(int a, int p = mod) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct Matrix {
    static const int maxn = 100 + 5;
    static const int mod = 119 << 23;
    int x[maxn][maxn];

    Matrix() {
        memset(x, 0, sizeof(x));
    }
    int* operator [] (int r) {
        return x[r];
    }
    static Matrix unit() {
        Matrix res;
        for (int i = 0; i < maxn; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator + (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) {
            res[i][j] = A[i][j] + B[i][j];
            if (res[i][j] >= mod) res[i][j] -= mod;
        }
        return res;
    }
    friend Matrix operator * (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) {
            long long SQmod = (long long) mod * mod;
            long long sum = 0;
            for (int k = 0; k < maxn; k++) {
                sum += (long long) A[i][k] * B[k][j];
                if (sum >= SQmod) sum -= SQmod;
            }
            res[i][j] = sum % mod;
        }
        return res;
    }
    friend Matrix operator ^ (Matrix A, long long k) {
        if (k == 0) return unit();
        Matrix res, tmp;
        for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) {
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
    //Calculate geometric series: A^0 + A^1 + ... + A^k
    friend Matrix geometricseries(Matrix A, long long k) {
        if (k == 0) return unit();
        if (k == 1) return A + unit();
        vector<int> bit;
        while (k) {
            bit.push_back(k & 1);
            k >>= 1;
        }
        Matrix res = A, tmp = A;
        for (int i = bit.size() - 2; i >= 0; i--) {
            res = res + (res * tmp);
            tmp = tmp * tmp;
            if (bit[i] & 1) {
                tmp = tmp * A;
                res = res + tmp;
            }
        }
        res = res + unit();
        return res;
    }
};

const int maxn = 100 + 5;
int k;
int b[maxn];
int n, m;

template<class num_t>
pair<num_t, num_t> euclid(num_t a, num_t b) {
    if (!b) return make_pair(1, 0);
    pair<num_t, num_t> r = euclid(b, a % b);
    return make_pair(r.second, r.first - a / b * r.second);
}

int inverse(int x, int p) {
    auto res = euclid(x, p);
    return (res.fi % p + p) % p;
}

int find(int x) {
    static const int magic = 32000;
    map<int, int> hs;
    int t = 1;
    FOR(i, 0, magic) {
        hs[t] = i;
        t = (long long) 3 * t % mod;
    }
    int step = fpow(inv(3), magic);
    FOR(i, 0, magic) {
        if (hs.count(x)) {
            return i * magic + hs[x];
        }
        x = (long long) x * step % mod;
    }
    assert(0);
}

void chemthan() {
    cin >> k;
    FOR(i, 0, k) cin >> b[i];
    cin >> n >> m;
    Matrix mat;
    FOR(i, 0, k) mat[0][i] = b[i];
    FOR(i, 1, k) mat[i][i - 1] = 1;
    mat = mat ^ (n - k);
    m = find(m);
    int x = mat[0][0];
    int y = mod - 1;
    int g = __gcd(x, y);
    if (m % g) {
        cout << -1 << "\n";
        return;
    }
    int res = (long long) mult(m / g, inverse(x / g, y / g), y / g);
    cout << fpow(3, res) << "\n";
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