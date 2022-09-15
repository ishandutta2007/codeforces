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

const int maxn = 100 + 5;
int n, m;
int s[maxn];
int h[maxn];
int a[maxn];
map<int, int> hs;

int solve1(int u) {
    vi left, right;
    vi res;
    FOR(i, 0, m) {
        if (s[i] <= u) {
            left.pb(i);
        }
        else if (s[i] > u) {
            right.pb(i);
        }
    }
    if (!sz(left)) {
        return 0;
    }
    int st = sz(left) - 1, tmp = u;
    while (st >= 0) {
        int ok = 0;
        FOR(i, 0, st + 1) {
            long long pts = h[left[i]];
            int found = 0;
            FOR(j, s[left[i]], tmp + 1) {
                pts += a[j];
                if (pts < 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                res.pb(left[i]);
                FOR(j, i + 1, st + 1) {
                    res.pb(left[j]);
                }
                ok = 1, st = i - 1, tmp = s[left[i]] - 1;
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    st = 0, tmp = u + 1;
    while (st < sz(right)) {
        int ok = 0;
        FORd(i, sz(right), st) {
            long long pts = h[right[i]];
            int found = 0;
            FORd(j, s[right[i]] + 1, tmp) {
                pts += a[j];
                if (pts < 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                res.pb(right[i]);
                FORd(j, i, st) {
                    res.pb(right[j]);
                }
                ok = 1, st = i + 1, tmp = s[right[i]] + 1;
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    cout << u + 1 << "\n";
    FOR(i, 0, sz(res)) cout << hs[s[res[i]]] + 1 << " \n"[i == sz(res) - 1];
    return 1;
}

int solve2(int u) {
    vi left, right;
    vi res;
    FOR(i, 0, m) {
        if (s[i] < u) {
            left.pb(i);
        }
        else if (s[i] >= u) {
            right.pb(i);
        }
    }
    if (!sz(right)) {
        return 0;
    }
    int st = 0, tmp = u;
    while (st < sz(right)) {
        int ok = 0;
        FORd(i, sz(right), st) {
            long long pts = h[right[i]];
            int found = 0;
            FORd(j, s[right[i]] + 1, tmp) {
                pts += a[j];
                if (pts < 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                res.pb(right[i]);
                FORd(j, i, st) {
                    res.pb(right[j]);
                }
                ok = 1, st = i + 1, tmp = s[right[i]] + 1;
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    st = sz(left) - 1, tmp = u - 1;
    while (st >= 0) {
        int ok = 0;
        FOR(i, 0, st + 1) {
            long long pts = h[left[i]];
            int found = 0;
            FOR(j, s[left[i]], tmp + 1) {
                pts += a[j];
                if (pts < 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                res.pb(left[i]);
                FOR(j, i + 1, st + 1) {
                    res.pb(left[j]);
                }
                ok = 1, st = i - 1, tmp = s[left[i]] - 1;
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    cout << u + 1 << "\n";
    FOR(i, 0, sz(res)) cout << hs[s[res[i]]] + 1 << " \n"[i == sz(res) - 1];
    return 1;
}

void chemthan() {
    cin >> n >> m;
    vii vals;
    FOR(i, 0, m) cin >> s[i] >> h[i], s[i]--, vals.pb(mp(s[i], h[i])), hs[s[i]] = i;
    sort(all(vals));
    FOR(i, 0, m) s[i] = vals[i].fi, h[i] = vals[i].se;
    FOR(i, 0, n) cin >> a[i];
    FOR(u, 0, n) {
        if (solve1(u)) {
            return;
        }
        if (solve2(u)) {
            return;
        }
    }
    cout << -1 << "\n";
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