#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 210;
int n, m, q;
int x[maxn][maxn];
int a[10], b[10];
char s[1000010];
vi adj[maxn * maxn];
vi radj[maxn * maxn];
int d[maxn * maxn];
int e[maxn * maxn];
bool vis[maxn * maxn];
vi vs, t;
int bms;

int get(int i, int j) {
	return i * m + j;
}

void dfs(int u) {
	vis[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (!vis[v]) dfs(v);
	}
	vs.pb(u);
}

void rdfs(int u) {
	vis[u] = 1;
	t.pb(u); bms |= (1 << d[u]);
	FOR(i, 0, sz(radj[u])) {
		int v = radj[u][i];
		if (!vis[v]) rdfs(v);
	}
}

bool work(int u, char* s, vi cnt, int bitmask) {
	if (e[u]) {
		if ((e[u] & bitmask) == bitmask) return 1;
		return 0;
	}
	int k = s[0] - '0';
	if (d[u] == k) {
		s++;
		if (!(--cnt[k])) bitmask ^= (1 << k);
	}
	if (s[0] == 0) return 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (work(v, s, cnt, bitmask)) return 1;
	}
	return 0;
}

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) d[get(i, j)] = x[i][j] = s[j] - '0';
	}
	FOR(i, 0, 10) scanf("%d%d", a + i, b + i);
	FOR(i, 0, n) FOR(j, 0, m) {
		int k = x[i][j];
		if (!a[k] && !b[k])
			e[get(i, j)] = 1 << k;
		else if (i + a[k] >= 0 && i + a[k] < n && j + b[k] >= 0 && j + b[k] < m) {
			adj[get(i, j)].pb(get(i + a[k], j + b[k]));
			radj[get(i + a[k], j + b[k])].pb(get(i, j));
		}
	}
	FOR(i, 0, n * m) if (!vis[i]) dfs(i);
	ms(vis, 0);
	FORd(i, sz(vs), 0) {
		int u = vs[i];
		if (!vis[u]) {
			bms = 0; rdfs(u);
			if (sz(t) == 1) {t.clear(); continue;}
			while (sz(t)) {
				e[t.back()] = bms;
				t.pop_back();
			}
		}
	}
	FOR(i, 0, n * m) if (!sz(adj[i])) e[i] = (1 << d[i]);
	while (q--) {
		scanf("%s", s);
		vi cnt(10, 0);
		int bitmask = 0, len = strlen(s);
		FOR(i, 0, len) {
			cnt[s[i] - '0']++;
			bitmask |= (1 << (s[i] - '0'));
		}
		bool flag = 0;
		FOR(i, 0, n * m)  if ((!sz(radj[i]) || e[i]) && work(i, s, cnt, bitmask)) {printf("YES\n"); flag = 1; break;}
		if (!flag) printf("NO\n");
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}