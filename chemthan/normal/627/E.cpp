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

const int maxn = 3000 + 5;
int r, c, n, k;
vi gx[maxn];
int nxt[maxn];
int prv[maxn];
vi li[maxn];
int val[maxn];

int rem(int x, int st, int ed) {
    static int vl[15], vr[15];
    fill_n(vl, 15, 0), fill_n(vr, 15, 0);
    int nvl = 0, nvr = 0;
    if (prv[x] == st) {
        vl[nvl++] = val[x] + 1;
    }
    else {
        vl[nvl++] = val[x] - val[prv[x]];
    }
    for (int i = 0, it = prv[x]; i < k - 1 && it != st; i++, it = prv[it]) {
        if (prv[it] == st) {
            vl[nvl++] = val[it] + 1;
        }
        else if (val[it] != val[prv[it]]) {
            vl[nvl++] = val[it] - val[prv[it]];
        }
        else {
            vl[nvl++] = 0;
        }
    }
    if (nxt[x] == ed) {
        vr[nvr++] = c - val[x];
    }
    else {
        vr[nvr++] = val[nxt[x]] - val[x];
    }
    for (int i = 0, it = nxt[x]; i < k - 1 && it != ed; i++, it = nxt[it]) {
        if (nxt[it] == ed) {
            vr[nvr++] = c - val[it];
        }
        else if (val[it] != val[nxt[it]]) {
            vr[nvr++] = val[nxt[it]] - val[it];
        }
        else {
            vr[nvr++] = 0;
        }
    }
    int res = 0;
    FOR(i, 0, k) {
        res += vl[i] * vr[k - i - 1];
    }
    nxt[prv[x]] = nxt[x];
    prv[nxt[x]] = prv[x];
    return res;
}

void solve() {
    cin >> r >> c >> n >> k;
    FOR(i, 0, n) {
        int x, y; cin >> x >> y; x--, y--;
        gx[x].pb(y);
    }
    long long ans = 0;
    FOR(i, 0, r) {
        static int li[maxn][maxn];
        int nli[maxn];
        fill_n(nli, c, 0);
        int ptr = 0;
        FOR(j, i, r) {
            FOR(l, 0, sz(gx[j])) {
                int y = gx[j][l];
                li[y][nli[y]++] = ptr;
                val[ptr++] = y;
            }
        }
        int st = ptr, ed = ptr + 1;
        static int v[maxn];
        int nv = 0;
        v[nv++] = st;
        FOR(j, 0, c) {
            FOR(l, 0, nli[j]) {
                v[nv++] = li[j][l];
            }
        }
        v[nv++] = ed;
        FOR(j, 0, nv - 1) {
            int l = v[j];
            int r = v[j + 1];
            nxt[l] = r, prv[r] = l;
        }
        static int rc[maxn];
        int nrc = 0;
        FORd(j, r, i) {
            int tot = 0;
            FORd(l, sz(gx[j]), 0) {
                int y = gx[j][l];
                tot += rem(--ptr, st, ed);
            }
            rc[nrc++] = tot;
        }
        int tot = c * (c + 1) / 2;
        FORd(j, nrc, 0) {
            tot -= rc[j];
            ans += tot;
        }
    }
    ans = (long long) r * (r + 1) * c * (c + 1) / 4 - ans;
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}