#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 5e4 + 5;
const int maxk = 10 + 5;
int n, k;
int a[maxn][maxk];

int fen[2][maxk][maxn];
void upd(int fen[], int p, int val) {
    for (; p < maxn; p += p & -p) {
        chkmax(fen[p], val);
    }
}
int query(int fen[], int p) {
    int res = 0;
    for (; p > 0; p -= p & -p) {
        chkmax(res, fen[p]);
    }
    return res;
}

int dj[maxn];
int size[maxn];
int f[maxn];
int g[maxn];
void init() {
    FOR(i, 1, n + 1) dj[i] = i, size[i] = 1, f[i] = g[i] = i;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        size[q] += size[p];
        chkmin(f[q], f[p]);
        chkmax(g[q], g[p]);
    }
}

void solve() {
    cin >> n >> k;
    static vi dc[maxk];
    FOR(i, 0, n) FOR(j, 0, k) {
        cin >> a[i][j];
        dc[j].pb(a[i][j]);
    }
    FOR(i, 0, k) {
        sort(all(dc[i])), uni(dc[i]);
    }
    FOR(i, 0, n) FOR(j, 0, k) {
        a[i][j] = lower_bound(all(dc[j]), a[i][j]) - dc[j].begin() + 1;
    }
    init();
    set<int> st, heap;
    FOR(i, 0, n) {
        st.insert(a[i][0]);
        heap.insert(a[i][0]);
        FOR(j, 1, k) {
            int mx = query(fen[0][j], a[i][j]);
            if (a[i][0] < mx) {
                vi vals;
                set<int>::iterator it = st.lower_bound(a[i][0]);
                while (it != st.end() && *it <= mx) {
                    vals.pb(*it);
                    it++;
                }
                FOR(l, 0, sz(vals)) {
                    st.erase(vals[l]);
                    join(mx, vals[l]);
                }
            }
            int mn = n + 1 - query(fen[1][j], n + 1 - a[i][j]);
            if (mn < a[i][0]) {
                vi vals;
                set<int>::iterator it = st.lower_bound(mn);
                while (it != st.end() && *it <= a[i][0]) {
                    vals.pb(*it);
                    it++;
                }
                FOR(l, 0, sz(vals)) {
                    st.erase(vals[l]);
                    join(mn, vals[l]);
                }
            }
            int z = find(a[i][0]);
            st.insert(f[z]);
            st.insert(g[z]);
            upd(fen[0][j], a[i][j], a[i][0]);
            upd(fen[1][j], n + 1 - a[i][j], n + 1 - a[i][0]);
        }
        int k = find(*heap.rbegin());
        cout << size[k] << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}