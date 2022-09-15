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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1010;
int n, m;
int a[maxn][maxn];
char s[maxn];
ll f[3][maxn][maxn];

void go(int k) {
	queue<pair<pi, ll> > pq;
	FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == k) {
		pq.push(make_pair(make_pair(i, j), 0)); f[k][i][j] = 0;
	}
	while (sz(pq)) {
		int u = pq.front().first.first;
		int v = pq.front().first.second;
		pq.pop();
		FOR(i, -1, 2) FOR(j, -1, 2) if (i * j == 0 && i + j != 0 && u + i >= 0 && u + i < n && v + j >= 0 && v + j < m) {
			if (f[k][u + i][v + j] > f[k][u][v] + 1 && a[u + i][v + j] != 4) {
				pq.push(make_pair(make_pair(u + i, v + j), f[k][u][v] + 1));
				f[k][u + i][v + j] = f[k][u][v] + 1;
			}
		}
	}
	FOR(i, 0, n) FOR(j, 0, m) if (f[k][i][j] > 0 && f[k][i][j] < INF) f[k][i][j]--;
}

void solve() {
	FOR(i, 0, maxn) FOR(j, 0, maxn) f[0][i][j] = f[1][i][j] = f[2][i][j] = INF;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) {
			if (s[j] == '.') a[i][j] = 3;
			else if (s[j] == '#') a[i][j] = 4;
			else a[i][j] = s[j] - '0' - 1;
		}
	}
	FOR(i, 0, 3) go(i);
	ll d[] = {INF, INF, INF}, ans = INF;
	FOR(i, 0, n) FOR(j, 0, m) {
		ans = min(ans, f[0][i][j] + f[1][i][j] + f[2][i][j] + (a[i][j] == 3));
		d[0] = min(d[0], f[0][i][j] + f[1][i][j] + (a[i][j] == 3));
		d[1] = min(d[1], f[1][i][j] + f[2][i][j] + (a[i][j] == 3));
		d[2] = min(d[2], f[2][i][j] + f[0][i][j] + (a[i][j] == 3));
	}
	ans = min(ans, d[0] + d[1]);
	ans = min(ans, d[1] + d[2]);
	ans = min(ans, d[2] + d[0]);
	if (ans == INF) ans = -1;
	printf("%I64d", ans);
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