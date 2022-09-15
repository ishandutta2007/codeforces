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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

template<class TE, class TS> struct KthTree {
    static const int MAXN = 3e5 + 5;
    static const int LOGN = 20;
    long long tr[LOGN + 1][MAXN];
    TS sm[LOGN + 1][MAXN];
    int cnt;
    void insert(int x, TE t) {
        cnt++;
        for (int i = 0; i < LOGN; i++) {
            tr[i][x]++;
            sm[i][x] += t;
            x >>= 1;
        }
    }
    void erase(int x, TE t) {
        cnt--;
        for (int i = 0; i < LOGN; i++) {
            tr[i][x]--;
            sm[i][x] -= t;
            x >>= 1;
        }
    }
    TE kthelm(int k) {
        TE res = 0;
        int a = 0, b = LOGN;
        while (b--) {
            a <<= 1;
            k -= tr[b][a] < k ? tr[b][a++] : 0;
            res = sm[b][a] / tr[b][a];
        }
        return res;
    }
    TS kthsum(int k) {
        TS res = 0;
        int a = 0, b = LOGN;
        while (b--) {
            a <<= 1;
            if (tr[b][a] < k) {
                res += sm[b][a];
            }
            k -= tr[b][a] < k ? tr[b][a++] : 0;
            if (!b) res += sm[b][a] / tr[b][a] * k;
        }
        return res;
    }
};
KthTree<long long, long long> ktree;

const int maxn = 3e5 + 5;
int n, m, k;
int c[maxn];
int f[maxn];
int g[maxn];
vi v[4];

void solve() {
    cin >> n >> m >> k;
    FOR(i, 0, n) cin >> c[i];
    int x; cin >> x;
    FOR(i, 0, x) {
        int y; cin >> y; y--;
        f[y] = 1;
    }
    cin >> x;
    FOR(i, 0, x) {
        int y; cin >> y; y--;
        g[y] = 1;
    }
    vi dc;
    FOR(i, 0, n) {
        v[f[i] + 2 * g[i]].pb(c[i]);
        dc.pb(c[i]);
    }
    sort(all(dc)), uni(dc);
    FOR(i, 0, 4) {
        sort(all(v[i]));
        if (i == 0 || i == 3) {
            FOR(j, 0, sz(v[i])) {
                int ix = lower_bound(all(dc), v[i][j]) - dc.begin() + 1;
                ktree.insert(ix, v[i][j]);
            }
        }
    }
    long long ans = LINF, tot = 0;
    FOR(i, 1, 3) {
        FOR(j, 0, sz(v[i])) {
            tot += v[i][j];
        }
    }
    int mn = max(0, 2 * k - m);
    int ptr = 0, ptr1 = sz(v[1]) - 1, ptr2 = sz(v[2]) - 1;
    FOR(i, mn, sz(v[3]) + 1) {
        while (ptr < i) {
            int ix = lower_bound(all(dc), v[3][ptr]) - dc.begin() + 1;
            ktree.erase(ix, v[3][ptr]);
            tot += v[3][ptr];
            ptr++;
        }
        int t = max(0, k - i);
        while (ptr1 + 1 > t) {
            int ix = lower_bound(all(dc), v[1][ptr1]) - dc.begin() + 1;
            ktree.insert(ix, v[1][ptr1]);
            tot -= v[1][ptr1];
            ptr1--;
        }
        while (ptr2 + 1 > t) {
            int ix = lower_bound(all(dc), v[2][ptr2]) - dc.begin() + 1;
            ktree.insert(ix, v[2][ptr2]);
            tot -= v[2][ptr2];
            ptr2--;
        }
        if (ptr1 + 1 >= t && ptr2 + 1 >= t) {
            int rm = m - i - t - t;
            if (rm > 0 && ktree.cnt >= rm) {
                chkmin(ans, tot + ktree.kthsum(rm));
            }
            else if (!rm) {
                chkmin(ans, tot);
            }
        }
    }
    if (ans == LINF) ans = -1;
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}