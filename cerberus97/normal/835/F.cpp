/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;
const ll inf = 1e16;

vector <pll> g[N];
vector <int> cycle;
stack <int> stk;
bool seen[N], cycle_node[N];
ll dist[N], d[N], weight[2 * N];
pll tree1[8 * N], tree2[8 * N];

bool find_cycle(int cur, int p);
ll get_diameter(int cur);
int bfs(int cur);
void reset_seen(int cur);
void build(pll* tree, int i, int l, int r);
void update(pll* tree, int i, int l, int r, int p, ll x);
pll query(pll* tree, int i, int l, int r, int ql, int qr);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int u, v; ll l;
		scanf("%d%d%lld", &u, &v, &l);
		g[u].pb({v, l});
		g[v].pb({u, l});
	}

	find_cycle(1, -1);
	memset(seen, 0, sizeof(seen));
	ll fix_dtr = 0;
	for (auto &i : cycle) {
		fix_dtr = max(fix_dtr, get_diameter(i));
		// cout << i << ' ' << fix_dtr << ' ' << d[i] << endl;
	}

	int c = cycle.size();
	// cout << "here" << endl;
	build(tree1, 1, 0, 2 * c);
	build(tree2, 1, 0, 2 * c);
	for (int i = 0; i < 2 * c; ++i) {
		update(tree1, 1, 0, 2 * c, i,  weight[i] + d[cycle[i % c]]);
		update(tree2, 1, 0, 2 * c, i, -weight[i] + d[cycle[i % c]]);
		for (auto &j : g[cycle[i % c]]) {
			if (j.first == cycle[(i + 1) % c]) {
				weight[i + 1] = weight[i] + j.second;
				break;
			}
		}
	}

	ll ans = inf;
	for (int i = 0; i < c; ++i) {
		// cout << i << ' ' << query(1, 0, 2 * c, i + 1, i + c - 1) - weight << endl;
		// ans = min(ans, query(1, 0, 2 * c, i + 1, i + c - 1) - weight);
		int k   = query(tree1, 1, 0, 2 * c, i, i + c - 1).second;
		ll temp = query(tree1, 1, 0, 2 * c, k + 1, i + c - 1).first - weight[k] + d[cycle[k % c]];
		temp    = max(query(tree2, 1, 0, 2 * c, i, k - 1).first + weight[k] + d[cycle[k % c]], temp);
		// cout << cycle[i] << " " << temp << endl;
		ans = min(ans, temp);
	}

	printf("%lld", max(ans, fix_dtr));
	// cout << max(ans, fix_dtr) << endl;
}

bool find_cycle(int cur, int p) {
	seen[cur] = true;
	stk.push(cur);
	for (auto &i : g[cur]) {
		if (i.first == p) {
			continue;
		} else if (!seen[i.first]) {
			if (find_cycle(i.first, cur)) {
				return true;
			}
		} else {
			while (true) {
				cycle_node[stk.top()] = true;
				cycle.pb(stk.top());
				stk.pop();
				if (cycle.back() == i.first) {
					break;
				}
			}

			return true;
		}
	}

	stk.pop();
	return false;
}

ll get_diameter(int cur) {
	cycle_node[cur] = false;
	int furthest = bfs(cur);
	d[cur] = dist[furthest];
	reset_seen(cur);
	ll ans = dist[bfs(furthest)];
	reset_seen(cur);
	cycle_node[cur] = true;
	return ans;
}

int bfs(int cur) {
	int ans = cur;
	dist[cur] = 0;
	seen[cur] = true;
	queue <int> q;
	q.push(cur);
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (auto &j : g[i]) {
			if (!seen[j.first] and !cycle_node[j.first]) {
				dist[j.first] = dist[i] + j.second;
				seen[j.first] = true;
				q.push(j.first);
				if (dist[j.first] > dist[ans]) {
					ans = j.first;
				}
			}
		}
	}

	return ans;
}

void reset_seen(int cur) {
	seen[cur] = false;
	for (auto &i : g[cur]) {
		if (seen[i.first]) {
			reset_seen(i.first);
		}
	}
}

void build(pll* tree, int i, int l, int r) {
	tree[i] = {-inf, 0};
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	build(tree, 2 * i, l, mid);
	build(tree, 2 * i + 1, mid + 1, r);
}

void update(pll* tree, int i, int l, int r, int p, ll x) {
	if (x > tree[i].first) {
		tree[i] = {x, p};
	}

	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	if (p <= mid) {
		update(tree, 2 * i, l, mid, p, x);
	} else {
		update(tree, 2 * i + 1, mid + 1, r, p, x);
	}
}

pll query(pll* tree, int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return {-inf, 0};
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2;
		pll lt = query(tree, 2 * i, l, mid, ql, qr);
		pll rt = query(tree, 2 * i + 1, mid + 1, r, ql, qr);
		return max(lt, rt);
	}
}