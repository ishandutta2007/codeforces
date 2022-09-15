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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200000 + 10;
int n, m;
vii edge;
int s, t, ds, dt;
int f[maxn];
int g[maxn];
int con;
vii ans;

int dj[maxn];
void init() {
	FOR(i, 0, n) dj[i] = i;
}
int find(int u) {
	return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
	int p = find(u);
	int q = find(v);
	if (p != q) {
		dj[p] = q;
		return 1;
	}
	return 0;
}

typedef int T;
struct Dinic {
	static const T oo = (T) 1e9;
	static const int MAXV = 1000000 + 10;
	static const int MAXE = 2000000 + 10;
	int n, s, t, E, adj[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	T flow[MAXE], cap[MAXE];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		fill_n(last, n + 1, -1);
	}
	void add(int u, int v, int c1, int c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}
	int bfs() {
		fill_n(level, n + 1, -1);
		level[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; ~e; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && !~level[v]) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return level[t] != -1;
	}
	T dfs(int u, T bot) {
		if (u == t) return bot;
		for (int& e = run[u]; ~e; e = next[e]) {
			int v = adj[e];
			T delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}
	T maxflow() {
		T total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = last[i];
			for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
		}
		return total;
	}
	void trace(int s, int t) {
		for (int e = last[0]; ~e; e = next[e]) if (flow[e] > 0) {
			int v = adj[e];
			if (v < n + 2 && v >= 2) {
				ans.pb(mp(s, f[v - 2]));
			}
		}
		for (int e = last[1]; ~e; e = next[e]) if (flow[e] > 0) {
			int v = adj[e];
			if (v < n + 2 && v >= 2) {
				ans.pb(mp(t, g[v - 2]));
			}
		}
	}
} dinic;

void work1() {
	if (!con) return;
	fill_n(f, n, -1), fill_n(g, n, -1);
	int tot = n + 2, ss = tot++, tt = tot++;
	dinic.init(tot, ss, tt);
	dinic.add(ss, 0, ds - 1, 0);
	dinic.add(ss, 1, dt - 1, 0);
	FOR(i, 0, n) dinic.add(2 + i, tt, 1, 0);
	int cnt = 0;
	FOR(i, 0, n) if (i != s && i != t) {
		if (find(i) == i) {
			cnt++;
		}
	}
	FOR(i, 0, sz(edge)) {
		int u = edge[i].fi;
		int v = edge[i].se;
		if (u != s) swap(u, v);
		if (u == s && v != t) {
			int ix = find(v);
			if (f[ix] == -1) {
				f[ix] = v;
				dinic.add(0, 2 + ix, 1, 0);
			}
		}
		if (u != t) swap(u, v);
		if (u == t && v != s) {
			int ix = find(v);
			if (g[ix] == -1) {
				g[ix] = v;
				dinic.add(1, 2 + ix, 1, 0);
			}
		}
	}
	if (dinic.maxflow() == cnt) {
		dinic.trace(s, t);
		ans.pb(mp(s, t));
		cout << "Yes\n";
		FOR(i, 0, sz(ans)) {
			cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n";
		}
		exit(0);
	}
}

void work2() {
	fill_n(f, n, -1), fill_n(g, n, -1);
	int tot = n + 2, ss = tot++, tt = tot++;
	dinic.init(tot, ss, tt);
	dinic.add(ss, 0, ds - 1, 0);
	dinic.add(ss, 1, dt - 1, 0);
	FOR(i, 0, n) dinic.add(2 + i, tt, 1, 0);
	int cnt = 0;
	FOR(i, 0, n) if (i != s && i != t) {
		if (find(i) == i) {
			cnt++;
		}
	}
	FOR(i, 0, sz(edge)) {
		int u = edge[i].fi;
		int v = edge[i].se;
		if (u != s) swap(u, v);
		if (u == s && v != t) {
			int ix = find(v);
			if (f[ix] == -1) {
				f[ix] = v;
			}
		}
		if (u != t) swap(u, v);
		if (u == t && v != s) {
			int ix = find(v);
			if (g[ix] == -1) {
				g[ix] = v;
			}
		}
	}
	int ix = -1;
	FOR(i, 0, n) {
		if (f[i] != -1 && g[i] != -1) {
			ix = i;
			break;
		}
	}
	if (ix == -1) {
		return;
	}
	FOR(i, 0, n) if (f[i] != -1 && i != ix) {
		dinic.add(0, 2 + i, 1, 0);
	}
	FOR(i, 0, n) if (g[i] != -1 && i != ix) {
		dinic.add(1, 2 + i, 1, 0);
	}
	if (dinic.maxflow() == cnt - 1) {
		dinic.trace(s, t);
		ans.pb(mp(s, f[ix]));
		ans.pb(mp(t, g[ix]));
		cout << "Yes\n";
		FOR(i, 0, sz(ans)) {
			cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n";
		}
		exit(0);
	}
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, m) {
		int u, v; cin >> u >> v; u--, v--;
		edge.pb(mp(u, v));
	}
	cin >> s >> t >> ds >> dt; s--, t--;
	init();
	FOR(i, 0, m) {
		int u = edge[i].fi;
		int v = edge[i].se;
		if (mp(u, v) == mp(s, t) || mp(u, v) == mp(t, s)) {
			con = 1;
		}
		if (u != s && u != t && v != s && v != t) {
			if (join(u, v)) {
				ans.pb(mp(u, v));
			}
		}
	}
	work1(), work2();
	cout << "No\n";
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