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
    auto move = [&] (vector<vi> a, int t) {
        int n = sz(a);
        priority_queue<tuple<int, int, int>>heap;
        FOR(i, 0, n) FOR(j, 0, n) {
            heap.push({-a[i][j], i, j});
        }
        FOR(i, 0, n) FOR(j, 0, n) {
            if (a[i][j] == 1) {
                int res = 0;
                a[i][j] = INF;
                int x = i, y = j;
                FOR(k, 0, n * n - 1) {
                    tuple<int, int, int> mn(INF, INF, INF);
                    FOR(z, 0, n) {
                        chkmin(mn, make_tuple(a[x][z], x, z));
                        chkmin(mn, make_tuple(a[z][y], z, y));
                    }
                    if (t) {
                        for (int i = 1; x + i < n && y + i < n; i++) {
                            chkmin(mn, make_tuple(a[x + i][y + i], x + i, y + i));
                        }
                        for (int i = 1; 0 <= x - i && 0 <= y - i; i++) {
                            chkmin(mn, make_tuple(a[x - i][y - i], x - i, y - i));
                        }
                        for (int i = 1; x + i < n && 0 <= y - i; i++) {
                            chkmin(mn, make_tuple(a[x + i][y - i], x + i, y - i));
                        }
                        for (int i = 1; 0 <= x - i && y + i < n; i++) {
                            chkmin(mn, make_tuple(a[x - i][y + i], x - i, y + i));
                        }
                    }
                    if (get<0>(mn) < INF) {
                        x = get<1>(mn);
                        y = get<2>(mn);
                        a[x][y] = INF;
                    }
                    else {
                        while (sz(heap)) {
                            int u = get<1>(heap.top());
                            int v = get<2>(heap.top());
                            heap.pop();
                            if (a[u][v] < INF) {
                                x = u, y = v;
                                a[x][y] = INF;
                                res++;
                                break;
                            }
                        }
                    }
                }
                return res;
            }
        }
        return -1;
    };
    int n; cin >> n;
    if (n <= 2) {
        cout << -1 << "\n";
        return;
    }
    vector<vi> a(n, vi(n));
    vi v1, v2;
    FOR(i, 1, n * n + 1) {
        if (i & 1) {
            v1.pb(i);
        }
        else {
            v2.pb(i);
        }
    }
    vii order;
    FOR(i, 0, n) {
        if (!(i & 1)) {
            FOR(j, 0, n) {
                if (i < 3 && j < 3) {
                    continue;
                }
                order.pb({i, j});
            }
        }
        else {
            FORd(j, n, 0) {
                if (i < 3 && j < 3) {
                    continue;
                }
                order.pb({i, j});
            }
        }
    }
    /*
       4 5 8
       9 3 7
       1 6 2
     */
    a[0][0] = 4, a[0][1] = 5, a[0][2] = 8;
    a[1][0] = 9, a[1][1] = 3, a[1][2] = 7;
    a[2][0] = 1, a[2][1] = 6, a[2][2] = 2;
    FOR(i, 0, 3) FOR(j, 0, 3) a[i][j] += n * n - 9;
    FOR(i, 0, 3) swap(a[0][i], a[2][i]);
    int ptr = n * n - 9;
    FOR(i, 0, sz(order)) {
        int x = order[i].fi;
        int y = order[i].se;
        a[x][y] = ptr--;
    }
    //db(move(a, 0)) db(move(a, 1)) endln;
    FOR(i, 0, n) FOR(j, 0, n) cout << a[i][j] << " \n"[j == n - 1];
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