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

struct KMP {
    string s;
    int n;
    vector<int> link;
    void build(char* str) {
        s = str, n = (int) s.size();
        link.resize(n);
        int cur = link[0] = -1;
        for (int i = 1; i < n; i++) {
            while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
            if (s[i] == s[cur + 1]) cur++;
            link[i] = cur;
        }
    }
    vector<int> query(char* t) {
        vector<int> res;
        int k = strlen(t);
        int cur = -1;
        for (int i = 0; i < k; i++) {
            while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
            if (t[i] == s[cur + 1]) cur++;
            if (cur == n - 1) {
                res.push_back(i - n + 1);
                cur = link[cur];
            }
        }
        return res;
    }
} kmp;

struct ZFuntion {
    int n;
    vector<int> f; //the length of the longest substr begins at i
    void build(char* s) {
        n = strlen(s), f.resize(n);
        int l = 0, r = 0;
        f[0] = n;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && s[r] == s[r - l]) r++;
                f[i] = r - l, r--;
            }
            else {
                int k = i - l;
                if (f[k] < r - i + 1) f[i] = f[k];
                else {
                    l = i;
                    while (r < n && s[r] == s[r - l]) r++;
                    f[i] = r - l, r--;
                }
            }
        }
    }
} zf;

const int maxn = 2e5 + 5;
int fen[maxn];

void upd(int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query(int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void chemthan() {
    string s, t; cin >> s >> t;
    kmp.build((char *) t.data());
    zf.build((char *) (t + s).data());
    FOR(i, 0, sz(t)) {
        if (kmp.link[i] == -1) {
            upd(maxn - 2, 1);
        }
        else {
            upd(i - kmp.link[i], 1);
        }
    }
    long long res = 0;
    FOR(i, 0, sz(s)) {
        if (i == sz(s) - 1) {
            res += sz(t);
        }
        else {
            int k = min(sz(s) - i - 1, min(sz(t), zf.f[sz(t) + i + 1]));
            res += sz(t) - query(k);
        }
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