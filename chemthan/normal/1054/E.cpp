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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

const int maxn = 300 + 5;
int n, m;
string a[maxn][maxn];
string b[maxn][maxn];

vector<pair<pi, pi> > ff() {
    static queue<char> c[maxn][maxn];
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            while (sz(c[i][j])) c[i][j].pop();
            string t = a[i][j];
            reverse(all(t));
            for (char e : t) {
                c[i][j].push(e);
            }
        }
    }
    vector<pair<pi, pi> > moves;
    int p = sz(c[0][0]);
    int q = sz(c[0][m - 1]);
    FOR(i, 0, p) {
        char e = c[0][0].front();
        c[0][0].pop();
        if (e == '0') {
            c[n - 1][0].push(e);
            moves.pb(mp(mp(0, 0), mp(n - 1, 0)));
        }
        else {
            c[0][m - 1].push(e);
            moves.pb(mp(mp(0, 0), mp(0, m - 1)));
        }
    }
    FOR(i, 0, q) {
        char e = c[0][m - 1].front();
        c[0][m - 1].pop();
        if (e == '1') {
            c[n - 1][m - 1].push(e);
            moves.pb(mp(mp(0, m - 1), mp(n - 1, m - 1)));
        }
        else {
            c[0][0].push(e);
            moves.pb(mp(mp(0, m - 1), mp(0, 0)));
        }
    }
    FOR(i, 1, n) {
        int p = sz(c[i][0]);
        int q = sz(c[i][m - 1]);
        FOR(j, 0, p) {
            char e = c[i][0].front();
            c[i][0].pop();
            if (e == '0') {
                c[0][0].push(e);
                moves.pb(mp(mp(i, 0), mp(0, 0)));
            }
            else {
                c[i][m - 1].push(e);
                moves.pb(mp(mp(i, 0), mp(i, m - 1)));
            }
        }
        FOR(j, 0, q) {
            char e = c[i][m - 1].front();
            c[i][m - 1].pop();
            if (e == '1') {
                c[0][m - 1].push(e);
                moves.pb(mp(mp(i, m - 1), mp(0, m - 1)));
            }
            else {
                c[i][0].push(e);
                moves.pb(mp(mp(i, m - 1), mp(i, 0)));
            }
        }
    }
    FOR(i, 0, n) FOR(j, 0, m) {
        if (mp(i, j) != mp(0, 0) && mp(i, j) != mp(0, m - 1)) {
            while (sz(c[i][j])) {
                char e = c[i][j].front();
                c[i][j].pop();
                if (e == '0') {
                    if (!i || !j) {
                        moves.pb(mp(mp(i, j), mp(0, 0)));
                    }
                    else {
                        moves.pb(mp(mp(i, j), mp(i, 0)));
                        moves.pb(mp(mp(i, 0), mp(0, 0)));
                    }
                }
                else {
                    if (!i || j == m - 1) {
                        moves.pb(mp(mp(i, j), mp(0, m - 1)));
                    }
                    else {
                        moves.pb(mp(mp(i, j), mp(i, m - 1)));
                        moves.pb(mp(mp(i, m - 1), mp(0, m - 1)));
                    }
                }
            }
        }
    }
    return moves;
}

void chemthan() {
    deque<int> dq;
    cin >> n >> m;
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    vector<pair<pi, pi> > res = ff();
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j], reverse(all(a[i][j]));
    vector<pair<pi, pi> > res2 = ff();
    cout << sz(res) + sz(res2) << "\n";
    for (auto it : res) {
        cout << it.fi.fi + 1 << " " << it.fi.se + 1 << " " << it.se.fi + 1 << " " << it.se.se + 1 << "\n";
    }
    reverse(all(res2));
    for (auto it : res2) {
        cout << it.se.fi + 1 << " " << it.se.se + 1 << " " << it.fi.fi + 1 << " " << it.fi.se + 1 << "\n";
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