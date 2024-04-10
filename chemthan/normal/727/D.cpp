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

struct Dinic {
	typedef int T;
	static const T oo = (T) 1e9;
	static const int MAXV = 100000 + 10;
	static const int MAXE = 1000000 + 10;
	int n, s, t, E, adj[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	T flow[MAXE], cap[MAXE];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		fill_n(last, n + 1, -1);
	}
	void add(int u, int v, T c1, T c2) {
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

const int maxn = 100000 + 10;
int n;
int a[6];
map<string, int> hs;
string ar[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

void solve() {
	FOR(i, 0, 6) hs[ar[i]] = i;
	FOR(i, 0, 6) cin >> a[i];
	cin >> n;
	int tot = n + 6, s = tot++, t = tot++;
	dinic.init(tot, s, t);
	FOR(i, 0, 6) {
		dinic.add(n + i, t, a[i], 0);
	}
	FOR(i, 0, n) {
		dinic.add(s, i, 1, 0);
		string s; cin >> s;
		int k;
		if ((k = s.find(",")) == -1) {
			dinic.add(i, n + hs[s], 1, 0);
		}
		else {
			string s1 = s.substr(0, k);
			string s2 = s.substr(k + 1);
			dinic.add(i, n + hs[s1], 1, 0);
			dinic.add(i, n + hs[s2], 1, 0);
		}
	}
	if (dinic.maxflow() < n) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		FOR(i, 0, n) {
			for (int e = dinic.last[i]; ~e; e = dinic.next[e]) {
				if (dinic.flow[e] > 0) {
					int ix = dinic.adj[e] - n;
					cout << ar[ix] << "\n";
				}
			}
		}
	}
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