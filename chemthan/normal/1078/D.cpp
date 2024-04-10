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
//const int MOD = (int) 1e9 + 7;
const int MOD = 998244353;
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
RMQ<pi, greater<pi> > rmq[2];

const int maxn = 2e5 + 5;
const int logn = 20;
int n;
int a[maxn];
int l[logn][maxn];
int r[logn][maxn];

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i], a[i + n] = a[i];
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    rmq[0].init(n + n);
    rmq[1].init(n + n);
    FOR(i, 0, n + n) {
        rmq[0].upd(i, mp(a[i] + i, i));
        rmq[1].upd(i, mp(a[i] - i, i));
    }
    rmq[0].build();
    rmq[1].build();
    FOR(u, 0, n) {
        l[0][u] = r[0][u] = a[u];
    }
    FOR(i, 0, logn - 1) {
        FOR(u, 0, n) {
            if (l[i][u] + r[i][u] >= n - 1) {
                l[i + 1][u] = r[i + 1][u] = n;
            }
            else {
                int uu = u;
                int pu = u - l[i][u];
                int nu = u + r[i][u];
                if (pu < 0) {
                    uu += n;
                    pu += n;
                    nu += n;
                }
                int x = rmq[0].query(pu, nu).se;
                int y = rmq[1].query(pu, nu).se;
                chkmax(l[i + 1][u], uu - x + l[i][x % n]);
                chkmax(l[i + 1][u], uu - y + l[i][y % n]);
                chkmax(r[i + 1][u], x - uu + r[i][x % n]);
                chkmax(r[i + 1][u], y - uu + r[i][y % n]);
            }
        }
    }
    FOR(u, 0, n) {
        int res = 0;
        int ll = 0, rr = 0;
        FORd(i, logn, 0) {
            int uu = u;
            int pu = u - ll;
            int nu = u + rr;
            if (pu < 0) {
                uu += n;
                pu += n;
                nu += n;
            }
            int x = rmq[0].query(pu, nu).se;
            int y = rmq[1].query(pu, nu).se;
            int nll = uu - y + l[i][y % n];
            chkmax(nll, uu - x + l[i][x % n]);
            int nrr = x - uu + r[i][x % n];
            chkmax(nrr, y - uu + r[i][y % n]);
            if (nll + nrr < n - 1) {
                res += 1 << i;
                ll = nll, rr = nrr;
            }
        }
        cout << res + 1 << " \n"[u == n - 1];
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