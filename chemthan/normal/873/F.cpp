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

struct SuffixArray {
    static const int maxn = 2e5 + 5;
    static const char SEP = '$';
    
    int n;
    char s[maxn];
    int sa[maxn], ra[2][maxn];
    int lcp[maxn];
    
    void build(char* t) {
        strcpy(s, t), n = strlen(s);
        for (int i = 0; i < n; i++) {
            sa[i] = i, ra[0][i] = 0, ra[1][i] = s[i] + 1;
        }
        for (int d = 1; radixsort(); d <<= 1) {
            for (int i = 0; i < n; i++) {
                if (i + d < n) {
                    ra[1][i] = ra[0][i + d] + 1;
                }
                else {
                    ra[1][i] = 0;
                }
            }
        }
        buildlcp();
    }
    
    int radixsort() {
        static int p[maxn];
        static int tmpsa[maxn];
        static int tmpra[maxn];
        int mx = max(256, n) + 1;
        for (int step = 1; step >= 0; step--) {
            fill_n(p, mx, 0);
            for (int i = 0; i < n; i++) {
                p[ra[step][i] + 1]++;
                tmpsa[i] = sa[i];
            }
            partial_sum(p, p + mx, p);
            for (int i = 0; i < n; i++) {
                sa[p[ra[step][tmpsa[i]]]++] = tmpsa[i];
            }
        }
        int ptr = 0;
        tmpra[sa[0]] = ptr;
        for (int i = 1; i < n; i++) {
            int u = sa[i - 1];
            int v = sa[i];
            if (ra[0][u] < ra[0][v] || ra[1][u] < ra[1][v]) {
                ptr++;
            }
            tmpra[v] = ptr;
        }
        for (int i = 0; i < n; i++) ra[0][i] = tmpra[i];
        return ptr < n - 1;
    }
    
    void buildlcp() {
        for (int i = 0, k = 0; i < n; i++) {
            if (!ra[0][i]) lcp[ra[0][i]] = 0;
            else {
                for (int j = sa[ra[0][i] - 1]; s[i + k] == s[j + k] && s[i + k] != SEP; k++);
                lcp[ra[0][i]] = k;
                k = max(k - 1, 0);
            }
        }
    }
} sa;

const int maxn = 2e5 + 5;
int n;
string s, t;
int a[maxn];
int f[maxn];
int l[maxn];
int r[maxn];

void solve() {
    cin >> n >> s >> t;
    reverse(all(s)), reverse(all(t));
    sa.build((char*) s.data());
    FOR(i, 0, n) {
        int j = sa.ra[0][i];
        f[j] = 1 - (t[i] - '0');
        a[i] = sa.lcp[i];
    }
    partial_sum(f, f + n, f);
    FOR(i, 0, n) l[i] = r[i] = i;
    FOR(i, 1, n) {
        int ptr = i;
        while (ptr > 0 && a[i] <= a[ptr - 1]) ptr = l[ptr - 1];
        l[i] = ptr;
    }
    FORd(i, n - 1, 0) {
        int ptr = i;
        while (ptr < n - 1 && a[i] <= a[ptr + 1]) ptr = r[ptr + 1];
        r[i] = ptr;
    }
    long long ans = 0;
    FOR(i, 1, n) {
        int cnt = f[r[i]] - (l[i] > 1 ? f[l[i] - 2] : 0);
        chkmax(ans, (long long) cnt * a[i]);
    }
    FOR(i, 0, n) if (t[i] != '1') {
        chkmax(ans, (long long) n - i);
    }
    cout << ans << "\n";
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