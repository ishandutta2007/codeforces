#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> field(n);
	for (int i = 0; i < n; ++i){ 
		field[i].resize(m, 0);
	}
	map<pair<int, int>, int> tmp; 
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		field[x][y] = 1;
		if (tmp.find(make_pair(x, y)) == tmp.end()) tmp[make_pair(x, y)] = i;
	}
	vector<pair<int, int>> res;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (field[i][j] == 1 && field[i][j + 1] == 1 && field[i + 1][j] == 1 && field[i + 1][j + 1] == 1) res.push_back(make_pair(i, j));
		}
	}
	if ((int) res.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	int min_ans = k;
	for (int i = 0; i < (int) res.size(); ++i) {
		int ans = max(tmp[make_pair(res[i].first, res[i].second)], tmp[make_pair(res[i].first, res[i].second + 1)]);
		ans = max(ans, tmp[make_pair(res[i].first + 1, res[i].second)]);
		ans = max(ans, tmp[make_pair(res[i].first + 1, res[i].second + 1)]); 
		if (ans < min_ans) min_ans = ans;
	}
	cout << min_ans + 1 << endl;


	return 0;
}