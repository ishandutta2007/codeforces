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
int n, m;
vi adj1[maxn];
vi adj2[maxn];
vi tmp;
int vis1[maxn];
int vis2[maxn];
int iscyc;

void dfs1(int u) {
	vis1[u] = 1;
	tmp.push_back(u);
	FOR(i, 0, sz(adj1[u])) {
		int v = adj1[u][i];
		if (!vis1[v]) dfs1(v);
	}
}

void dfs2(int u) {
	vis2[u] = 1;
	FOR(i, 0, sz(adj2[u])) {
		int v = adj2[u][i];
		if (vis2[v] == 1) iscyc = 1;
		if (!vis2[v]) dfs2(v);
	}
	vis2[u] = 2;
}

void solve() {
	ms(vis1, 0); ms(vis2, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {int a, b; scanf("%d%d", &a, &b); a--; b--; adj1[a].push_back(b); adj1[b].push_back(a); adj2[a].push_back(b);}
	int ans = 0;
	FOR(i, 0, n) if (!vis1[i]) {
		tmp.clear();
		dfs1(i);
		iscyc = 0;
		FOR(j, 0, sz(tmp)) {
			int u = tmp[j];
			if (!vis2[u]) dfs2(u);
		}
		ans += sz(tmp) + iscyc - 1;
	}
	printf("%d", ans);
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