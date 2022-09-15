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
const int MOD2 = 1007681537;
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

long long dp[100][11][2][1 << 10];

long long calc(int k, int b, int fa, int msk) {
    if (!k) return msk == 0 && fa;
    long long& res = dp[k][b][fa][msk];
    if (~res) return res;
    res = 0;
    FOR(i, 0, b) {
        int nfa = fa | (i > 0);
        if (nfa) {
            res += calc(k - 1, b, nfa, msk ^ (1 << i));
        }
        else {
            res += calc(k - 1, b, nfa, msk);
        }
    }
    return res;
}
int tot;
inline int getmsk(long long x, int b) {
    tot++;
    int res = 0;
    while (x) {
        res ^= 1 << (x % b);
        x /= b;
    }
    return res;
}

long long calc(int b, long long l) {
    if (!l) return 0;
    vi vals;
    while (l) {
        vals.pb(l % b);
        l /= b;
    }
    reverse(all(vals));
    long long res = 0;
    long long cur = 0;
    int msk = 0;
    FOR(i, 0, sz(vals)) {
        FOR(j, 0, vals[i]) {
            long long ncur = cur * b + j;
            res += calc(sz(vals) - i - 1, b, ncur > 0, ncur ? (msk ^ (1 << j)) : msk);
        }
        msk ^= 1 << vals[i];
        cur = cur * b + vals[i];
    }
    if (!getmsk(cur, b)) res++;
    return res;
}

void solve() {
    ms(dp, -1);
    int q; cin >> q;
    while (q--) {
        int b; long long l, r; cin >> b >> l >> r;
        cout << calc(b, r) - calc(b, l - 1) << "\n";
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