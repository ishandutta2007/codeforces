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
    auto ispr = [&] (int k) {
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                return 0;
            }
        }
        return 1;
    };
    vi prs;
    vector<vi> p10s;
    vector<vi> ip10s;
    FOR(it, 0, 3) {
        int pr = INF - mrand(INF / 100);
        while (!ispr(pr)) pr++;
        prs.pb(pr);
        vi p10;
        vi ip10;
        int i10 = inv(10, pr);
        int t = 1;
        int t2 = 1;
        FOR(i, 0, 1e6) {
            p10.pb(t);
            ip10.pb(t2);
            t = mult(t, 10, pr);
            t2 = mult(t2, i10, pr);
        }
        p10s.pb(p10);
        ip10s.pb(ip10);
    }
    string s; cin >> s;
    string x; cin >> x;
    reverse(all(s)), reverse(all(x));
    for (char& c : s) c -= '0';
    for (char& c : x) c -= '0';
    int n = sz(s);
    vector<vi> hs;
    vector<map<int, int>> mems;
    FOR(ix, 0, sz(prs)) {
        map<int, int> mem;
        vi h;
        int t = 0;
        FOR(i, 0, n) {
            addmod(t, mult(p10s[ix][i], s[i], prs[ix]), prs[ix]);
            h.pb(t);
            mem[t] = i;
        }
        hs.pb(h);
        mems.pb(mem);
    }
    vi hx;
    vector<vi> hxs;
    FOR(ix, 0, sz(prs)) {
        int t = 0;
        FOR(i, 0, sz(x)) {
            addmod(t, mult(p10s[ix][i], x[i], prs[ix]), prs[ix]);
        }
        hx.pb(t);
        {
            vi tmp;
            int t = 0;
            FORd(i, sz(x), 0) {
                t = mult(t, 10, prs[ix]);
                addmod(t, x[i], prs[ix]);
                tmp.pb(t);
            }
            hxs.pb(tmp);
        }
    }
    auto calc = [&] (int ix, int l, int r) {
        int res = hs[ix][r];
        if (l) submod(res, hs[ix][l - 1], prs[ix]);
        return mult(res, ip10s[ix][l], prs[ix]);
    };

    FOR(i, 0, n) {
        for (int len : {sz(x) - 1, sz(x)}) {
            if (!len) continue;
            if (n <= i + len) continue;
            map<int, int> cnt;
            FOR(ix, 0, sz(prs)) {
                int h = hx[ix];
                submod(h, calc(ix, i, i + len - 1), prs[ix]);
                h = mult(h, p10s[ix][i + len], prs[ix]);
                addmod(h, hs[ix][i + len - 1], prs[ix]);
                if (mems[ix].count(h)) {
                    cnt[mems[ix][h]]++;
                }
                else {
                    break;
                }
            }
            for (auto [x, c] : cnt) {
                if (c == sz(prs) && i + len <= x) {
                    int u = i;
                    int v = i + len - 1;
                    int w = i + len;
                    int t = x;
                    cout << n - t << " " << n - w << "\n" << n - v << " " << n - u << "\n";
                    return;
                }
            }
        }
    }
    FOR(i, 0, n) {
        for (int len : {sz(x) - 1, sz(x)}) {
            if (!len) continue;
            if (i - len < 0) continue;
            map<int, int> cnt;
            FOR(ix, 0, sz(prs)) {
                int t = calc(ix, i - len + 1, i);
                vi len2s;
                if (len == sz(x) - 1) {
                    len2s.pb(len);
                }
                else {
                    int lo = i - len + 1, hi = i;
                    while (lo < hi) {
                        int mi = lo + hi >> 1;
                        if (calc(ix, mi, i) != hxs[ix][i - mi]) {
                            lo = mi + 1;
                        }
                        else {
                            hi = mi;
                        }
                    }
                    int mi = lo + hi >> 1;
                    int tmp = mi - (i - len + 1);
                    if (0 < tmp) {
                        len2s.pb(tmp);
                    }
                    if (0 < tmp - 1) {
                        len2s.pb(tmp - 1);
                    }
                }
                for (int len2 : len2s) if (0 <= i - len - len2 + 1) {
                    int y = t;
                    addmod(y, calc(ix, i - len - len2 + 1, i - len), prs[ix]);
                    if (y == hx[ix]) {
                        cnt[i - len - len2 + 1]++;
                    }
                }
            }
            for (auto [x, c] : cnt) {
                if (c == sz(prs)) {
                    int u = x;
                    int v = i - len;
                    int w = i - len + 1;
                    int t = i;
                    cout << n - t << " " << n - w << "\n" << n - v << " " << n - u << "\n";
                    return;
                }
            }
        }
    }
}

int32_t main(int32_t argc, char* argv[]) {
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