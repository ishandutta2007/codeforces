#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<tuple>
using namespace std;
vector<tuple<long long, long long, long long>>x[10005]; long long n, m, L, s, t, a[10005], b[10005], c[10005]; pair<long long, long long>dist[10005];
pair<long long, vector<long long>> shortest_path() {
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>Q;
	for (int i = 0; i < 10005; i++)dist[i] = make_pair(1LL << 60, -1);
	Q.push(make_pair(0, s)); dist[s] = make_pair(0, -1);
	while (!Q.empty()) {
		long long a1 = Q.top().first, a2 = Q.top().second; Q.pop();
		for (tuple<long long, long long, long long>r : x[a2]) {
			long long to1 = get<0>(r), to2 = get<1>(r), dst = get<2>(r);
			if (dist[to1].first > a1 + dst) {
				dist[to1] = make_pair(a1 + dst, to2);
				Q.push(make_pair(dist[to1].first, to1));
			}
		}
	}
	long long r1 = dist[t].first;
	vector<long long>V1; int pos1 = t;
	while (pos1 != -1) {
		if (dist[pos1].second != -1)V1.push_back(dist[pos1].second);
		if (dist[pos1].second == -1)pos1 = -1;
		else if (b[dist[pos1].second] == pos1)pos1 = a[dist[pos1].second];
		else pos1 = b[dist[pos1].second];
	}
	reverse(V1.begin(), V1.end());
	return make_pair(r1, V1);
}
int main() {
	cin >> n >> m >> L >> s >> t;
	for (int i = 1; i <= m; i++)cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= m; i++) {
		if (c[i] >= 1) { x[a[i]].push_back(make_tuple(b[i], i, c[i])); x[b[i]].push_back(make_tuple(a[i], i, c[i])); }
		else { x[a[i]].push_back(make_tuple(b[i], i, 1LL << 40)); x[b[i]].push_back(make_tuple(a[i], i, 1LL << 40)); }
	}
	long long P1 = shortest_path().first;
	if (P1 < L) { cout << "NO" << endl; return 0; }
	while (true) {
		for (int i = 0; i <= n; i++)x[i].clear();
		for (int i = 1; i <= m; i++) {
			if (c[i] != 0) { x[a[i]].push_back(make_tuple(b[i], i, abs(c[i]))); x[b[i]].push_back(make_tuple(a[i], i, abs(c[i]))); }
			else { x[a[i]].push_back(make_tuple(b[i], i, 1)); x[b[i]].push_back(make_tuple(a[i], i, 1)); }
		}
		pair<long long, vector<long long>>P2 = shortest_path();
		if (P2.first > L) { cout << "NO" << endl; return 0; }
		bool OK = false;
		for (int i = 0; i < P2.second.size(); i++) {
			if (c[P2.second[i]] <= 0 && OK == false) {
				if (c[P2.second[i]] == 0)c[P2.second[i]] = -1;
				c[P2.second[i]] += -1LL * (L - P2.first); OK = true;
			}
			else if (c[P2.second[i]] <= 0 && c[P2.second[i]] >= -1)c[P2.second[i]] = -1;
		}
		for (int i = 1; i <= m; i++) { if (c[i] == 0)c[i] = (1LL << 30); }
		if (P2.first == L)break;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= m; i++) { if (c[i] == 0)c[i] = (1LL << 30); }
	for (int i = 1; i <= m; i++)cout << a[i] << ' ' << b[i] << ' ' << abs(c[i]) << endl;
	return 0;
}