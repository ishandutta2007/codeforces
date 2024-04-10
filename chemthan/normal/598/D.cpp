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

const int maxn = 1010;
int n, m, k;
int a[maxn][maxn];
char s[maxn];
bool vis[maxn][maxn];
int cnt[maxn * maxn];
int com[maxn][maxn];

void dfs(int u, int v, int d) {
	vis[u][v] = 1;
	com[u][v] = d;
	FOR(i, -1, 2) FOR(j, -1, 2) if (i * j == 0 && i + j != 0) {
		if (u + i >= 0 && u + i < n && v + j >= 0 && v + j < m) {
			if (a[u + i][v + j]) cnt[d]++;
			else if (!vis[u + i][v + j]) dfs(u + i, v + j, d);
		}
	}
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) a[i][j] = s[j] == '*';
	}
	int d = 0;
	FOR(i, 0, n) FOR(j, 0, m) if (!vis[i][j] && !a[i][j]) dfs(i, j, d++);
	while (k--) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		printf("%d\n", cnt[com[x][y]]);
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