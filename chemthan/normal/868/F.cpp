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
const ld EPS = 1e-12;
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

const long long oo = (long long) 1e18;
const int MAXN = 20 + 5;
const int MAXM = 1e5 + 5;
int n, k;
int a[MAXM];
long long f[MAXN][MAXM];
int cnt[MAXM];
long long cost;
int u, v;

void add(int u) {
    cost += 2 * cnt[u] + 1;
    cnt[u]++;
}
void rem(int u) {
    cnt[u]--;
    cost -= 2 * cnt[u] + 1;
}
long long query(int l, int r) {
    while (u < l) rem(a[u++]);
    while (u > l) add(a[--u]);
    while (v < r) add(a[++v]);
    while (v > r) rem(a[v--]);
    return cost;
}

void divide(int i, int L, int R, int optL, int optR) {
    if (L > R) return;
    int M = L + R >> 1, ptr = optL;
    f[i][M] = oo;
    FOR(k, max(M, optL), optR + 1) {
        if (chkmin(f[i][M], query(M, k) + f[i - 1][k + 1])) {
            ptr = k;
        }
    }
    divide(i, L, M - 1, optL, ptr);
    divide(i, M + 1, R, ptr, optR);
}

void solve() {
    cin >> n >> k;
    FOR(i, 0, n) {
        cin >> a[i];
    }
    FOR(i, 0, n) f[0][i] = oo;
    FOR(i, 1, k + 1) {
        cost = 0, u = 0, v = -1;
        fill_n(cnt, MAXM, 0);
        divide(i, 0, n - 1, 0, n - 1);
    }
    cout << (f[k][0] - n) / 2 << "\n";
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