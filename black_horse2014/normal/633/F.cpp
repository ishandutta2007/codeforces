#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef long double DB;
#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define X first
#define Y second
#define Error(x) cout << #x << " = " << x << endl
template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}
  
template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}
int n;
#define MX 123456
VI con[MX];
LL dp[2][MX], dia[MX], res, d[2][MX], d1[MX];
vector<LL> V;
int a[MX];
void DFS(int u, int par) {
	dp[0][u] = a[u];
	dp[1][u] = -1;
	d[0][u] = d[1][u] = -1;
	
	for (int i = 0; i < con[u].size(); i++) {
		int v = con[u][i];
		if (v == par) continue;
		DFS(v, u);
		if (dp[0][u] < dp[0][v] + a[u]) {
			dp[1][u] = dp[0][u], dp[0][u] = dp[0][v] + a[u];
		} else if (dp[0][u] == dp[0][v] + a[u]) {
			dp[1][u] = dp[0][u];
		} else {
			chkmax(dp[1][u], dp[0][v] + a[u]);
		}
		if (d[0][u] < dia[v]) {
			d[1][u] = d[0][u], d[0][u] = dia[v];
		} else if (d[0][u] == dia[v]) {
			d[1][u] = dia[v];
		} else {
			chkmax(d[1][u], dia[v]);
		}
	}
	V.clear();
	for (int i = 0; i < con[u].size(); i++) {
		int v = con[u][i];
		if (v == par) continue;
		V.pb(dp[0][v] + a[u]);
	}
	dia[u] = d[0][u];
	chkmax(dia[u], dp[0][u]);
	if (dp[1][u] >= 0) chkmax(dia[u],  dp[0][u] + dp[1][u] - a[u]);
	sort(all(V));
	reverse(all(V));
	for (int i = 0; i < con[u].size(); i++) {
		int v = con[u][i];
		if (v == par) continue;
		if (V.size() <= 2) {
			d1[v] = -1; continue;
		} else {
			if (dp[0][v] + a[u] == V[0]) {
				d1[v] = V[1] + V[2] - a[u];
			} else if (dp[0][v] + a[u] == V[1]) {
				d1[v] = V[0] + V[2] - a[u];
			} else d1[v] = V[0] + V[1] - a[u];
		}
	}
}
LL dd[MX], deep[MX];
void solve(int u, int par) {
	for (int i = 0; i < con[u].size(); i++) {
		int v = con[u][i];
		if (v == par) continue;
		LL tmp = dd[u];
		LL x;
		if (dp[0][v] == dp[0][u] - a[u]) x = dp[1][u];
		else x = dp[0][u];
		if (dia[v] == d[0][u]) chkmax(tmp, d[1][u]);
		else chkmax(tmp, d[0][u]);
		chkmax(tmp, d1[v]);
		tmp = max(max(0LL, x) + deep[u], tmp);
		chkmax(res, tmp + dia[v]);
		dd[v] = max(max(x - a[u], deep[u]) + a[u], tmp);
		deep[v] = max(x - a[u], deep[u]) + a[u];
		solve(v, u);
	}
}

int main() {

	scanf("%d", &n);
	
	for (int i = 0; i <= n; i++) con[i].clear();
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		con[u].pb(v);
		con[v].pb(u);
	}
	DFS(0, 0);
	res = 0;
	solve(0, 0);
	cout << res << endl;
	return 0;
}