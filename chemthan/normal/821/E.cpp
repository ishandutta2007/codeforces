#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

struct Matrix {
    static const int MAXN = 20;
    static const int MOD = (int) 1e9 + 7;
    int x[MAXN][MAXN];
    
    Matrix() {
        memset(x, 0, sizeof(x));
    }
    int* operator [] (int r) {
        return x[r];
    }
    static Matrix unit() {
        Matrix res;
        for (int i = 0; i < MAXN; i++) res[i][i] = 1;
        return res;
    }
    friend Matrix operator + (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = A[i][j] + B[i][j];
            if (res[i][j] >= MOD) res[i][j] -= MOD;
        }
        return res;
    }
    friend Matrix operator * (Matrix A, Matrix B) {
        Matrix res;
        for (int i = 0; i < MAXN; i++) for (int k = 0; k < MAXN; k++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = (res[i][j] + (long long) A[i][k] * B[k][j]) % MOD;
        }
        return res;
    }
    friend Matrix operator ^ (Matrix A, long long k) {
        if (k == 0) return unit();
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
int n;
long long k;
long long a[maxn];
long long b[maxn];
int c[maxn];

void solve() {
    cin >> n >> k;
    Matrix mat = Matrix::unit();
    FOR(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i];
        chkmin(b[i], k);
        Matrix t;
        FOR(j, 0, c[i] + 1) {
            if (j) {
                t[j - 1][j] = 1;
            }
            t[j][j] = 1;
            if (j + 1 <= c[i]) {
                t[j + 1][j] = 1;
            }
        }
        t = t ^ (b[i] - a[i]);
        mat = mat * t;
    }
    cout << mat[0][0] << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}