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

const int maxn = 300010;
int n;
vi adj[maxn];
ll c[maxn];
char d[maxn];
ll dmax, cnt;
int size[maxn];
int mcld[maxn];

void fdfs(int u, int p = -1) {
	size[u] = 1; mcld[u] = -1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != p) {
			fdfs(v, u);
			size[u] += size[v];
			if (mcld[u] == -1 || size[v] > size[mcld[u]]) mcld[u] = v;
		}
	}
}

map<pi, int>* dfs(int u, int p = -1, int hash1 = 0, int hash2 = 0) {
	hash1 = (2311LL * hash1 + d[u]) % MOD;
	hash2 = 257 * hash2 + d[u];
	int k = mcld[u];
	map<pi, int>* res;
	if (k == -1) {
		res = new map<pi, int>;
		(*res)[mp(hash1, hash2)]++;
	}
	else {
		res = dfs(k, u, hash1, hash2);
		(*res)[mp(hash1, hash2)]++;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			if (v != p && v != k) {
				map<pi, int>* t = dfs(v, u, hash1, hash2);
				FORall(it, *t) (*res)[it->fi] += it->se;
			}
		}
	}
	if (dmax < sz(*res) + c[u]) {
		dmax = sz(*res) + c[u];
		cnt = 1;
	}
	else if (dmax == sz(*res) + c[u]) cnt++;
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%I64d", c + i);
	char s[maxn]; scanf("%s", s);
	FOR(i, 0, n) d[i] = s[i];
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	fdfs(0); dfs(0);
	printf("%I64d\n%I64d", dmax, cnt);
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