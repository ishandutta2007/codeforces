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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int test; cin >> test;
    while (test--) {
        auto solve = [&] () {
            int n, m; cin >> n >> m;
            vector<string> a(n);
            vector<vi> row(26);
            vector<vi> col(26);
            FOR(i, 0, n) {
                cin >> a[i];
                FOR(j, 0, m) if (a[i][j] != '.') {
                    int c = a[i][j] - 'a';
                    row[c].pb(i);
                    col[c].pb(j);
                }
            }
            int total = 0;
            FOR(i, 0, 26) {
                sort(all(row[i])), uni(row[i]);
                sort(all(col[i])), uni(col[i]);
                if (sz(row[i])) {
                    total = i + 1;
                }
                if (1 < sz(row[i]) && 1 < sz(col[i])) {
                    cout << "NO\n";
                    return;
                }
                if (sz(row[i]) == 1) {
                    int l = *min_element(all(col[i]));
                    int r = *max_element(all(col[i]));
                    FOR(j, l, r + 1) {
                        if (a[row[i][0]][j] - 'a' < i || a[row[i][0]][j] == '.') {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
                if (sz(col[i]) == 1) {
                    int l = *min_element(all(row[i]));
                    int r = *max_element(all(row[i]));
                    FOR(j, l, r + 1) {
                        if (a[j][col[i][0]] - 'a' < i || a[j][col[i][0]] == '.') {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
            cout << "YES\n";
            cout << total << "\n";
            FOR(i, 0, 26) {
                if (sz(row[i])) {
                    if (sz(row[i]) == 1) {
                        int l = *min_element(all(col[i]));
                        int r = *max_element(all(col[i]));
                        cout << row[i][0] + 1 << " " << l + 1 << " " << row[i][0] + 1 << " " << r + 1 << "\n";
                    }
                    else {
                        int l = *min_element(all(row[i]));
                        int r = *max_element(all(row[i]));
                        cout << l + 1 << " " << col[i][0] + 1 << " " << r + 1 << " " << col[i][0] + 1 << "\n";
                    }
                }
                else if (i < total) {
                    cout << row[total - 1][0] + 1 << " " << col[total - 1][0] + 1 << " ";
                    cout << row[total - 1][0] + 1 << " " << col[total - 1][0] + 1 << "\n";
                }
            }
        };
        solve();
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