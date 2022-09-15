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

const int maxn = 1e5 + 5;
int n;
long long a[maxn];
int cnt[maxn];
int tmp[maxn];

int check(int mi) {
    FOR(i, 0, 100) tmp[i] = cnt[i];
    vi li;
    FOR(i, 0, mi) {
        if (!tmp[0]) return 0;
        tmp[0]--;
        int ptr = 0;
        while (tmp[ptr + 1]) {
            tmp[ptr + 1]--;
            ptr++;
        }
        li.pb(ptr);
    }
    FOR(i, 0, sz(li)) {
        int ptr = li[i];
        FORd(j, ptr + 2, 0) {
            if (tmp[j]) {
                tmp[j]--;
                break;
            }
        }
    }
    FOR(i, 0, 100) if (tmp[i]) return 0;
    return 1;
}

void solve() {
    cin >> n;
    vector<long long> v;
    FOR(i, 0, n) {
        cin >> a[i];
        int k = __lg(a[i]);
        if (a[i] == (1LL << k)) {
            cnt[k]++;
        }
        else {
            v.pb(a[i]);
        }
    }
    vi li;
    FOR(i, 0, sz(v)) {
        long long x = v[i];
        if (!cnt[0]) {
            cout << -1 << "\n";
            return;
        }
        cnt[0]--;
        int st = 0;
        while ((1LL << st + 1) < x) {
            if (!cnt[st + 1]) {
                cout << -1 << "\n";
                return;
            }
            cnt[st + 1]--;
            st++;
        }
        li.pb(st);
    }
    FOR(i, 0, sz(li)) {
        int ptr = li[i];
        while (cnt[ptr + 1]) {
            cnt[ptr + 1]--;
            ptr++;
        }
    }
    int lo = 0, hi = cnt[0] + 1;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!check(mi)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    if (lo == cnt[0] + 1) {
        cout << -1 << "\n";
        return;
    }
    vi res;
    FOR(i, lo, cnt[0] + 1) {
        res.pb(i);
    }
    FOR(i, 0, sz(res)) cout << res[i] + sz(v) << " \n"[i == sz(res) - 1];
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