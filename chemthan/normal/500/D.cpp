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

const int maxn = 100010;
int n;
vii adj[maxn];
int d[maxn];
int fi[maxn];
int la[maxn];
int size[maxn];
bool vis[maxn];

void dfs(int u) {
	vis[u] = 1;
	size[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].first;
		if (!vis[v]) {dfs(v); size[u] += size[v];}
	}
}

void solve() {
	ms(vis, 0);
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int a, b, l; scanf("%d%d%d", &a, &b, &l); a--; b--;
		adj[a].push_back(make_pair(b, i));
		adj[b].push_back(make_pair(a, i));
		d[i] = l; fi[i] = a; la[i] = b;
	}
	dfs(0);
	ld ans = 0;
	FOR(i, 0, n - 1) {
		int k = min(size[fi[i]], size[la[i]]);
		ans += 1.0 * d[i] * k * (n - k) * 6 / n / (n - 1);
	}
	int q; scanf("%d", &q);
	while (q--) {
		int r, w; scanf("%d%d", &r, &w); r--;
		int diff = d[r] - w;
		d[r] = w;
		int k = min(size[fi[r]], size[la[r]]);
		ans -= 1.0 * diff * k * (n - k) * 6 / n / (n - 1);
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}
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