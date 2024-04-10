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
const int MOD2 = (int) 1e8 + 7;
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

const int maxn = 1e6 + 5;
int n;
int op[maxn];
long long l[maxn];
long long r[maxn];

int st[maxn << 2];
int lz1[maxn << 2];
int lz2[maxn << 2];

void pushdown(int p, int L, int R) {
    if (lz1[p]) {
        st[p] = (R - L + 1) - st[p];
        if (L < R) {
            if (~lz2[p << 1]) {
                lz1[p << 1] = 0;
                lz2[p << 1] ^= 1;
            }
            else {
                lz1[p << 1] ^= 1;
            }
            if (~lz2[p << 1 | 1]) {
                lz1[p << 1 | 1] = 0;
                lz2[p << 1 | 1] ^= 1;
            }
            else {
                lz1[p << 1 | 1] ^= 1;
            }
        }
        lz1[p] = 0;
    }
    if (~lz2[p]) {
        st[p] = lz2[p] * (R - L + 1);
        if (L < R) {
            lz2[p << 1] = lz2[p];
            lz1[p << 1] = 0;
            lz2[p << 1 | 1] = lz2[p];
            lz1[p << 1 | 1] = 0;
        }
        lz2[p] = -1;
    }
}

void upd1(int p, int l, int r, int L, int R) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        lz1[p] = 1;
        pushdown(p, L, R);
        return;
    }
    upd1(p << 1, l, r, L, L + R >> 1);
    upd1(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
    st[p] = st[p << 1] + st[p << 1 | 1];
}

void upd2(int p, int l, int r, int L, int R, int val) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        lz2[p] = val;
        pushdown(p, L, R);
        return;
    }
    upd2(p << 1, l, r, L, L + R >> 1, val);
    upd2(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1] + st[p << 1 | 1];
}

int query(int p, int L, int R) {
    pushdown(p, L, R);
    if (L == R) return L;
    pushdown(p << 1, L, L + R >> 1);
    pushdown(p << 1 | 1, (L + R >> 1) + 1, R);
    if (st[p << 1] < (L + R >> 1) - L + 1) return query(p << 1, L, L + R >> 1);
    return query(p << 1 | 1, (L + R >> 1) + 1, R);
}

void solve() {
    cin >> n;
    vector<long long> dc;
    FOR(i, 0, n) {
        cin >> op[i] >> l[i] >> r[i];
        FOR(k, -1, 1 + 1) {
            if (l[i] + k > 0) {
                dc.pb(l[i] + k);
            }
            if (r[i] + k > 0) {
                dc.pb(r[i] + k);
            }
        }
    }
    dc.pb(1);
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) {
        int x = lower_bound(all(dc), l[i]) - dc.begin();
        int y = lower_bound(all(dc), r[i]) - dc.begin();
        if (op[i] == 1) {
            upd2(1, x, y, 0, sz(dc) - 1, 1);
        }
        else if (op[i] == 2) {
            upd2(1, x, y, 0, sz(dc) - 1, 0);
        }
        else if (op[i] == 3) {
            upd1(1, x, y, 0, sz(dc) - 1);
        }
        cout << dc[query(1, 0, sz(dc) - 1)] << "\n";
    }
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