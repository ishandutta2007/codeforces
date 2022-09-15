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
#define chkpt cerr << "-----\n";

const int maxn = 2e5 + 5;
const int magic = 320;
int n, k, q;
int a[maxn];
int f[magic][maxn];
int g[magic][magic];
int num[maxn];

void solve() {
    cin >> n >> k;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) {
        num[a[i]]++;
        if ((i + 1) % magic == 0) {
            int j = i / magic;
            FOR(l, 0, maxn >> 1) f[j][l] = num[l];
        }
    }
    FOR(i, 0, magic) {
        fill_n(num, maxn >> 1, 0);
        int st = i * magic;
        int tot = 0;
        FOR(j, st, magic * magic) {
            if (j < n && num[a[j]] < k) {
                num[a[j]]++;
                tot++;
            }
            if ((j + 1) % magic == 0) {
                int l = j / magic;
                g[i][l] = tot;
            }
        }
    }
    fill_n(num, maxn >> 1, 0);
    int lstans = 0;
    cin >> q;
    while (q--) {
        static int* his[maxn];
        int nhis = 0;
        int l, r; cin >> l >> r;
        l = (l + lstans) % n;
        r = (r + lstans) % n;
        if (l > r) swap(l, r);
        if (r - l + 1 <= magic) {
            lstans = 0;
            FOR(i, l, r + 1) {
                int d = a[i];
                if (num[d] < k) {
                    lstans++;
                    num[d]++;
                    his[nhis++] = &num[d];
                }
            }
            FOR(i, 0, nhis) (*his[i])--;
            cout << lstans << "\n";
            continue;
        }
        int u = l / magic;
        int v = r / magic;
        lstans = g[u + 1][v - 1];
        if (u != v - 1) {
            FOR(i, l, min(r + 1, (u + 1) * magic)) {
                int d = a[i];
                if (f[v - 1][d] - f[u][d] < k) {
                    lstans++;
                    f[v - 1][d]++;
                    his[nhis++] = &f[v - 1][d];
                }
            }
            if (u < v) {
                FOR(i, max(l, v * magic), r + 1) {
                    int d = a[i];
                    if (f[v - 1][d] - f[u][d] < k) {
                        lstans++;
                        f[v - 1][d]++;
                        his[nhis++] = &f[v - 1][d];
                    }
                }
            }
        }
        else {
            FOR(i, l, min(r + 1, (u + 1) * magic)) {
                int d = a[i];
                if (num[d] < k) {
                    lstans++;
                    num[d]++;
                    his[nhis++] = &num[d];
                }
            }
            if (u < v) {
                FOR(i, max(l, v * magic), r + 1) {
                    int d = a[i];
                    if (num[d] < k) {
                        lstans++;
                        num[d]++;
                        his[nhis++] = &num[d];
                    }
                }
            }
        }
        FOR(i, 0, nhis) (*his[i])--;
        cout << lstans << "\n";
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