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
template<class T> inline void addmod(T& a, T val, T p = MOD) {if ((a = (a + val)) >= p) a -= p;}
template<class T> inline void submod(T& a, T val, T p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
int n;
long long s;
int p[maxn];
int a[maxn];

int check(int mi, long long s) {
    ms(a, 0);
    priority_queue<pi, vii, greater<pi> > heap;
    heap.push(mp(1, 0));
    s -= n;
    int mx = 1;
    FOR(i, 1, n) {
        int found = 0;
        while (sz(heap)) {
            int x = heap.top().fi;
            int u = heap.top().se;
            heap.pop();
            int len = n - i - 1;
            int st = max(mx, x + 1);
            //st, st + len - 1
            if (s >= x && s - x <= (long long) (st + st + len - 1) * len / 2) {
                if (++a[u] < mi) {
                    heap.push(mp(x, u));
                }
                s -= x;
                p[i] = u;
                heap.push(mp(x + 1, i));
                chkmax(mx, x + 1);
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return !s;
}

void chemthan() {
    cin >> n >> s;
    if ((long long) n * (n + 1) / 2 < s) {
        cout << "No\n";
        return;
    }
    if (2 * n - 1 > s) {
        cout << "No\n";
        return;
    }
    int lo = 1, hi = n - 1;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!check(mi, s)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    int mi = lo + hi >> 1;
    check(mi, s);
    cout << "Yes\n";
    FOR(i, 1, n) cout << p[i] + 1 << " \n"[i == n];
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