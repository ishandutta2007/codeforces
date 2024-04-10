#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, q, s;

int tot;

int child[N][2];

vector<pair<int, int>> adj[N];

const bool DOWN = true;
const bool UP = false;

int build(int l, int r, bool SIGN) {
	if (l == r) {
		return l;
	} else {
		int cur = tot++;
		int mid = (l + r) / 2;
		child[cur][0] = build(l, mid, SIGN);
		child[cur][1] = build(mid + 1, r, SIGN);
		for (int c = 0; c < 2; c++) {
			if (SIGN == DOWN) adj[cur].push_back({child[cur][c], 0});
			if (SIGN == UP) adj[child[cur][c]].push_back({cur, 0});
		}
		return cur;
	}
}

vector<int> nodes;

void get_node(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		nodes.push_back(x);
		return ;
	} else if (r < ql || qr < l) return ;
		// cout << x << " " << l << " " << r << " " << ql << " " << qr << endl;
	int mid = (l + r) / 2;
	get_node(child[x][0], l, mid, ql, qr);
	get_node(child[x][1], mid + 1, r, ql, qr);
}

int main() {
	scanf("%d %d %d", &n, &q, &s);
	s--;
	tot = n;
	int dr = build(0, n - 1, DOWN), ur = build(0, n - 1, UP);
	for (int i = 0; i < q; i++) {
		int t, u, v, w, l, r;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &u, &v, &w);
			--u, --v;
			adj[u].push_back({v, w});
		} else if (t == 2) {
			scanf("%d %d %d %d", &v, &l, &r, &w);
			--v, --l, --r;
			nodes.clear();
			get_node(dr, 0, n - 1, l, r);
			for (auto vv : nodes) {
				adj[v].push_back({vv, w});
			}
		} else {
			scanf("%d %d %d %d", &v, &l, &r, &w);
			--v, --l, --r;
			nodes.clear();
			get_node(ur, 0, n - 1, l, r);
			for (auto vv : nodes) {
				adj[vv].push_back({v, w});
			}
		}
	}
	static long long dist[N];
	static bool visit[N];
	const long long INF = 1LL << 60;
	vector<int> queue;
	fill(dist, dist + tot, INF);
	fill(visit, visit + tot, false);
	queue.push_back(s);
	visit[s] = true;
	dist[s] = 0;
	for (int head = 0; head < (int)queue.size(); head++) {
		int u = queue[head];
		visit[u] = false;
		for (auto e : adj[u]) {
			int v = e.first, w = e.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!visit[v]) {
					visit[v] = 1;
					queue.push_back(v);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%lld%c", dist[i] == INF ? -1 : dist[i], i + 1 == n ? '\n' : ' ');
	}
	return 0;
}