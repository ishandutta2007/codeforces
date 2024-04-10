#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 500010;
const int maxc = 26;
int n, m;
vi adj[maxn];
char s[maxn];
int d[maxn];
int tms;
int tin[maxn];
int tou[maxn];
vii v1[maxn];
vii v2[maxn];
vi a[maxn];

void dfs(int u) {
	tin[u] = tms++;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		d[v] = d[u] + 1; dfs(v);
	}
	tou[u] = tms++;
	v1[d[u]].push_back(make_pair(tin[u], u));
	v2[d[u]].push_back(make_pair(tou[u], u));
}

void query(int u, int h) {
	if (d[u] >= h || !sz(v1[h])) {printf("Yes\n"); return;}
	int L = lower_bound(v1[h].begin(), v1[h].end(), make_pair(tin[u], 0)) - v1[h].begin();
	int R = lower_bound(v2[h].begin(), v2[h].end(), make_pair(tou[u], 0)) - v2[h].begin(); R--;
	if (L == sz(v1[h]) || R < 0 || L > R) {printf("Yes\n"); return;}
	int k = a[h][R + 1] ^ a[h][L];
	int cnt = 0;
	FOR(i, 0, maxc) if (k & (1 << i)) cnt++;
	if (cnt < 2) printf("Yes\n"); else printf("No\n");
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n - 1) {
		int p; scanf("%d", &p); p--;
		adj[p].push_back(i + 1);
	}
	scanf("%s", s);
	tms = 0; d[0] = 1; dfs(0);
	FOR(i, 1, n + 1) FOR(j, 0, sz(v1[i]) + 1) if (!j) a[i].push_back(0); else a[i].push_back(a[i].back() ^ (1 << (s[v1[i][j - 1].second] - 'a')));
	while (m--) {
		int v, h; scanf("%d%d", &v, &h); v--;
		query(v, h);
	}
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}