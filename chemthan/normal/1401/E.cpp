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
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> vx;
    vector<tuple<int, int, int>> vy;
    FOR(i, 0, n) {
        int y, lx, rx; cin >> y >> lx >> rx;
        vx.pb({y, lx, rx});
    }
    FOR(i, 0, m) {
        int x, ly, ry; cin >> x >> ly >> ry;
        vy.pb({x, ly, ry});
    }
    auto calc = [&] (vector<tuple<int, int, int>> vx, vector<tuple<int, int, int>> vy) {
        int K = 1e6 + 5;
        vector<vi> fens(2, vi(K));
        auto upd = [&] (vi& fen, int p, int v) {
            p++;
            for (; p < K; p += p & -p) {
                fen[p] += v;
            }
        };
        auto query = [&] (vi& fen, int p) {
            p++;
            int res = 0;
            for (; 0 < p; p -= p & -p) {
                res += fen[p];
            }
            return res;
        };
        long long res = 0;
        vector<tuple<int, int, int>> events;
        FOR(i, 0, sz(vx)) {
            int y, lx, rx; tie(y, lx, rx) = vx[i];
            events.pb({rx, y, 1});
            events.pb({lx - 1, y, -1});
            if (!lx && rx == 1e6) {
                res += 2;
            }
        }
        sort(all(events));
        sort(all(vy));
        int ptr = 0;
        for (auto e : events) {
            while (ptr < sz(vy) && get<0>(vy[ptr]) <= get<0>(e)) {
                int x, ly, ry; tie(x, ly, ry) = vy[ptr];
                if (ry == 1e6) {
                    upd(fens[0], ly, 1);
                }
                else {
                    upd(fens[1], K - ry - 2, 1);
                }
                ptr++;
            }
            int x, y, s; tie(x, y, s) = e;
            res += query(fens[0], y) * s;
            res += query(fens[1], K - y - 2) * s;
        }
        return res;
    };
    cout <<  (calc(vx, vy) + calc(vy, vx)) / 2 + 1 << "\n";
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