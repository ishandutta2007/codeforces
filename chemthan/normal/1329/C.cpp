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
const ld EPS = 1e-6;
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
    int test; cin >> test;
    while (test--) {
        int h, g; cin >> h >> g;
        vi a(1 << h);
        FOR(i, 1, 1 << h) cin >> a[i];
        vi size(1 << h, 0);
        vi size2(1 << h, 0);
        FORd(i, 1 << h, 1) {
            size[i] = 1;
            if (2 * i + 1 < (1 << h)) {
                size[i] = 1 + size[i * 2] + size[i * 2 + 1];
            }
        }
        FORd(i, 1 << g, 1) {
            size2[i] = 1;
            if (2 * i + 1 < (1 << g)) {
                size2[i] = 1 + size2[i * 2] + size2[i * 2 + 1];
            }
        }
        int d = (1 << h) - (1 << g);
        vii changes;
        function<int(int)> ff = [&] (int k) {
            if (k * 2 + 1 < (1 << h)) {
                if (a[k * 2] + a[k * 2 + 1] == 0) {
                    return k;
                }
                if (a[k * 2] < a[k * 2 + 1]) {
                    swap(a[k], a[k * 2 + 1]);
                    changes.pb({k, k * 2 + 1});
                    return ff(k * 2 + 1);
                }
                else {
                    swap(a[k], a[k * 2]);
                    changes.pb({k, k * 2});
                    return ff(k * 2);
                }
            }
            return k;
        };
        long long res = accumulate(all(a), 0LL);
        priority_queue<pi> heap;
        heap.push({a[1], 1});
        vi vres;
        FOR(i, 0, d) {
            changes.clear();
            int u = heap.top().se;
            heap.pop();
            int v = ff(u);
            int found = 0;
            for (int t = v; u <= t; t >>= 1) {
                size[t]--;
                if (size[t] < size2[t]) {
                    found = 1;
                }
            }
            while (sz(changes)) {
                int u = changes.back().fi;
                int v = changes.back().se;
                changes.pop_back();
                swap(a[u], a[v]);
            }
            if (!found) {
                res -= a[u];
                ff(u);
                a[v] = 0;
                heap.push({a[u], u});
                vres.pb(u);
            }
            else {
                for (int t = v; u <= t; t >>= 1) {
                    size[t]++;
                }
                i--;
                if (u * 2 < (1 << h)) {
                    heap.push({a[u * 2], u * 2});
                    heap.push({a[u * 2 + 1], u * 2 + 1});
                }
            }
        }
        cout << res << "\n";
        FOR(i, 0, sz(vres)) cout << vres[i] << " \n"[i == sz(vres) - 1];
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