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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

template<class TF, class TC, const TF Foo, const TC Coo> struct MincostMaxflow {
    static const int maxv = 1e5 + 5;
    static const int maxe = 1e6 + 5;
    int n, s, t, E;
    int adj[maxe], nxt[maxe], lst[maxv], vis[maxv], frm[maxv];
    TF cap[maxe], flw[maxe], totflw;
    TC cst[maxe], dst[maxv], totcst;
    
    void init(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t, E = 0;
        fill_n(lst, n, -1);
    }
    
    void add(int u, int v, int f, int c) {
        adj[E] = v, nxt[E] = lst[u], lst[u] = E, cap[E] = f, flw[E] = 0, cst[E] = c, E++;
        swap(u, v), f = 0, c *= -1;
        adj[E] = v, nxt[E] = lst[u], lst[u] = E, cap[E] = f, flw[E] = 0, cst[E] = c, E++;
    }
    
    int spfa() {
        fill_n(dst, n, Coo);
        queue<int> que;
        dst[s] = 0, vis[s] = 1, que.push(s);
        while (sz(que)) {
            int u = que.front(); que.pop();
            for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (chkmin(dst[v], dst[u] + cst[e])) {
                    frm[v] = e;
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
            vis[u] = 0;
        }
        return dst[t] < Coo;
    }
    TC mincost() {
        totflw = totcst = 0;
        while (spfa()) {
            TF ff = Foo;
            int st = t;
            while (st != s) {
                int e = frm[st];
                chkmin(ff, cap[e] - flw[e]);
                st = adj[e ^ 1];
            }
            st = t;
            while (st != s) {
                int e = frm[st];
                flw[e] += ff, flw[e ^ 1] -= ff;
                st = adj[e ^ 1];
            }
            totflw += ff;
            totcst += ff * dst[t];
        }
        return totcst;
    }
};
MincostMaxflow<long long, long long, (long long) 1e18, (long long) 1e18> mcf;

const int maxn = 100 + 10;
int n, m;
int d[maxn];

void solve() {
	cin >> n >> m;
	mcf.init(n + 2, n, n + 1);
	int ans = 0;
	FOR(i, 0, m) {
		int u, v, c, f; cin >> u >> v >> c >> f; u--, v--;
		if (c >= f) {
			d[u] -= f, d[v] += f;
			mcf.add(u, v, c - f, 1);
			mcf.add(u, v, INF, 2);
			mcf.add(v, u, f, 1);
		}
		else {
			d[u] -= c, d[v] += c;
			ans += f - c;
			mcf.add(u, v, f - c, 0);
			mcf.add(u, v, INF, 2);
			mcf.add(v, u, c, 1);
		}
	}
	mcf.add(n - 1, 0, INF, 0);
	FOR(i, 0, n) {
		if (d[i] > 0) {
			mcf.add(n, i, d[i], 0);
		}
		else if (d[i] < 0) {
			mcf.add(i, n + 1, -d[i], 0);
		}
	}
	cout << ans + mcf.mincost() << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}