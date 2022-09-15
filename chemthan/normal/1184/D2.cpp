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
inline int mrand() {return abs((int) mt());}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";
 
void chemthan() {
    int n, k, m; cin >> n >> k >> m;
    if (k == 1 || k == n) {
        cout << n << "\n";
        return;
    }
    auto mul_vec = [&] (vi v, int k) {
        for (int& x : v) {
            x = mult(x, k);
        }
        return v;
    };
    auto add_vec = [&] (vi v1, vi v2) {
        assert(sz(v1) == sz(v2));
        FOR(i, 0, sz(v1)) {
            addmod(v1[i], v2[i]);
        }
        return v1;
    };
    auto sub_vec = [&] (vi v1, vi v2) {
        assert(sz(v1) == sz(v2));
        FOR(i, 0, sz(v1)) {
            submod(v1[i], v2[i]);
        }
        return v1;
    };
    vector<vector<vi>> dp(m, vector<vi>(m, vi(m)));
    vector<vector<vi>> f(m, vector<vi>(m, vi(m)));
    FOR(i, 1, m - 1) {
        dp[1][i][i] = 1;
        dp[0][i][0] = dp[i][0][0] = i + 1;
    }
    FOR(s, 0, 2) {
        FOR(a, 0, s + 1) {
            int b = s - a;
            if (b) {
                f[a][b] = add_vec(f[a][b - 1], dp[a][b]);
            }
            else {
                f[a][b] = dp[a][b];
            }
        }
    }
    FOR(s, 2, m) {
        FOR(a, 2, s) {
            int b = s - a;
            int x = mult(s, inv(mult(m, s - 1)));
            int y = (1 - mult(s, inv(m)) + MOD) % MOD;
            int p = mult(a, inv(s + 1));
            int q = mult(b + 1, inv(s + 1));
            dp[a][b] = dp[a - 1][b];
            dp[a][b] = sub_vec(dp[a][b], mul_vec(f[b][a - 2], x));
            dp[a][b] = sub_vec(dp[a][b], mul_vec(f[a - 1][b - 1], x));
            dp[a][b] = mul_vec(dp[a][b], inv(y));
            dp[a][b] = sub_vec(dp[a][b], mul_vec(dp[a - 1][b + 1], q));
            dp[a][b] = mul_vec(dp[a][b], inv(p));
        }
        FOR(a, 0, s + 1) {
            int b = s - a;
            if (b) {
                f[a][b] = add_vec(f[a][b - 1], dp[a][b]);
            }
            else {
                f[a][b] = dp[a][b];
            }
        }
    }
    auto gauss = [&] (vector<vi>& a) {
        int n = sz(a);
        FOR(i, 0, n) {
            if (!a[i][i]) {
                FOR(j, i + 1, n) if (a[j][i]) {
                    FOR(k, 0, n + 1) addmod(a[i][k], a[j][k]);
                    break;
                }
            }
            assert(a[i][i]);
            int t = inv(a[i][i]);
            FOR(j, 0, n + 1) a[i][j] = mult(a[i][j], t);
            FOR(j, 0, n) if (j ^ i) {
                t = a[j][i];
                FOR(k, 0, n + 1) submod(a[j][k], mult(a[i][k], t));
            }
        }
    };
    vector<vi> mat(m - 2, vi(m - 1));
    int ptr = 0;
    FOR(i, 2, m - 1) if (i % 2 == 0) {
        vi v = dp[i][1];
        submod(v[i], 1);
        FOR(j, 1, m) {
            mat[ptr][j - 1] = v[j];
        }
        submod(mat[ptr][m - 2], v[0]);
        ptr++;
    }
    FOR(i, 1, m - 1) if (ptr < m - 2) {
        vi v = dp[i][m - i - 1];
        v = sub_vec(v, mul_vec(f[i][m - i - 2], inv(m - 1)));
        v = sub_vec(v, mul_vec(f[m - i - 1][i - 1], inv(m - 1)));
        FOR(i, 1, m) {
            mat[ptr][i - 1] = v[i];
        }
        submod(mat[ptr][m - 2], v[0]);
        ptr++;
    }
    assert(ptr == m - 2);
    gauss(mat);
    int res = dp[k - 1][n - k][0];
    FOR(i, 1, m - 1) {
        addmod(res, mult(mat[i - 1][m - 2], dp[k - 1][n - k][i]));
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