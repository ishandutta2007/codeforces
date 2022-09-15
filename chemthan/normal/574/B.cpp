#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 4010;
int n, m;
vi adj[maxn];
int d[maxn];
int g[maxn][maxn];

void solve() {
	ms(d, 0); ms(g, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		d[a]++; d[b]++;
		g[a][b] = g[b][a] = 1;
	}
	int ans = -1;
	FOR(i, 0, n) {
		FOR(j, 0, sz(adj[i])) FOR(k, 0, sz(adj[i])) {
			int u = adj[i][j];
			int v = adj[i][k];
			if (u != i && v != i && u != v && g[u][v]) {
				int tmp = d[i] + d[u] + d[v] - 6;
				if (ans == -1) ans = tmp; else ans = min(ans, tmp);
			}
		}
	}
	printf("%d", ans);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}