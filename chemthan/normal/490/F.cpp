#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 6010;
int n;
int r[maxn];
vi adj[maxn];
int p[maxn];
int d[maxn];
int ans;

void dfs(int u) {
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (p[u] != v) {
			int k = lower_bound(d, d + n, r[v]) - d;
			ans = max(ans, k);
			int tmp = d[k];
			d[k] = r[v];
			p[v] = u; dfs(v);
			d[k] = tmp;
		}
	}
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", r + i);
	FOR(i, 0, n - 1) {int a, b; scanf("%d%d", &a, &b); a--; b--; adj[a].push_back(b); adj[b].push_back(a);}
	ans = 0; ms(d, 0x3f);
	FOR(i, 0, n) {p[i] = -1; d[0] = r[i]; dfs(i);}
	printf("%d", ans + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}