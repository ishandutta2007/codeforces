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

const int maxn = 4e5 + 5;
int n;
long long c;
long long a[maxn];
int l[maxn];
long long dp[maxn];
long long sum[maxn];

long long st[maxn << 1];
void upd(int p, long long val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
long long query(int l, int r) {
    long long res = -LINF;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void solve() {
    fill_n(st, maxn << 1, -LINF);
    cin >> n >> c;
    FOR(i, 1, n + n) cin >> a[i];
    partial_sum(a, a + n + n, a);
    int ptr = 1;
    FOR(i, 1, n + 1) {
        while (ptr < i && a[i + i - 1] - a[ptr + ptr - 2] > c) ptr++;
        l[i] = ptr;
    }
    dp[1] = sum[1] = min(a[1], c);
    FOR(i, 0, 1 + 1) {
        upd(i, sum[i] - a[i + i]);
    }
    FOR(i, 2, n + 1) {
        dp[i] = (a[i + i - 1] - sum[i - 1]) + query(l[i] - 1, i - 2);
        if (l[i] >= 2) {
            chkmax(dp[i], c - (sum[i - 1] - sum[l[i] - 2]));
        }
        chkmax(dp[i], min(a[i + i - 1] - a[i + i - 2], c));
        sum[i] = sum[i - 1] + dp[i];
        upd(i, sum[i] - a[i + i]);
    }
    cout << sum[n] << "\n";
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