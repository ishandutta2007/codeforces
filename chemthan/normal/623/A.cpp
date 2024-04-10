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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a + val)) < 0) a += p;}

#define MAXV 200010
#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
namespace Twosat {
	int n;
	vector<int> forward[MAXV], backward[MAXV];
	bool used[MAXV];
	int cnt, order[MAXV], comp[MAXV];
	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; i++) {
			forward[i].clear();
			backward[i].clear();
		}
	}
	void add(int u, int v) {
		forward[u].push_back(v);
		backward[v].push_back(u);
	}
	void dfs1(int u) {
		used[u] = true;
		for (int i = 0; i < forward[u].size(); i++) {
			int v = forward[u][i];
			if (!used[v]) dfs1(v);
		}
		order[cnt++] = u;
	}
	void dfs2(int u, int c) {
		comp[u] = c;
		for (int i = 0; i < backward[u].size(); i++) {
			int v = backward[u][i];
			if (comp[v] == -1) dfs2(v, c);
		}
	}
	bool solve(vector<int> &res) {
		cnt = 0;
		memset(used, 0, sizeof(used));
		for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
		memset(comp, -1, sizeof(comp));
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			int u = order[i];
			if (comp[u] == -1) dfs2(u, c++);
		}
		for (int u = 0; u < n; u += 2)
			if (comp[u] == comp[u ^ 1]) return false;
		res.clear();
		for (int u = 0; u < n; u += 2) {
			int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
			if (!(choose & 1)) res.push_back(choose >> 1);
		}
		return true;
	}
}

const int maxn = 510;
int n, m;
int a[maxn][maxn];
int f[maxn];
int g[maxn];

void solve() {
	cin>>n>>m;
	FOR(i, 0, m) {
		int u, v; cin>>u>>v; u--; v--;
		a[u][v] = a[v][u] = 1;
	}
	Twosat::init(n << 1);
	FOR(i, 0, n) FOR(j, 0, n) if (i != j) {
		if (!a[i][j]) {
			Twosat::add(pos(i), neg(j));
			Twosat::add(pos(j), neg(i));
			Twosat::add(neg(i), pos(j));
			Twosat::add(neg(j), pos(i));
			f[i] = f[j] = 1;
		}
	}
	FOR(i, 0, n) FOR(j, 0, n) if (i != j) {
		if (a[i][j]) {
			if (f[i] && f[j]) {
				Twosat::add(pos(i), pos(j));
				Twosat::add(neg(i), neg(j));
			}
		}
	}
	vi res;
	if (Twosat::solve(res)) {
		cout<<"Yes\n";
		FOR(i, 0, sz(res)) g[res[i]] = 1;
		FOR(i, 0, n) {
			if (!f[i]) cout<<"b";
			else if (g[i]) cout<<"a";
			else cout<<"c";
		}
	}
	else cout<<"No";
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