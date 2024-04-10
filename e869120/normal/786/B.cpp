#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);

vector<pair<int, long long>>G[MAX_N]; vector<int> J;
int N, Q, S, sz = 1; long long dist[MAX_N];

void query_(int l, int r, int a, int b, int u) {
	if (l <= a && b <= r) { J.push_back(u); return; }
	if (r <= a || b <= l) return;
	query_(l, r, a, (a + b) >> 1, u * 2);
	query_(l, r, (a + b) >> 1, b, u * 2 + 1);
}

vector<int> get_range(int l, int r) {
	J.clear();
	query_(l, r, 0, sz, 1);
	return J;
}

void dijkstra() {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>que;
	for (int i = 1; i < sz * 4; i++) dist[i] = (1LL << 60);
	dist[sz + S] = 0; que.push(make_pair(0, sz + S));

	while (!que.empty()) {
		int pos = que.top().second; que.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			int to = G[pos][i].first; long long cost = G[pos][i].second;
			if (dist[to] > dist[pos] + cost) {
				dist[to] = dist[pos] + cost;
				que.push(make_pair(dist[to], to));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &Q, &S);
	while (sz <= N) sz *= 2;

	for (int i = 1; i <= Q; i++) {
		int ty, t1, t2, t3, t4;
		scanf("%d", &ty);
		if (ty == 1) { scanf("%d%d%d", &t1, &t2, &t3); G[t1 + sz].push_back(make_pair(t2 + sz, t3)); }
		if (ty == 2) {
			scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
			vector<int> E = get_range(t2, t3 + 1);
			for (int j = 0; j < E.size(); j++) { G[t1 + sz].push_back(make_pair(E[j], t4)); }
		}
		if (ty == 3) {
			scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
			vector<int> E = get_range(t2, t3 + 1);
			for (int j = 0; j < E.size(); j++) { G[E[j] + sz * 2].push_back(make_pair(t1 + sz, t4)); }
		}
	}
	for (int i = 1; i < sz; i++) { G[i].push_back(make_pair(i * 2, 0)); G[i].push_back(make_pair(i * 2 + 1, 0)); }
	for (int i = 1; i < sz * 2; i++) {
		int cx = i;
		while (cx >= 1) {
			G[i].push_back(make_pair(cx + sz * 2, 0));
			cx >>= 1;
		}
	}

	dijkstra();
	for (int i = 1; i <= N; i++) {
		if (i >= 2) printf(" ");
		if (dist[sz + i] == (1LL << 60)) printf("-1");
		else printf("%lld", dist[sz + i]);
	}
	printf("\n");
	return 0;
}