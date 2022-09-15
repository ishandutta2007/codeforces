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

const int maxn = 1e6 + 5;
int n, q;
int a[maxn];
int x[maxn];
int y[maxn];
int l[maxn];
int r[maxn];
long long res[maxn];

long long fen[3][maxn];
void upd(long long fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
long long query(long long fen[], int p) {
    p++;
    long long res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void calc() {
    vector<pair<int, pi> > events;
    FOR(i, 0, q) {
        events.pb(mp(r[i], mp(1, i)));
        if (l[i]) {
            events.pb(mp(l[i] - 1, mp(-1, i)));
        }
    }
    sort(all(events)), reverse(all(events));
    ms(fen, 0);
    FOR(i, 0, n) {
        upd(fen[0], n - x[i], i - x[i]);
        upd(fen[1], x[i], i);
        upd(fen[2], x[i], 1);
        while (sz(events) && events.back().fi == i) {
            int sign = events.back().se.fi;
            int ix = events.back().se.se;
            events.pop_back();
            res[ix] += sign * query(fen[0], n - l[ix]);
            res[ix] += sign * (query(fen[1], l[ix] - 1) - query(fen[2], l[ix] - 1) * l[ix]);
        }
    }
}

void chemthan() {
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i], a[i]--;
    FOR(i, 0, q) {
        cin >> l[i], l[i]--;
    }
    FOR(i, 0, q) {
        cin >> r[i], r[i]--;
    }
    FOR(i, 0, n) x[i] = y[i] = i;
    FOR(i, 1, n) {
        int ptr = i;
        while (ptr && a[ptr - 1] < a[i]) ptr = x[ptr - 1];
        x[i] = ptr;
    }
    FORd(i, n - 1, 0) {
        int ptr = i;
        while (ptr + 1 < n && a[ptr + 1] < a[i]) ptr = y[ptr + 1];
        y[i] = ptr;
    }
    calc();
    FOR(i, 0, n) {
        swap(x[i], y[i]);
        x[i] = n - x[i] - 1, y[i] = n - y[i] - 1;
    }
    for (int i = 0; i < n - i; i++) {
        swap(x[i], x[n - i - 1]);
        swap(y[i], y[n - i - 1]);
    }
    FOR(i, 0, q) {
        swap(l[i], r[i]);
        l[i] = n - l[i] - 1, r[i] = n - r[i] - 1;
    }
    calc();
    FOR(i, 0, q) {
        cout << res[i] + r[i] - l[i] + 1 << " \n"[i == q - 1];
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