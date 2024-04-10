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
int n, q;
int x[maxn];
int y[maxn];
int L[maxn];
int R[maxn];
map<pi, int> hs;
int ans[maxn];
int tms;
vector<pair<int, pair<int*, int> > > rc;

inline void change(int* x, int v) {
    rc.pb(mp(tms, mp(x, *x)));
    *x = v;
}

void rollback(int pts) {
    while (sz(rc) && rc.back().fi >= pts) {
        *rc.back().se.fi = rc.back().se.se;
        rc.pop_back();
    }
}

int dj[maxn];
int rk[maxn];
int state;
void init() {
    FOR(i, 0, n + n) dj[i] = i, rk[i] = 1;
}
int find(int u) {
    if (dj[u] == u) return dj[u];
    change(&dj[u], find(dj[u]));
    return dj[u];
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    p = find(p);
    q = find(q);
    if (rk[p] < rk[q]) change(&dj[p], q);
    else change(&dj[q], p);
    if (rk[p] == rk[q]) change(&rk[p], rk[p] + 1);
}

void divide(int l, int r, vi& seg) {
    int pts = ++tms;
	if (l == r) {
		FOR(i, 0, sz(seg)) {
			int ix = seg[i];
			int u = x[ix];
			int v = y[ix];
			if (find(u << 1) == find(v << 1) || find(u << 1 | 1) == find(v << 1 | 1)) {
			    change(&state, 1);
			}
			join(u << 1, v << 1 | 1);
			join(u << 1 | 1, v << 1);
		} 
		ans[l] = state;
		rollback(pts);
		return;
	}
	int m = l + r >> 1;
	vi seg1, seg2;
	FOR(i, 0, sz(seg)) {
	    int ix = seg[i];
		int ll = L[ix];
		int rr = R[ix];
		if (ll <= l && rr >= r) {
		    int u = x[ix];
			int v = y[ix];
			if (find(u << 1) == find(v << 1) || find(u << 1 | 1) == find(v << 1 | 1)) {
			    change(&state, 1);
			}
			join(u << 1, v << 1 | 1);
			join(u << 1 | 1, v << 1);
		}
		else {
			if (ll <= m) {
				seg1.pb(seg[i]);
			}
			if (rr > m) {
				seg2.pb(seg[i]);
			}
		}
	}
	divide(l, m, seg1);
	divide(m + 1, r, seg2);
	rollback(pts);
}

void solve() {
    cin >> n >> q;
    int cnt = 0;
    FOR(i, 0, q) {
        cin >> x[cnt] >> y[cnt]; x[cnt]--, y[cnt]--;
        if (!hs[mp(x[cnt], y[cnt])]) {
            L[cnt] = i, R[cnt] = q - 1;
            hs[mp(x[cnt], y[cnt])] = ++cnt;
        }
        else {
            int ix = hs[mp(x[cnt], y[cnt])] - 1;
            R[ix] = i - 1;
            hs[mp(x[cnt], y[cnt])] = 0;
        }
    }
    init();
    vi seg;
    FOR(i, 0, cnt) seg.pb(i);
    divide(0, q - 1, seg);
    FOR(i, 0, q) {
        if (!ans[i]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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