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
    int query(char* t) {
        int k = strlen(t);
        int cur = -1;
        for (int i = 0; i < k; i++) {
            while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
            if (t[i] == s[cur + 1]) cur++;
            if (cur == n - 1) {
                return i - n + 1;
            }
        }
        return -1;
    }
} kmp;

const int maxn = 3000 + 5;
int n;
string a[maxn];
string b[maxn];
int l[maxn];
int r[maxn];

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    string s;
    int ix;
    FOR(i, 0, n) {
        cin >> b[i];
        l[i] = 0, r[i] = sz(a[i]) - 1;
        while (l[i] < sz(a[i]) && a[i][l[i]] == b[i][l[i]]) l[i]++;
        while (r[i] && a[i][r[i]] == b[i][r[i]]) r[i]--;
        if (l[i] <= r[i]) {
            if (s == "") {
                s = a[i].substr(l[i], r[i] - l[i] + 1);
                ix = i;
            }
            else if (s != a[i].substr(l[i], r[i] - l[i] + 1)) {
                cout << "NO\n";
                return;
            }
        }
    }
    while (l[ix]) {
        char c = -1;
        int ok = 1;
        FOR(i, 0, n) if (l[i] <= r[i]) {
            if (!l[i]) {
                ok = 0;
                break;
            }
            if (c == -1) {
                c = b[i][l[i] - 1];
            }
            else if (c != b[i][l[i] - 1]) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            break;
        }
        FOR(i, 0, n) if (l[i] <= r[i]) {
            l[i]--;
        }
    }
    while (r[ix] + 1 < sz(a[ix])) {
        char c = -1;
        int ok = 1;
        FOR(i, 0, n) if (l[i] <= r[i]) {
            if (r[i] == sz(b[i]) - 1) {
                ok = 0;
                break;
            }
            if (c == -1) {
                c = b[i][r[i] + 1];
            }
            else if (c != b[i][r[i] + 1]) {
                ok = 0;
                break;
            }
        }
        if (!ok) {
            break;
        }
        FOR(i, 0, n) if (l[i] <= r[i]) {
            r[i]++;
        }
    }
    s = a[ix].substr(l[ix], r[ix] - l[ix] + 1);
    string t = b[ix].substr(l[ix], r[ix] - l[ix] + 1);
    kmp.build((char *) s.data());
    FOR(i, 0, n) {
        if (l[i] <= r[i]) {
            if (kmp.query((char *) a[i].data()) < l[i]) {
                cout << "NO\n";
                return;
            }
        }
        else {
            if (kmp.query((char *) a[i].data()) != -1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    cout << s << "\n" << t << "\n";
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