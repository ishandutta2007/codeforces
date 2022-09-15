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
vi adj[maxn];
bool vis[maxn];
int d[maxn];
int cnt[2];

void dfs(int u) {
	cnt[d[u]]++;
	vis[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (!vis[v]) {d[v] = (d[u] + 1) % 2; dfs(v);}
		else if (d[u] == d[v]) {printf("0 1"); exit(0);}
	}
}

void solve() {
	ms(vis, 0); ms(d, 0);
	scanf("%d%d", &n, &m);
	int a, b;
	FOR(i, 0, m) {
		scanf("%d%d", &a, &b); a--; b--;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	ll ans = 0;
	FOR(i, 0, n) if (!vis[i]) {
		cnt[0] = cnt[1] = 0; dfs(i);
		ans += 1LL * cnt[0] * (cnt[0] - 1) / 2 + 1LL * cnt[1] * (cnt[1] - 1) / 2;
	}
	if (ans) {printf("1 %I64d", ans); return;}
	FOR(i, 0, n) if (sz(adj[i])) ans += n - 2;
	if (ans) {printf("2 %I64d", ans / 2); return;}
	printf("3 %I64d", 1LL * n * (n - 1) * (n - 2) / 6);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}