#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 410000;
const int inf = 1 << 30;
vector<int> G[maxn];
struct edge {
	int from, to, weight;
	edge() {}
	edge(int from, int to, int weight) : from(from), to(to), weight(weight){}
};
int p[maxn];
int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
bool operator< (edge A, edge B) {
	return A.weight < B.weight;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i <= n; ++i) {
			G[i].clear();
			p[i] = i;
		}
		vector<edge> edges;
		for (int i = 0; i < m; ++i) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			edges.emplace_back(x, y, w);
		}
		sort(edges.begin(), edges.end());
		int tot = n;
		for (int i = 0; i < edges.size(); ++i) if (edges[i].weight <= k) {
			int a = edges[i].from, b = edges[i].to;
			int x = find(a), y = find(b);
			if (x != y) {
				tot -= 1;
				p[x] = y;
			}
		}
		if (tot == 1) {
			long long ans = inf;
			for (auto [x, y, w] : edges)
				ans = min(ans, llabs((long long)w - k));
			printf("%lld\n", ans);
			continue;
		}
		long long ans = 0;
		for (int i = 0; i < edges.size(); ++i) if (edges[i].weight > k) {
			int a = edges[i].from, b = edges[i].to;
			int x = find(a), y = find(b);
			if (x != y) {
				ans += llabs(edges[i].weight - k);
				p[x] = y;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}