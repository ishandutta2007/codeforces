#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

const int N = 1e3 + 7;
const long long INF = (1LL << 60);

int n, m,length, s, t;
std::vector<std::pair<int, int> > adj[N];
long long dist[N];
std::vector<std::pair<int, int> > zeros;

bool visit[N];
long long shortest(int s, int t, long long delta) {
	for (int i = 0; i < zeros.size(); i += 2) {
		int u = zeros[i].first;
		int v = zeros[i + 1].first;
		int tmp = std::min(delta, 0LL + length);
		delta -= tmp;
		adj[u][zeros[i].second].second = adj[v][zeros[i + 1].second].second = 1 + tmp;
	}
	std::vector<int> queue;
	std::fill(dist, dist + n, INF);
	std::fill(visit, visit + n, 0);
	queue.push_back(s);
	dist[s] = 0;
	visit[s] = 1;
	for (int head = 0; head < queue.size(); head++) {
		int u = queue[head];
		visit[u] = 0;
		for (auto e : adj[u]) {
			int v = e.first, cost = e.second;
			if (dist[u] + cost < dist[v]) {
				dist[v] = dist[u] + cost;
				if (!visit[v]) {
					queue.push_back(v);
					visit[v] = 1;
				}
			}
		}
	}
	return dist[t];
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &length, &s, &t);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(std::make_pair(v, w));
		adj[v].push_back(std::make_pair(u, w));
		if (w == 0) {
			zeros.push_back(std::make_pair(u, adj[u].size() - 1));
			zeros.push_back(std::make_pair(v, adj[v].size() - 1));
		}
	}
	long long l = 0, r = 1LL * length * zeros.size() / 2;
	while (l < r) {
		long long mid = l + r >> 1;
		if (shortest(s, t, mid) < length) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	if (shortest(s, t, l) != length) {
		puts("NO");
		return 0;
	}
	puts("Yes");
	for (int u = 0; u < n; u++) {
		for (auto e : adj[u]) {
			int v = e.first, cost = e.second;
			if (u > v) {
				continue;
			}
			printf("%d %d %d\n", u, v, cost);
		}
	}
	return 0;
}