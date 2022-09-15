#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

struct BinaryMatrix {
    static const int MAXN = 500 + 5;
    bitset<MAXN> x[MAXN];
    
    BinaryMatrix() {
        memset(x, 0, sizeof(x));
    }
    bitset<MAXN>& operator [] (int r) {
        return x[r];
    }
    static BinaryMatrix unit() {
        BinaryMatrix res;
        for (int i = 0; i < MAXN; i++) res[i][i] = 1;
        return res;
    }
    friend BinaryMatrix operator + (BinaryMatrix A, BinaryMatrix B) {
        BinaryMatrix res;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = A[i][j] ^ B[i][j];
        }
        return res;
    }
    friend BinaryMatrix operator * (BinaryMatrix A, BinaryMatrix B) {
        BinaryMatrix res, tmp;
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            tmp[i][j] = B[j][i];
        }
        for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) {
            res[i][j] = (A[i] & tmp[j]).any();
        }
        return res;
    }
    friend BinaryMatrix operator ^ (BinaryMatrix A, long long k) {
        if (k == 0) return unit();
        BinaryMatrix res, tmp;
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
    //Caculate geometric series: A^0 + A^1 + ... + A^k
    friend BinaryMatrix geometricseries(BinaryMatrix A, long long k) {
        if (k == 0) return unit();
        if (k == 1) return A + unit();
        vector<int> bit;
        while (k) {
            bit.push_back(k & 1);
            k >>= 1;
        }
        BinaryMatrix res = A, tmp = A;
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

const int maxn = 500 + 5;
const int maxk = 63;
int n, m;
BinaryMatrix can[2][maxk];
long long dp[maxn][maxk][2];

long long calc(int u, int k, int fa) {
    if (k == -1) return 0;
    long long& res = dp[u][k][fa];
    if (~res) return res;
    res = calc(u, k - 1, fa);
    FOR(v, 0, n) if (can[fa][k][u][v]) {
        chkmax(res, calc(v, k - 1, !fa) + (1LL << k));
        chkmin(res, LINF + 1);
    }
    return res;
}

void solve() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        can[w][0][u][v] = 1;
    }
    FOR(k, 1, maxk) {
        can[0][k] = can[0][k - 1] * can[1][k - 1];
        can[1][k] = can[1][k - 1] * can[0][k - 1];
    }
    FOR(u, 0, 1) FOR(v, 0, n) {
        if (can[0][maxk - 1][u][v]) {
            cout << -1 << "\n";
            return;
        }
    }
    ms(dp, -1);
    long long ans = 0;
    FOR(u, 0, 1) {
        chkmax(ans, calc(u, maxk - 1, 0));
    }
    if (ans > LINF) ans = -1;
    cout << ans << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}