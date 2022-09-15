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

const int maxn = 1e6 + 5;
int phi[maxn];
long long f[maxn];

void build() {
    for (int i = 0; i < maxn; i++) phi[i] = i;
    for (int i = 1; i < maxn; i++) for (int j = 2 * i; j < maxn; j += i) phi[j] -= phi[i];
    f[0] = 0; for (int i = 1; i < maxn; i++) f[i] = f[i - 1] + phi[i];
}

long long calc(int n) {
    if (n < maxn) return f[n];
    long long res = (long long) n * (n + 1) / 2;
    int d = 2;
    for (; d * d <= n; d++) res -= calc(n / d);
    int k = n / d;
    for(; k; k--) {
        int lo = n / (k + 1) + 1;
        int hi = n / k;
        res -= (hi - lo + 1) * f[k];
    }
    return res;
}

void solve() {
    static int sp[maxn * 10];
    FOR(i, 1, maxn * 10) sp[i] = i;
    FOR(i, 2, maxn * 10) if (sp[i] == i) {
        for (int j = i + i; j < maxn * 10; j += i) {
            chkmin(sp[j], i);
        }
    }
    build();
    int n; cin >> n;
    long long a = calc(n) - 1;
    static long long cnt[maxn * 10];
    FOR(i, 2, n + 1) {
        cnt[sp[i]]++;
    }
    partial_sum(cnt, cnt + maxn * 10, cnt);
    long long b = 0;
    FOR(i, 2, n + 1) if (sp[i] == i) {
        int k = max(i, n / i) + 1;
        b += (cnt[maxn * 10 - 1] - cnt[k - 1]) * (cnt[i] - cnt[i - 1]);
    }
    long long c = 0;
    FOR(i, 2, n + 1) if (sp[i] == i) {
        if (i + i > n) {
            c++;
        }
    }
    long long x = (long long) n * (n - 1) / 2 - a;
    long long y = a - n + 1;
    long long z = c * (n - c - 1) + c * (c - 1) / 2;
    cout << x + 2 * (y - b) + 3 * (b - z) << "\n";
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