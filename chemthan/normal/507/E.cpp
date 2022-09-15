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
vii adj[maxn];
int d1[maxn];
int d2[maxn];
int p[maxn];
bool vis[maxn];
map<pi, int> mp;
map<pi, int> edge;
vector<pair<pair<int, int>, int> > ans;

void dfs(int u) {
	vis[u] = 1;
	while (sz(adj[u])) {
		int v = adj[u].back().first, k = adj[u].back().second; adj[u].pop_back();
		if (!edge[make_pair(u, v)]) {
			edge[make_pair(u, v)] = edge[make_pair(v, u)] = 1;
			if (mp[make_pair(u, v)] && k == 0) ans.push_back(make_pair(make_pair(u, v), 1));
			if (!mp[make_pair(u, v)] && k == 1) ans.push_back(make_pair(make_pair(u, v), 0));
			dfs(v);
		}
	}
}

void solve() {
	ms(d1, 0x3f); ms(d2, 0x3f); ms(p, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {int x, y, z; scanf("%d%d%d", &x, &y, &z); x--; y--; adj[x].push_back(make_pair(y, z)); adj[y].push_back(make_pair(x, z));}
	priority_queue<pair<pair<int, int>, int> > pq; pq.push(make_pair(make_pair(0, 0), 0)); d1[0] = d2[0] = 0;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].first;
			if (d1[v] > d1[u] + 1 || (d1[v] == d1[u] + 1 && d2[v] > d2[u] + 1 - adj[u][i].second)) {
				d1[v] = d1[u] + 1;
				d2[v] = d2[u] + 1 - adj[u][i].second;
				p[v] = u;
				pq.push(make_pair(make_pair(-d1[v], -d2[v]), v));
			}
		}
	}
	int k = n - 1; while (k != 0) {mp[make_pair(k, p[k])] = mp[make_pair(p[k], k)] = 1; k = p[k];}
	dfs(0);
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
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