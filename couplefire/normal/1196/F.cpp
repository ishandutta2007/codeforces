#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<pair<int, pair<int, int>>> e;
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		--x, --y;
		e.push_back(make_pair(w, make_pair(x, y)));
	}
	sort(e.begin(), e.end());
	
	vector<int> vert;
	for (int i = 0; i < min(m, k); ++i) {
		vert.push_back(e[i].second.first);
		vert.push_back(e[i].second.second);
	}
	sort(vert.begin(), vert.end());
	vert.resize(unique(vert.begin(), vert.end()) - vert.begin());
	int cntv = vert.size();
	vector<vector<long long>> dist(cntv, vector<long long>(cntv, INF64));
	for (int i = 0; i < cntv; ++i) dist[i][i] = 0;
	
	for (int i = 0; i < min(m, k); ++i) {
		int x = lower_bound(vert.begin(), vert.end(), e[i].second.first) - vert.begin();
		int y = lower_bound(vert.begin(), vert.end(), e[i].second.second) - vert.begin();
		dist[x][y] = dist[y][x] = min(dist[x][y], (long long)e[i].first);
	}
	
	for (int z = 0; z < cntv; ++z) {
		for (int x = 0; x < cntv; ++x) {
			for (int y = 0; y < cntv; ++y) {
				dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);
			}
		}
	}
	
	vector<long long> res;
	for (int i = 0; i < cntv; ++i) {
		for (int j = 0; j < i; ++j) {
			res.push_back(dist[i][j]);
		}
	}
	
	sort(res.begin(), res.end());
	cout << res[k - 1] << endl;
	
	return 0;
}