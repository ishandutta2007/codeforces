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

struct MincostFlow {
	typedef long long T;
	static const T oo = (T) 1e18;
	static const int MAXV = 100000 + 10;
	static const int MAXE = 10000000 + 10;
	int n, s, t, E, adj[MAXE], next[MAXE], last[MAXV], which[MAXV];
	T totalCost, totalFlow, cap[MAXE], flow[MAXE], cost[MAXE], pot[MAXE], dist[MAXV];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t;
		memset(last, -1, sizeof(last)); E = 0;
	}
	void add(int u, int v, T ca, T co) {
		adj[E] = v; cap[E] = ca; flow[E] = 0; cost[E] = +co; next[E] = last[u]; last[u] = E++;
		adj[E] = u; cap[E] =  0; flow[E] = 0; cost[E] = -co; next[E] = last[v]; last[v] = E++;
	}
	void bellman() {
		int stop = 0;
		fill_n(pot, n, 0);
		while (!stop) {
			stop = 1;
			for (int u = 0; u < n; u++) for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				if (pot[v] > pot[u] + cost[e]) {
					pot[v] = pot[u] + cost[e];
					stop = 0;
				}
			}
		}
	}
	int dijkstra() {
		typedef pair<T, int> node;
		priority_queue<node, vector<node>, greater<node> > que;
		for (int u = 0; u < n; u++) dist[u] = oo;
		dist[s] = 0;
		que.push(make_pair(0, s));
		while (!que.empty()) {
			T dnow = que.top().first;
			int u = que.top().second;
			que.pop();
			if (dnow > dist[u]) continue;
			for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				T dnext = dnow + cost[e] + pot[u] - pot[v];
				if (dist[v] > dnext) {
					dist[v] = dnext;
					which[v] = e;
					que.push(make_pair(dnext, v));
				}
			}
		}
		return dist[t] < oo;
	}
	int maxflow(T desireFlow = oo) {
		totalCost = totalFlow = 0;
		bellman();
		while (totalFlow < desireFlow) {
			if (!dijkstra()) return 0;
			T delta = desireFlow - totalFlow;
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) delta = min(delta, cap[e] - flow[e]);
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) {
				flow[e] += delta;
				flow[e ^ 1] -= delta;
			}
			totalFlow += delta;
			totalCost += delta * (dist[t] - pot[s] + pot[t]);
			for (int u = 0; u < n; u++) pot[u] += dist[u];
		}
		return 1;
	}
} mcf;

const int maxn = 3000 + 10;
int n, p, s;
int a[maxn];
int b[maxn];

void solve() {
	cin >> n >> p >> s;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n) cin >> b[i];
	int tot = n + 2, ss = tot++, tt = tot++;
	mcf.init(tot, ss, tt);
	FOR(i, 0, n) {
		mcf.add(ss, i, 1, 0);
		mcf.add(i, n, 1, -a[i]);
		mcf.add(i, n + 1, 1, -b[i]);
	}
	mcf.add(n, tt, p, 0);
	mcf.add(n + 1, tt, s, 0);
	mcf.maxflow();
	cout << -mcf.totalCost << "\n";
	vi res[2];
	FOR(i, 0, n) {
		for (int e = mcf.last[i]; ~e; e = mcf.next[e]) if (mcf.flow[e] > 0) {
			int v = mcf.adj[e] - n;
			res[v].pb(i);
		}
	}
	FOR(i, 0, sz(res[0])) cout << res[0][i] + 1 << " \n"[i == sz(res[0]) - 1];
	FOR(i, 0, sz(res[1])) cout << res[1][i] + 1 << " \n"[i == sz(res[1]) - 1];
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