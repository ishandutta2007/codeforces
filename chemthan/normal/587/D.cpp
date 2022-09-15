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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 50010;
int n, m;
vector<pair<int, pair<pi, int> > > adj[maxn];
vector<pair<int, pair<pi, int> > > adj2[maxn];
vector<int> res;

#define MAXV 300010
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
	int solve() {
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
			if (comp[u] == comp[u ^ 1]) return 0;
		res.clear();
		for (int u = 0; u < n; u += 2) {
			int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
			if (!(choose & 1)) res.push_back(1); else res.push_back(0);
		}
		return 1;
	}
}

int check(int mid) {
	Twosat::init(6 * m);
	int cnt = m;
	FOR(i, 0, n) {
		if (sz(adj2[i])) {
			int u = adj2[i][0].se.se;
			int v = adj2[i][1].se.se;
			Twosat::add(pos(u), neg(v));
			Twosat::add(neg(u), pos(v));
			Twosat::add(pos(v), neg(u));
			Twosat::add(neg(v), pos(u));
		}
		FOR(j, 0, sz(adj[i]) - 1) {
			int u = adj[i][j].se.se;
			int v = adj[i][j + 1].se.se;
			Twosat::add(pos(cnt + j), pos(cnt + j + 1));
			Twosat::add(neg(cnt + j + 1), neg(cnt + j));
			Twosat::add(pos(cnt + j), neg(v));
			Twosat::add(pos(v), neg(cnt + j));
		}
		FOR(j, 0, sz(adj[i])) {
			int u = adj[i][j].se.se;
			if (adj[i][j].se.fi.se > mid) {
				Twosat::add(pos(u), neg(u));
			}	
			Twosat::add(pos(u), pos(cnt + j));
			Twosat::add(neg(cnt + j), neg(u));
		}
		cnt += sz(adj[i]);
	}
	return Twosat::solve();
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int u, v, c, t; scanf("%d%d%d%d", &u, &v, &c, &t); u--; v--;
		adj[u].pb(mp(c, mp(mp(v, t), i))); adj[v].pb(mp(c, mp(mp(u, t), i)));
	}
	FOR(i, 0, n) {
		sort(all(adj[i]));
		vector<pair<int, pair<pi, int> > > t;
		FOR(j, 1, sz(adj[i]) - 1) {
			if (adj[i][j].fi == adj[i][j - 1].fi || adj[i][j].fi == adj[i][j + 1].fi) {
				t.pb(adj[i][j]);
			}
		}
		if (sz(adj[i]) > 1) {
			if (adj[i][0].fi == adj[i][1].fi) {
				t.pb(adj[i][0]);
			}
			if (adj[i][sz(adj[i]) - 1].fi == adj[i][sz(adj[i]) - 2].fi) {
				t.pb(adj[i][sz(adj[i]) - 1]);
			}
		}
		if (sz(t) > 2) {printf("No"); return;}
		adj2[i] = t;
	}
	int l = 0, r = INF;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) l = mid + 1; else r = mid;
	}
	if (!check(l)) printf("No");
	else {
		printf("Yes\n");
		vi ans;
		FOR(i, 0, m) if (res[i]) ans.pb(i);
		printf("%d %d\n", l, sz(ans));
		FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
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