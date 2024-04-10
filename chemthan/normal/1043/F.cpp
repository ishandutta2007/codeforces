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

const int maxn = 3e5 + 5;
int sp[maxn];
int n;
int f[maxn];
int g[maxn];
int h[maxn];
vector<vi> gg[10];

void rec(int msk, vi vals, int num) {
    if (!msk) {
        gg[sz(vals)].pb(vals);
        return;
    }
    int k = __lg(msk);
    vals[k] = num;
    msk ^= 1 << k;
    for (int submsk = msk; submsk; submsk = (submsk - 1) & msk) {
        int nmsk = msk ^ submsk;
        vi nvals = vals;
        FOR(i, 0, sz(vals)) if (bit(submsk, i)) {
            nvals[i] = num;
        }
        rec(nmsk, nvals, num + 1);
    }
    rec(msk, vals, num + 1);
}

void chemthan() {
    FOR(i, 1, 6 + 1) {
        vi vals(i);
        rec((1 << i) - 1, vals, 0);
    }
    FOR(i, 1, maxn) sp[i] = i;
    FOR(i, 2, maxn) if (sp[i] == i) {
        for (int j = i + i; j < maxn; j += i) {
            chkmin(sp[j], i);
        }
    }
    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        f[x]++;
    }
    FOR(i, 1, maxn) {
        for (int j = i; j < maxn; j += i) {
            g[i] += f[j];
        }
        g[i] = n - g[i];
    }
    FOR(i, 1, maxn) {
        map<int, int> hs;
        int t = i;
        while (t > 1) {
            hs[sp[t]] = 1;
            t /= sp[t];
        }
        vi vals;
        for (auto it : hs) {
            vals.pb(it.fi);
        }
        static int ff[1 << 10];
        ff[0] = 1;
        FOR(msk, 0, 1 << sz(vals)) {
            if (msk) {
                int k = __lg(msk);
                int nmsk = msk ^ (1 << k);
                ff[msk] = ff[nmsk] * vals[k];
            }
            if (bitcount(msk) & 1) {
                h[i] += g[ff[msk]];
            }
            else {
                h[i] -= g[ff[msk]];
            }
        }
    }
    int res = INF;
    FOR(i, 1, maxn) if (f[i]) {
        if (i == 1) {
            res = 1;
            break;
        }
        map<int, int> hs;
        int t = i;
        while (t > 1) {
            hs[sp[t]] = 1;
            t /= sp[t];
        }
        vi vals;
        for (auto it : hs) {
            vals.pb(it.fi);
        }
        for (auto it : gg[sz(vals)]) {
            int num = *max_element(all(it)) + 1;
            vi tmp(num, 1);
            FOR(j, 0, sz(it)) {
                tmp[it[j]] *= vals[j];
            }
            int ok = 1;
            FOR(j, 0, num) {
                int u = tmp[j];
                if (!h[u]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                chkmin(res, num + 1);
            }
        }
    }
    if (res == INF) res = -1;
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