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
#define EPS 1e-7
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 410;
int n, m;
int g[maxn][maxn];
int d[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		g[u][v] = g[v][u] = 1;
	}
	ms(d, 0x3f); d[0] = 0;
	queue<int> q; q.push(0);
	while (sz(q)) {
		int u = q.front(); q.pop();
		FOR(i, 0, n) if (g[i][u] && d[i] > d[u] + 1) {
			d[i] = d[u] + 1;
			q.push(i);
		}
	}
	int d1 = d[n - 1];
	if (d1 == 0x3f3f3f3f) {printf("-1"); return;}
	ms(d, 0x3f); d[0] = 0;
	q.push(0);
	while (sz(q)) {
		int u = q.front(); q.pop();
		FOR(i, 0, n) if (!g[i][u] && d[i] > d[u] + 1) {
			d[i] = d[u] + 1;
			q.push(i);
		}
	}
	int d2 = d[n - 1];
	if (d2 == 0x3f3f3f3f) {printf("-1"); return;}
	printf("%d", max(d1, d2));
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