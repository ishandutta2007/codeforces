#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 5e3 + 5;
int n, m;
string express[maxn];
int a[maxn];
int id1[maxn];
int id2[maxn];
int id3[maxn];
int type[maxn];
string tt[maxn];
string s1[maxn];
string op[maxn];
string s2[maxn];
map<string, int> hs;

inline int query(string s) {
    if (hs.count(s)) return hs[s];
    int res = sz(hs);
    return hs[s] = res;
}

void solve() {
    cin >> n >> m;
    cin.ignore();
    FOR(i, 0, n) {
        string s;
        getline(cin, s);
        FOR(i, 0, sz(s)) {
            if (s[i] == ':' || s[i] == '=') {
                s[i] = ' ';
            }
        }
        express[i] = s;
    }
    string ansmn, ansmx;
    FOR(k, 0, m) {
        pi mn = mp(+INF, +INF), mx = mp(-INF, -INF);
        FOR(x, 0, 2) {
            int tot = 0;
            FOR(i, 0, n) {
                if (!k) {
                    stringstream ss(express[i]);
                    string tmp; ss >> tmp;
                    int lhs = (id1[i] = query(tmp));
                    vector<string> vs;
                    while (ss >> tmp) {
                        vs.pb(tmp);
                    }
                    if (sz(vs) == 1) {
                        a[lhs] = vs[0][k] - '0';
                        tt[i] = vs[0];
                        tot += a[lhs];
                    }
                    else {
                        type[i] = 1;
                        s1[i] = vs[0];
                        op[i] = vs[1];
                        s2[i] = vs[2];
                        int u = s1[i] == "?" ? x : a[(id2[i] = query(s1[i]))];
                        int v = s2[i] == "?" ? x : a[(id3[i] = query(s2[i]))];
                        int res = 0;
                        if (op[i]  == "AND") {
                            res = u & v;
                        }
                        else if (op[i]  == "XOR") {
                            res = u ^ v;
                        }
                        else if (op[i]  == "OR") {
                            res = u | v;
                        }
                        a[lhs] = res;
                        tot += a[lhs];
                    }
                }
                else {
                    int lhs = id1[i];
                    if (!type[i]) {
                        a[lhs] = tt[i][k] - '0';
                        tot += a[lhs];
                    }
                    else {
                        int u = s1[i] == "?" ? x : a[id2[i]];
                        int v = s2[i] == "?" ? x : a[id3[i]];
                        int res = 0;
                        if (op[i]  == "AND") {
                            res = u & v;
                        }
                        else if (op[i]  == "XOR") {
                            res = u ^ v;
                        }
                        else if (op[i]  == "OR") {
                            res = u | v;
                        }
                        a[lhs] = res;
                        tot += a[lhs];
                    }
                }
            }
            chkmin(mn, mp(tot, x));
            chkmax(mx, mp(tot, -x));
        }
        ansmn += '0' + mn.se;
        ansmx += '0' - mx.se;
    }
    cout << ansmn << "\n";
    cout << ansmx << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}