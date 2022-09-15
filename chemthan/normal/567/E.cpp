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

const int maxn = 100010;
int n, m, s, t;
int from[maxn], to[maxn], len[maxn];
vii adj[maxn];
vii radj[maxn];
ll d[maxn];
ll rd[maxn];
map<pair<int, int>, bool> mp;
map<pair<pair<int, int>, ll>, int> cn;

int E, edge[2 * maxn], last[2 * maxn], next[2 * maxn];
int num[2 * maxn], low[2 * maxn];
int p[2 * maxn];
int cnt;
void init() {
	E = 0; ms(last, -1);
	ms(num, 0); ms(low, 0); ms(p, -1); cnt = 0;
}
void add(int from, int to) {
	edge[E] = to; next[E] = last[from]; last[from] = E++;
	edge[E] = from; next[E] = last[to]; last[to] = E++;
}
void dfs(int u) {
	num[u] = low[u] = cnt++;
	for (int e = last[u]; e != -1; e = next[e]) {
		int v = edge[e];
		if (!num[v]) {
			p[v] = u; dfs(v);
			if (low[v] > num[u]) {
				if (mp.count(make_pair(u, v))) mp[make_pair(u, v)] = 1;
				if (mp.count(make_pair(v, u))) mp[make_pair(v, u)] = 1;
			}
			low[u] = min(low[u], low[v]);
		}
		else if (v != p[u]) low[u] = min(low[u], num[v]);
	}
}

void dijkstra() {
	FOR(i, 0, maxn) d[i] = _I64_MAX / 3;
	priority_queue<pair<ll, ll> > pq; pq.push(make_pair(0, s)); d[s] = 0;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].first;
			if (d[v] > d[u] + adj[u][i].second) {d[v] = d[u] + adj[u][i].second; pq.push(make_pair(-d[v], v));}
		}
	}
}

void rdijkstra() {
	FOR(i, 0, maxn) rd[i] = _I64_MAX / 3;
	priority_queue<pair<ll, ll> > pq; pq.push(make_pair(0, t)); rd[t] = 0;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		FOR(i, 0, sz(radj[u])) {
			int v = radj[u][i].first;
			if (rd[v] > rd[u] + radj[u][i].second) {rd[v] = rd[u] + radj[u][i].second; pq.push(make_pair(-rd[v], v));}
		}
	}
}

void solve() {
	scanf("%d%d%d%d", &n, &m, &s, &t); s--; t--;
	FOR(i, 0, m) {
		int a, b, l; scanf("%d%d%d", &a, &b, &l); a--; b--;
		from[i] = a; to[i] = b; len[i] = l;
		adj[a].push_back(make_pair(b, l));
		radj[b].push_back(make_pair(a, l));
	}
	dijkstra(); rdijkstra();
	init();
	FOR(i, 0, m) {
		int u = from[i];
		int v = to[i];
		int l = len[i];
		if (d[u] + l + rd[v] == d[t]) add(u, v);
		mp[make_pair(u, v)] = 0;
		cn[make_pair(make_pair(u, v), l)]++;
	}
	dfs(s);
	FOR(i, 0, m) {
		int u = from[i];
		int v = to[i];
		int l = len[i];
		ll dis = d[u] + l + rd[v] - d[t];
		if (dis == 0 && mp[make_pair(u, v)] && cn[make_pair(make_pair(u, v), l)] == 1) {printf("YES\n"); continue;}
		if (l > dis + 1) printf("CAN %I64d\n", dis + 1); else printf("NO\n");
	}
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