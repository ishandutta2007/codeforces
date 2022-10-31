#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int dist[2][100][10000];

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<string> grid;
	vector<vector<int> > vls;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		grid.push_back(s);
		for (int p = 0; p < 2; ++p)
			for (int j = 0; j < m; ++j)
				dist[p][i][j] = INF;
	}

	for (int r = 0; r < n; ++r) {

		int left = -INF;
		int right = INF;
		for (int c = 0; c < 2 * m; ++c) {
			if (grid[r][c % m] == '1')
				left = c;
			if (left != -INF)
				dist[0][r][c % m] = c - left;

			int c2 = (2 * m - 1 - c);
			if (grid[r][c2 % m] == '1')
				right = c2;
			if (right != INF)
				dist[1][r][c2 % m] = right - c2;
		}
	}

	int ans = INF;
	for (int c = 0; c < m; ++c) {
		int sum = 0;
		for (int r = 0; r < n; ++r) {
			int md = min(dist[0][r][c], dist[1][r][c]);
			if (md == INF)
				goto skip;
			sum += md;
		}
		ans = min(sum, ans);
	}
	cout << ans << "\n";
	return 0;
	skip: ;
	cout << "-1\n";

	return 0;
}