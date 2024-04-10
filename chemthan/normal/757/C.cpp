#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>

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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return (int) fpow(a, p - 2, p);}

const int maxm = 1000000 + 10;
int n, m;
long long hs[maxm];
int hs2[maxm];
int cnt[maxm];
long long base[maxm];
int base2[maxm];
int fac[maxm];

int ispr(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    srand(time(NULL));
    int pr = abs(rand() * rand()) % (INF / 2) + INF / 2;
    while (!ispr(pr)) pr++;
    base[0] = base2[0] = 1;
    FOR(i, 1, maxm) {
        base[i] = base[i - 1] * 2311;
        base2[i] = mult(base2[i - 1], 1992, pr);
    }
    fac[0] = 1; FOR(i, 1, maxm) fac[i] = mult(fac[i - 1], i);
    scanf("%d%d", &n, &m);
    FOR(i, 0, n) {
        int k; scanf("%d", &k);
        vi his;
        FOR(j, 0, k) {
            int x; scanf("%d", &x); x--;
            if (!(cnt[x]++)) {
                his.pb(x);
            }
        }
        FOR(j, 0, sz(his)) {
            int x = his[j];
            hs[x] += base[i] * cnt[x];
            addmod(hs2[x], mult(base2[i], cnt[x], pr), pr);
            cnt[x] = 0;
        }
    }
    map<pair<long long, int>, int> hss;
    FOR(i, 0, m) {
        hss[mp(hs[i], hs2[i])]++;
    }
    int ans = 1;
    FORall(it, hss) {
        ans = mult(ans, fac[it->se]);
    }
    printf("%d\n", ans);
}

int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    solve();
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}