#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
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

const int MAXN = 200000 + 10;
const int LOGN = 20;
int tr[LOGN + 1][MAXN];
long long sm[LOGN + 1][MAXN];
void insert(int x, int t) {
    for (int i = 0; i < LOGN; i++) {
        tr[i][x]++;
        sm[i][x] += t;
        x >>= 1;
    }
}
void erase(int x, int t) {
    for (int i = 0; i < LOGN; i++) {
        tr[i][x]--;
        sm[i][x] -= t;
        x >>= 1;
    }
}
int kthelm(int k) {
    int res = 0;
    int a = 0, b = LOGN;
    while (b--) {
        a <<= 1;
        k -= tr[b][a] < k ? tr[b][a++] : 0;
        res = sm[b][a] / tr[b][a];
    }
    return res;
}
long long kthsum(int k) {
    long long res = 0;
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

const int maxn = 200000 + 10;
int n, q;
int a[maxn];
map<int, int> dc;
vector<pair<int, pair<long long, int> > > que;

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i], dc[a[i]];
    FOR(i, 0, q) {
        int op; cin >> op;
        if (op == 1) {
            int u, v; cin >> u >> v; u--;
            que.pb(mp(op, mp(u, v)));
            dc[v];
        }
        else {
            long long v; cin >> v;
            que.pb(mp(op, mp(v, 0)));
        }
    }
    int cnt = 0; FORall(it, dc) it->se = cnt++;
    FOR(i, 0, n) {
        insert(dc[a[i]], a[i]);
    }
    FOR(i, 0, q) {
        int op = que[i].fi;
        if (op == 1) {
            int u = que[i].se.fi;
            int v = que[i].se.se;
            erase(dc[a[u]], a[u]);
            a[u] = v;
            insert(dc[a[u]], a[u]);
        }
        else {
            long long v = que[i].se.fi;
            int l = 2, r = n + 1;
            while (l < r) {
                int m = (l + r) >> 1;
                if ((long long) m * kthelm(m) - kthsum(m) < v) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
                
            }
            long long tot = (long long) (l - 1) * kthelm(l - 1) - kthsum(l - 1);
            cout << prec(9) << (long double) (v - tot) / (l - 1) + kthelm(l - 1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    solve();
    cerr << "\n" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}