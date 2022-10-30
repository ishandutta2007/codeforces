#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<pii> v;
	for (int i = 0; i < m; ++i) {
		pii p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	int mx = -1;
	for (unsigned int i = 0; i < v.size() - 1; ++i) {
		if (v[i + 1].first - v[i].first < abs(v[i].second - v[i + 1].second)) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}

		mx = max(mx,
				max(v[i + 1].second, v[i].second) + (v[i + 1].first - v[i].first - abs(v[i + 1].second - v[i].second)) / 2);
	}

	mx = max(v[0].second + v[0].first - 1, mx);
	mx = max(n - v[v.size() - 1].first + v[v.size() - 1].second, mx);
	cout << mx << "\n";

	return 0;
}