#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

struct Seg {
    static const int maxn = 1e5 + 5;
    
    struct node_t {
        int mx, sc, cnt;
        long long sum;
        node_t(int mx = INF + 5, int sc = -1, int cnt = 0, long long sum = INF + 5) : mx(mx), sc(sc), cnt(cnt), sum(sum) {}
    };
    
    int cmp(int a, int b) {
        //if (!a) a = INF + 5;
        //if (!b) b = INF + 5;
        return a < b;
    }
    
    int mmax(int a, int b) {
        return cmp(a, b) ? b : a;
    }
    
    node_t join(node_t& a, node_t& b) {
        node_t res;
        res.mx = mmax(a.mx, b.mx);
        res.sc = mmax(a.sc, b.sc);
        if (cmp(a.mx, b.mx)) {
            res.sc = mmax(a.mx, b.sc);
        }
        if (cmp(b.mx, a.mx)) {
            res.sc = mmax(a.sc, b.mx);
        }
        if (res.mx == a.mx) res.cnt += a.cnt;
        if (res.mx == b.mx) res.cnt += b.cnt;
        res.sum = a.sum + b.sum;
        return res;
    }
    
    node_t st[maxn << 2];
    
    void push(int p) {
        FOR(i, p << 1, p + 1 << 1) {
            if (cmp(st[p].mx, st[i].mx)) {
                st[i].sum += (long long) (st[p].mx - st[i].mx) * st[i].cnt;
                st[i].mx = st[p].mx;
            }
        }
    }
    
    void build(int p, int L, int R) {
        if (L == R) {
            st[p].cnt = 1;
            return;
        }
        build(p << 1, L, L + R >> 1);
        build(p << 1 | 1, (L + R >> 1) + 1, R);
        st[p] = join(st[p << 1], st[p << 1 | 1]);
    }
    
    void upd(int p, int l, int r, int L, int R, int val) {
        if (L < R) push(p);
        if (l > R || r < L || cmp(st[p].mx, val)) return;
        if (l <= L && R <= r && cmp(st[p].sc, val)) {
            st[p].sum += (long long) (val - st[p].mx) * st[p].cnt;
            st[p].mx = val;
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = join(st[p << 1], st[p << 1 | 1]);
    }
    
    long long querysum(int p, int l, int r, int L, int R) {
        if (L < R) push(p);
        if (l > R || r < L) return 0;
        if (l <= L && R <= r) {
            long long res = st[p].sum;
            if (st[p].mx == INF + 5) {
                res -= (long long) st[p].mx * st[p].cnt;
            }
            return res;
        }
        return querysum(p << 1, l, r, L, L + R >> 1) + querysum(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
    }
    
    int querymax(int p, int l, int r, int L, int R) {
        if (L < R) push(p);
        if (l > R || r < L) return -1;
        if (l <= L && R <= r) return st[p].mx;
        return mmax(querymax(p << 1, l, r, L, L + R >> 1), querymax(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};

const int maxn = 1e5 + 5;
Seg seg[4];
set<int> st[2];

void upd(int k, int l, int r, int val) {
    set<int>::iterator it = st[k].lower_bound(l);
    vi vals;
    while (it != st[k].end() && *it <= r) {
        vals.pb(*it);
        it++;
    }
    FOR(i, 0, sz(vals)) {
        int u = vals[i];
        st[k].erase(u);
        int x = seg[k ^ 1].querymax(1, u, u, 0, maxn - 1);
        if (x < INF + 5) {
            seg[2].upd(1, u, u, 0, maxn - 1, 0);
            seg[3].upd(1, u, u, 0, maxn - 1, 0);
        }
    }
    seg[k | 2].upd(1, l, r, 0, maxn - 1, val);
}

void solve() {
    FOR(i, 0, 4) seg[i].build(1, 0, maxn - 1);
    FOR(i, 0, maxn) st[0].insert(i), st[1].insert(i);
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, k; cin >> l >> r >> k; r--;
            if (k > 0) {
                seg[0].upd(1, l, r, 0, maxn - 1, k);
                upd(0, l, r, k);
            }
            else {
                seg[1].upd(1, l, r, 0, maxn - 1, -k);
                upd(1, l, r, -k);
            }
        }
        else {
            int l, r; cin >> l >> r; r--;
            long long res = 0;
            FOR(i, 0, 2) {
                res += seg[i].querysum(1, l, r, 0, maxn - 1);
                res -= seg[i | 2].querysum(1, l, r, 0, maxn - 1);
            }
            cout << res << "\n";
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