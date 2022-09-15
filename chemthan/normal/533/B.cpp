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

const int maxn = 200010;
int n;
int p[maxn];
int a[maxn];
vi adj[maxn];
ll d[2][maxn];

void dfs(int u) {
	ll sum = 0, dmin = INT_MAX;
	int flag1 = 0, flag2 = 0;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		dfs(v);
		if (d[0][v] < d[1][v]) flag1 ^= 1;
		else if (d[0][v] == d[1][v]) flag2 = 1;
		sum += max(d[0][v], d[1][v]);
		dmin = min(dmin, abs(d[0][v] - d[1][v]));
	}
	if (flag2) d[0][u] = d[1][u] = sum;
	else {
		d[flag1][u] = sum;
		d[flag1 ^ 1][u] = sum - dmin;
	}
	d[1][u] = max(d[1][u], d[0][u] + a[u]);
}

void solve() {
	ms(d, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d%d", p + i, a + i);
		if (i) {p[i]--; adj[p[i]].push_back(i);}
	}
	dfs(0);
	printf("%I64d", d[1][0]);
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