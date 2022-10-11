#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
int dist[300000], col[300000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
vector<int>X[300000];
void dijkstra(int s) {
	for (int i = 0; i < 300000; i++)dist[i] = 99999999;
	Q.push(make_pair(0, s)); dist[s] = 0;
	while (!Q.empty()) {
		int a1 = Q.top().first, a2 = Q.top().second; Q.pop();
		for (int i = 0; i < X[a2].size(); i++) {
			int to = X[a2][i], cost = 1; if (col[a2] == col[to])cost = 0;
			if (dist[to] > dist[a2] + cost) { dist[to] = dist[a2] + cost; Q.push(make_pair(dist[to], to)); }
		}
	}
}
int main() {
	int n; cin >> n; for (int i = 1; i <= n; i++)cin >> col[i];
	for (int i = 0; i < n - 1; i++) { int a, b; cin >> a >> b; X[a].push_back(b); X[b].push_back(a); }
	dijkstra(1); int maxn = -1, maxid = 0;
	for (int i = 1; i <= n; i++) { if (maxn < dist[i]) { maxn = dist[i]; maxid = i; } }
	int maxn2 = 0; dijkstra(maxid);
	for (int i = 1; i <= n; i++) { maxn = max(maxn, dist[i]); }
	cout << (maxn + 1) / 2 << endl;
	return 0;
}