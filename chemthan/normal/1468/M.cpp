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

template<class TK, class TV> struct HashTable {
    static const int MAXN = 20000000;
    static const int MAGIC = 7654321;
    int ptr;
    int lst[MAGIC];
    int prv[MAXN];
    TK l[MAXN];
    TV x[MAXN];
    int cnt;
    int used[MAGIC];

    HashTable() {
        ptr = 0;
        fill_n(lst, MAGIC, -1);
        cnt = 0;
    }
    void clear() {
        ptr = 0;
        for (int i = 0; i < cnt; i++) {
            lst[used[i]] = -1;
        }
        cnt = 0;
    }
    TV& operator [] (const TK& key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        if (!~lst[hs]) {
            used[cnt++] = hs;
        }
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                return x[e];
            }
        }
        l[ptr] = key, x[ptr] = 0;
        prv[ptr] = lst[hs], lst[hs] = ptr;
        return x[ptr++];
    }
    int count(TK key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                return 1;
            }
        }
        return 0;
    }
    void erase(TK key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        int nxt = -1;
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                if (!~nxt) {
                    lst[hs] = prv[e];
                }
                else {
                    prv[nxt] = prv[e];
                }
                return;
            }
            nxt = e;
        }
    }
};

HashTable<long long, int> hs;

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<vi> a(n);
        vi dc;
        FOR(i, 0, n) {
            int k; cin >> k;
            while (k--) {
                int x; cin >> x;
                a[i].pb(x);
                dc.pb(x);
            }
            sort(all(a[i]));
        }
        sort(all(dc)), uni(dc);
        FOR(i, 0, n) {
            for (int& x : a[i]) x = lower_bound(all(dc), x) - dc.begin();
        }
        vi perm(n);
        FOR(i, 0, n) perm[i] = i;
        sort(all(perm), [&] (int u, int v) {
                return sz(a[v]) < sz(a[u]);
                }
            );
        vi f(sz(dc));
        auto solve = [&] () {
            FOR(i, 0, n) {
                for (int x : a[i]) {
                    long long key = (long long) i * INF + x;
                    hs[key] = 1;
                }
            }
            auto check = [&] (int j) {
                int num = 0;
                for (int x : a[j]) {
                    if (f[x]) {
                        num++;
                    }
                }
                return 2 <= num;
            };
            int magic = min(n, 500);
            FOR(i, 0, magic) {
                for (int x : a[perm[i]]) {
                    f[x] = 1;
                }
                FOR(j, i + 1, n) {
                    if (check(perm[j])) {
                        cout << perm[i] + 1 << " " << perm[j] + 1 << "\n";
                        return;
                    }
                }
                for (int x : a[perm[i]]) {
                    f[x] = 0;
                }
            }
            hs.clear();
            FOR(ii, magic, n) {
                int i = perm[ii];
                FOR(u, 0, sz(a[i])) FOR(v, u + 1, sz(a[i])) {
                    int x = a[i][u];
                    int y = a[i][v];
                    long long key = (long long) x * INF + y;
                    auto& t = hs[key];
                    if (t) {
                        cout << t << " " << i + 1 << "\n";
                        return;
                    }
                    t = i + 1;
                }
            }
            cout << -1 << "\n";
        };
        solve();
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