//started coding on 1.45pm;
#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

long long dis[N], a[N];
vector<pair<int, long long> > adj[N];
struct node {
	int v;
	long long w;
	node(int v, long long w) : v(v), w(w) {}
	bool operator < (const node &rhs) const {
		return w > rhs.w;
	}
};

void SSSP(int src, int n) {
	memset(dis, -1, sizeof dis);
	priority_queue<node> pq;
	pq.push(node(src, 0));
	while (!pq.empty()) {
		node e = pq.top();
		pq.pop();
		if (~dis[e.v]) continue;
		dis[e.v] = e.w;
		for (auto f : adj[e.v]) pq.push(node(f.first, f.second + dis[e.v]));
	}
}
		
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long w; cin >> u >> v >> w;
		w *= 2;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[0].push_back(make_pair(i, a[i]));
	}
	SSSP(0, n);
	for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];
	return 0;
}
//ended coding on 1.51pm;