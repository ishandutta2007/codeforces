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

const int maxn = 1000 + 5;
int n;
int d[maxn];

int fen[2][maxn];
void upd(int fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query(int fen[], int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

int check(vi degs) {
    ms(fen, 0);
    sort(all(degs), greater<int>());
    int n = sz(degs);
    int tot = accumulate(all(degs), 0);
    FORd(i, n, 0) {
        int k = i + 1;
        int x = (n - i - 1) - query(fen[0], k);
        int y = query(fen[1], k);
        int sum = k * (k - 1) + x * k + y;
        if (tot > sum) {
            return 0;
        }
        upd(fen[0], degs[i], 1);
        upd(fen[1], degs[i], degs[i]);
        tot -= degs[i];
    }
    return 1;
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> d[i];
    int nn = d[n - 1] + 1;
    vi degs;
    int found = 0;
    FOR(ii, 0, n) if (!found) {
        degs.clear();
        FOR(i, 0, n) degs.pb(d[i]);
        FOR(i, n, nn - 1) {
            degs.pb(d[ii]);
        }
        int sum = accumulate(all(degs), 0);
        FOR(i, 0, n) if (!(sum + d[i] & 1)) {
            degs.pb(d[i]);
            if (check(degs)) {
                found = 1;
                break;
            }
            degs.pop_back();
        }
    }
    assert(found);
    n = nn;
    vii edges;
    multiset<pi> st;
    FOR(i, 0, n) st.insert(mp(-degs[i], i));
    while (sz(st)) {
        auto it = *st.begin();
        st.erase(it);
        int u = it.se;
        int k = -it.fi;
        vii rems;
        for (auto it2 : st) {
            rems.pb(it2);
            k--;
            if (!k) break;
        }
        for (auto it2 : rems) {
            int v = it2.se;
            int l = -it2.fi;
            st.erase(it2);
            edges.pb(mp(u, v));
            if (--l) {
                st.insert(mp(-l, v));
            }
        }
    }
    cout << sz(edges) << "\n";
    for (auto it : edges) {
        cout << it.fi + 1 << " " << it.se + 1 << "\n";
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