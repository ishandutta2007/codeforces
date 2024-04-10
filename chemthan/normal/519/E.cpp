//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 100010;
int const dmax = 32;
int n, m;
vi adj[nmax];
int p[nmax][dmax];
int lv[nmax];
int size[nmax];
bool vis[nmax];
int cnt = 0, tin[nmax], tout[nmax];

void dfs(int i, int par = 0) {
	vis[i] = 1;
	tin[i] = cnt++;
	size[i] = 1;
	if (i == 0) lv[i] = 0; else lv[i] = lv[par] + 1;
	p[i][0] = par;
	for (int j = 1; 1 << j < n; j++) p[i][j] = p[p[i][j - 1]][j - 1];
	FOR(j, 0 , sz(adj[i])) if (!vis[adj[i][j]]) {dfs(adj[i][j], i); size[i] += size[adj[i][j]];}
	tout[i] = cnt++;
}

int lca(int u, int v) {
	if (lv[u] < lv[v]) swap(u, v);
	FORd(i, dmax, 0) if (lv[u] - (1 << i) >= lv[v]) u = p[u][i];
	if (u == v) return u;
	FORd(i, dmax, 0) if (p[u][i] != p[v][i]) {u = p[u][i]; v = p[v][i];}
	return p[u][0];
}

bool ancestor(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int up(int a, int b) {
	FORd(i, dmax, 0) if (!ancestor(p[a][i], b)) a = p[a][i];
	return a;
}

void solve() {
	ms(p, 0); ms(size, 0); ms(vis, 0);
	cin>>n;
	FOR(i, 0, n - 1) {int a, b; cin>>a>>b; a--; b--; adj[a].push_back(b); adj[b].push_back(a);}
	dfs(0);
	cin>>m;
	while (m--) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		int z = lca(x, y);
		if (x == y) {cout<<n<<"\n"; continue;}
		if ((lv[x] + lv[y]) % 2 == 1) {cout<<0<<"\n"; continue;}
		if (lv[x] == lv[y]) {
			x = up(x, z); y = up(y, z);
			cout<<n - size[x] - size[y]<<"\n"; continue;
		}
		int dist = (lv[x] + lv[y]) / 2 - lv[z];
		if (lv[x] < lv[y]) swap(x, y);
		int to = x;
		FORd(i, dmax, 0) if (lv[x] - lv[p[to][i]] < dist) to = p[to][i];
		cout<<size[p[to][0]] - size[to]<<"\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}