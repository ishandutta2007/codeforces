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
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

#define MAXV 1010
#define MAXE 1000010
#define INF 1000000000
struct Dinic {
	int n, s, t, E, adj[MAXE], flow[MAXE], cap[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		for (int i = 0; i <= n; i++) last[i] = -1;
	}
	void add(int u, int v, int c1, int c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}
	bool bfs() {
		for (int i = 0; i <= n; i++) level[i] = -1;
		level[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && level[v] == -1) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return level[t] != -1;
	}
	int dfs(int u, int bot) {
		if (u == t) return bot;
		for (int &e = run[u]; e != -1; e = next[e]) {
			int v = adj[e], delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}
	int maxflow() {
		int total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = last[i];
			for (int delta = dfs(s, INF); delta > 0; delta = dfs(s, INF)) total += delta;
		}
		return total;
	}
} dinic;

const int maxn = 60;
const int maxm = 510;
int n, m, x;
vector<pair<pi, int> > edges;

void solve() {
	cin>>n>>m>>x;
	FOR(i, 0, m) {
		int u, v, w; cin>>u>>v>>w; u--; v--;
		edges.pb(mp(mp(u, v), w));
	}
	ld l = 0, r = INF;
	FOR(_, 0, 200) {
		ld mid = (l + r) / 2;
		dinic.init(n, 0, n - 1);
		FOR(i, 0, sz(edges)) {
			int u = edges[i].fi.fi;
			int v = edges[i].fi.se;
			int w = edges[i].se;
			w = (int) min(w / mid, (ld) 1e9);
			dinic.add(u, v, w, 0);
		}
		if (dinic.maxflow() >= x) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout<<prec(9)<<l * x<<"\n";
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}