#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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
//const int MOD = (int) 1e9 + 7;
const int MOD = 998244353;
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

struct ZFuntion {
    int n;
    vector<int> f;
    void build(char* s) {
        n = strlen(s), f.resize(n);
        int l = 0, r = 0;
        f[0] = n;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = r = i;
                while (r < n && s[r] == s[r - l]) r++;
                f[i] = r - l, r--;
            }
            else {
                int k = i - l;
                if (f[k] < r - i + 1) f[i] = f[k];
                else {
                    l = i;
                    while (r < n && s[r] == s[r - l]) r++;
                    f[i] = r - l, r--;
                }
            }
        }
    }
} zf[2];

const int maxn = 2e6 + 5;
int n, m, k;
string s;
string t;
int a[maxn];
int b[maxn];

pi st[maxn << 1];
void upd(int p, pi val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
pi query(int l, int r) {
    pi res = mp(-INF, -INF);
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

set<pi> heap[maxn];

void add(int p, pi val) {
    heap[p].insert(val);
    upd(p, *heap[p].rbegin());
}
void rem(int p, pi val) {
    heap[p].erase(val);
    if (sz(heap[p])) {
        upd(p, *heap[p].rbegin());
    }
    else {
        upd(p, mp(-INF, -INF));
    }
}

void chemthan() {
    cin >> n >> m >> k;
    cin >> s >> t;
    zf[0].build((char *) (t + "$" + s).data());
    reverse(all(s)), reverse(all(t));
    zf[1].build((char *) (t + "$" + s).data());
    FOR(i, 0, 2) {
        for (int& x : zf[i].f) {
            chkmin(x, k);
        }
        FOR(j, 0, n) {
            zf[i].f[j] = zf[i].f[j + m + 1];
        }
    }
    reverse(zf[1].f.begin(), zf[1].f.begin() + n);
    FOR(i, 0, n) a[i] = zf[0].f[i], b[i] = zf[1].f[i];
    FOR(i, 0, n) {
        if (a[i] >= m) {
            int lo = i;
            int hi = i + m - 1;
            while (lo > 0 && hi - lo + 1 < k + k) lo--;
            cout << "Yes\n";
            cout << lo + 1 << " " << lo + k + 1 << "\n";
            return;
        }
    }
    fill_n(st, maxn << 1, mp(-INF, -INF));
    vii events1, events2;
    FOR(i, 0, n) {
        int ni = i - b[i] + k;
        if (ni < n) {
            add(b[i] + ni, mp(b[i], ni));
            events1.pb(mp(ni, b[i]));
        }
    }
    FOR(i, 0, n) {
        int ni = i + a[i] - k;
        if (ni >= 0) {
            events2.pb(mp(ni, a[i]));
        }
    }
    sort(all(events1)), sort(all(events2));
    int ptr = 0;
    FOR(l, 0, sz(events2)) {
        while (ptr < sz(events1) && events1[ptr].fi < events2[l].fi + k + k - 1) {
            int j = events1[ptr].fi;
            int bj = events1[ptr].se;
            rem(bj + j, mp(bj, j));
            ptr++;
        }
        int i = events2[l].fi;
        int ai = events2[l].se;
        int t = m + (n - 1) - (ai - i);
        pi mx = query(0, t);
        if (ai + mx.fi >= m) {
            int j = mx.se;
            int bj = mx.fi;
            int dif = ai + bj - m;
            int z = min(i, dif);
            dif -= z;
            cout << "Yes\n";
            cout << i - z + 1 << " " << j - (k - 1) + dif + 1 << "\n";
            return;
        }
    }
    cout << "No\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}