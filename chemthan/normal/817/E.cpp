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

const int maxn = 1e5 + 5;
const int logn = 31;

int ptr;
int nxt[maxn * logn * 5][2];
int val[maxn * logn * 5];

void add(int k) {
    int st = 0;
    FORd(i, logn, 0) {
        int x = bit(k, i);
        if (!nxt[st][x]) nxt[st][x] = ++ptr;
        st = nxt[st][x];
        val[st]++;
    }
}

void rem(int k) {
    int st = 0;
    FORd(i, logn, 0) {
        int x = bit(k, i);
        if (!nxt[st][x]) nxt[st][x] = ++ptr;
        st = nxt[st][x];
        val[st]--;
    }
}

int query(int k, int l) {
    int res = 0, st = 0;
    FORd(i, logn, 0) {
        int x = bit(k, i);
        int y = bit(l, i);
        if (y) {
            if (nxt[st][x]) {
                res += val[nxt[st][x]];
            }
            if (nxt[st][!x]) {
                st = nxt[st][!x];
            }
            else {
                return res;
            }
        }
        else {
            if (nxt[st][x]) {
                st = nxt[st][x];
            }
            else {
                return res;
            }
        }
    }
    return res;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int p; cin >> p;
            add(p);
        }
        else if (op == 2) {
            int p; cin >> p;
            rem(p);
        }
        else {
            int p, l; cin >> p >> l;;
            cout << query(p, l) << "\n";
        }
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