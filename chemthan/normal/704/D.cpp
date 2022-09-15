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

template<class TF, const TF Foo> struct Maxflow {
    static const int maxv = 1e6 + 5;
    static const int maxe = 1e7 + 5;
    
    int n, s, t, E;
    int adj[maxe], nxt[maxe], lst[maxv], lev[maxv], ptr[maxv], frm[maxv];
    TF cap[maxe], flw[maxe];
    
    void init(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, int c1, int c2) {
        adj[E] = v, nxt[E] = lst[u], lst[u] = E, cap[E] = c1, flw[E] = 0, E++;
        swap(u, v), swap(c1, c2);
        adj[E] = v, nxt[E] = lst[u], lst[u] = E, cap[E] = c1, flw[E] = 0, E++;
    }
    int bfs() {
        fill_n(lev, n, 0);
        queue<int> que;
        lev[s] = 1, que.push(s);
        while (sz(que)) {
            int u = que.front(); que.pop();
            for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (!lev[v]) {
                    lev[v] = lev[u] + 1;
                    que.push(v);
                }
            }
        }
        return lev[t];
    }
    TF dfs(int u, TF ff) {
        if (u == t) return ff;
        for (int& e = ptr[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
            int v = adj[e];
            TF res = 0;
            if (lev[v] == lev[u] + 1 && (res = dfs(v, min(ff, cap[e] - flw[e])))) {
                frm[v] = e;
                return res;
            }
        }
        return 0;
    }
    TF maxflow() {
        TF res = 0;
        while (bfs()) {
            FOR(i, 0, n) ptr[i] = lst[i];
            TF add = 0;
            while (add = dfs(s, Foo)) {
                res += add;
                int st = t;
                while (st != s) {
                    int e = frm[st];
                    flw[e] += add, flw[e ^ 1] -= add;
                    st = adj[e ^ 1];
                }
            }
        }
        return res;
    }
};
Maxflow<int, (int) 1e9> mf;

const int maxn = 1e5 + 5;
int n, m;
int r, b;
int x[maxn];
int y[maxn];
int f[maxn];
int g[maxn];
int cnt1, cnt2;
map<int, int> dc1;
map<int, int> dc2;
int ver[maxn];
int hor[maxn];
int vmn[maxn];
int vmx[maxn];
int hmn[maxn];
int hmx[maxn];
map<pi, int> hs;

int check() {
	int tot = cnt1 + cnt2;
	int s = tot++, t = tot++, _s = tot++, _t = tot++;
	mf.init(tot, _s, _t);
	int tot1 = 0, tot2 = 0;
	FOR(i, 0, cnt1) {
		mf.add(_s, i, vmn[i], 0);
		mf.add(s, i, vmx[i] - vmn[i], 0);
		tot1 += vmn[i];
	}
	FOR(i, 0, cnt2) {
		mf.add(cnt1 + i, _t, hmn[i], 0);
		mf.add(cnt1 + i, t, hmx[i] - hmn[i], 0);
		tot2 += hmn[i];
	}
	FOR(i, 0, n) {
		mf.add(x[i], cnt1 + y[i], 1, 0);
	}
	mf.add(s, _t, tot1, 0);
	mf.add(_s, t, tot2, 0);
	mf.add(t, s, INF, 0);
	return mf.maxflow() == tot1 + tot2;
}

void solve() {
	cin >> n >> m >> r >> b;
	FOR(i, 0, n) cin >> x[i] >> y[i];
	FOR(i, 0, n) dc1[x[i]];
	FORall(it, dc1) it->se = cnt1++;
	FOR(i, 0, n) ver[x[i] = dc1[x[i]]]++;
	FOR(i, 0, n) dc2[y[i]];
	FORall(it, dc2) it->se = cnt2++;
	FOR(i, 0, n) hor[y[i] = dc2[y[i]]]++;
	FOR(i, 0, cnt1) vmn[i] = 0, vmx[i] = ver[i];
	FOR(i, 0, cnt2) hmn[i] = 0, hmx[i] = hor[i];
	FOR(i, 0, m) {
		int t, l, d; cin >> t >> l >> d;
		if (t == 1) {
			if (dc1.count(l)) {
				l = dc1[l];
				chkmax(vmn[l], (ver[l] - d + 1) / 2);
				chkmin(vmx[l], (ver[l] + d) / 2);
				if (vmn[l] > vmx[l]) {
					cout << -1 << "\n";
					return;
				}
			}
		}
		else if (t == 2) {
			if (dc2.count(l)) {
				l = dc2[l];
				chkmax(hmn[l], (hor[l] - d + 1) / 2);
				chkmin(hmx[l], (hor[l] + d) / 2);
				if (hmn[l] > hmx[l]) {
					cout << -1 << "\n";
					return;
				}
			}
		}
	}
	if (!check()) {
		cout << -1 << "\n";
		return;
	}
	mf.s -= 2;
	mf.t -= 2;
	int tot = mf.maxflow();
	cout << (long long) max(r, b) * (n - tot) + (long long) min(r, b) * tot << "\n";
	FOR(i, 0, cnt1) {
		for (int e = mf.lst[i]; e != -1; e = mf.nxt[e]) if (mf.flw[e] > 0) {
			int j = mf.adj[e];
			if (j >= cnt1 && j < cnt1 + cnt2) {
				hs[mp(i, j - cnt1)]++;
			}
		}
	}
	FOR(i, 0, n) {
		if (hs[mp(x[i], y[i])]) {
			hs[mp(x[i], y[i])]--;
			if (r < b) cout << "r";
			else cout << "b";
		}
		else {
			if (r < b) cout << "b";
			else cout << "r";
		}
	}
	cout << "\n";
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