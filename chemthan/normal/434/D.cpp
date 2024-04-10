#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

typedef int T;
#define MAXV 100010
#define MAXE 1000010
const T oo = (T) 1e9;
struct Dinic {
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
} dinic;

const int maxn = 60;
int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int l[maxn];
int r[maxn];
int id[maxn][210];

int f(int i, int x) {
	return a[i] * x * x + b[i] * x + c[i];
}

void solve() {
	cin>>n>>m;
	int tot = 0;
	FOR(i, 0, n) cin>>a[i]>>b[i]>>c[i];
	int dmax = -INF;
	FOR(i, 0, n) {
		cin>>l[i]>>r[i];
		FOR(j, l[i] - 1, r[i] + 1) {
			id[i][j - l[i] + 1] = tot++;
			chkmax(dmax, f(i, j));
		}
	}
	int s = tot++, t = tot++;
	dinic.init(tot, s, t);
	FOR(i, 0, n) {
		dinic.add(s, id[i][0], INF, 0);
		dinic.add(id[i][r[i] - l[i] + 1], t, INF, 0);
		FOR(j, l[i] - 1, r[i]) {
			dinic.add(id[i][j - l[i] + 1], id[i][j - l[i] + 2], dmax - f(i, j + 1), 0);
		}
	}
	while (m--) {
		int u, v, d; cin>>u>>v>>d; u--; v--;
		FOR(i, l[u] - 1, r[u] + 1) {
			if (i - d >= l[v] - 1 && i - d <= r[v]) {
				dinic.add(id[u][i - l[u] + 1], id[v][i - d - l[v] + 1], INF, 0);
			}
		}
	}
	cout<<dmax * n - dinic.maxflow()<<"\n";
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