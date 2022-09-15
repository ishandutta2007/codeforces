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

int n;
int ask(int i, int j, int k) {
    vi vals({i, j, k});
    sort(all(vals));
    static map<vi, int> hs;
    if (hs.count(vals)) return hs[vals];
    int& res = hs[vals];
    static int cnt = 0;
    assert(cnt++ < 4 * n);
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
    cout.flush();
    cin >> res;
    return res;
}

vi func(vi ver) {
    pi mn = mp(INF + INF, INF);
    FOR(i, 2, sz(ver)) {
        chkmin(mn, mp(ask(ver[0], ver[1], ver[i]), ver[i]));
    }
    return {ver[0], ver[1], mn.se};
}

void chemthan() {
    cin >> n;
    vi ver; FOR(i, 0, n) ver.pb(i);
    vi mns = func(ver);
    vi remains;
    FOR(i, 0, n) if (i != mns[0] && i != mns[1] && i != mns[2]) {
        remains.pb(i);
    }
    static long long t[3];
    for (int i : {mns[0], mns[1], mns[2], remains[0], remains[1]}) {
        for (int j : {mns[0], mns[1], mns[2], remains[0], remains[1]}) {
            for (int k : {mns[0], mns[1], mns[2], remains[0], remains[1]}) {
                if (i < j && j < k) {
                    int w = ask(i, j, k);
                    for (int u : {i, j, k}) {
                        FOR(v, 0, 3) if (mns[v] == u) {
                            t[v] += w;
                        }
                    }
                }
            }
        }
    }
    pair<long long, int> mnl = mp(LINF, INF);
    FOR(i, 0, 3) {
        chkmin(mnl, mp(t[i], mns[i]));
    }
    int x = mnl.se;
    FOR(i, 0, sz(ver)) if (ver[i] == x) {
        swap(ver[i], ver.back());
        ver.pop_back();
        break;
    }
    mns = func(ver);
    remains.clear();
    FOR(i, 0, n) if (i != x && i != mns[0] && i != mns[1] && i != mns[2]) {
        remains.pb(i);
    }
    int c = remains[0];
    FOR(i, 0, 3) {
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        t[i] = (long long) ask(x, mns[i], mns[j]) + ask(x, mns[i], mns[k]);
    }
    int d = -1;
    FOR(i, 0, 3) {
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        if (t[i] > t[j] && t[i] > t[k]) {
            d = mns[i];
        }
    }
    if (d == -1) {
        pair<long long, int> mx = mp(-INF - INF, -INF);
        FOR(i, 0, 3) {
            int j = (i + 1) % 3;
            int k = (j + 1) % 3;
            chkmax(mx, mp((long long) ask(c, mns[i], mns[j]) + ask(c, mns[i], mns[k]), mns[i]));
        }
        d = mx.se;
    }
    FOR(i, 0, sz(mns)) if (mns[i] == d) {
        swap(mns[i], mns.back());
        mns.pop_back();
    }
    pi mn = mp(INF + INF, INF);
    FOR(i, 0, 2) {
        chkmin(mn, mp(ask(c, d, mns[i]), mns[i]));
    }
    int y = mn.se;
    static int res[1234];
    vi vals({mns[0] + mns[1] - y, c, d});
    sort(all(vals), [&] (int u, int v) {
            return ask(x, y, u) < ask(x, y, v);
            }
        );
    int u = ask(x, y, vals[0]);
    int v = ask(vals[0], vals[1], vals[2]);
    int w = ask(x, y, vals[2]);
    res[x] = ((long long) u + v + w) / 2 - v;
    res[y] = ask(y, vals[0], vals[2]) - (((long long) u + v + w) / 2 - u);
    FOR(i, 0, n) if (i != x && i != y) {
        res[i] = ask(x, y, i) - res[x];
    }
    cout << "! ";
    FOR(i, 0, n) {
        cout << res[i] << " \n"[i == n - 1];
    }
    cout.flush();
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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