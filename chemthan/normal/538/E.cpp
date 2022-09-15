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

const int maxn = 200010;
int n;
vi adj[maxn];
int d[maxn];
int res[maxn];

void dfs(int u) {
	if (sz(adj[u])) d[u] = 0; else d[u] = 1;
	FOR(i, 0, sz(adj[u])) {int v = adj[u][i]; dfs(v); d[u] += d[v];}
}

void run(int u, bool p) {
	if (!sz(adj[u])) {res[u] = 1; return;}
	if (p) {res[u] = INT_MIN; FOR(i, 0, sz(adj[u])) {int v = adj[u][i]; run(v, !p); res[u] = max(res[u], d[u] - d[v] + res[v]);}}
	else {res[u] = 1; FOR(i, 0, sz(adj[u])) {int v = adj[u][i]; run(v, !p); res[u] += res[v] - 1;}}
}

void run2(int u, bool p) {
	if (!sz(adj[u])) {res[u] = 1; return;}
	if (p) {res[u] = 0; FOR(i, 0, sz(adj[u])) {int v = adj[u][i]; run2(v, !p); res[u] += res[v];}}
	else {res[u] = INT_MAX; FOR(i, 0, sz(adj[u])) {int v = adj[u][i]; run2(v, !p); res[u] = min(res[u], res[v]);}}
}

void solve() {
	scanf("%d", &n);
	int u, v;
	FOR(i, 0, n - 1) {scanf("%d%d", &u, &v); u--; v--; adj[u].push_back(v);}
	dfs(0);
	run(0, true); printf("%d ", res[0]);
	run2(0, true); printf("%d", res[0]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}