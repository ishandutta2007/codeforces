#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;

bool bounds(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> n;
	string grid[n];
	vector<pair<int, int>> pieces;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
		for (int j = 0; j < n; ++j)
			if (grid[i][j] == 'o') {
				pieces.push_back(make_pair(i, j));
			}
	}

	bool marked[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (grid[i][j] == 'x')
				marked[i][j] = false;
			else
				marked[i][j] = true;

	vector<pair<int, int> > all;
	for (int dx = -n + 1; dx < n; ++dx) {
		for (int dy = -n + 1; dy < n; ++dy) {
			bool ok = true;

			for (auto p : pieces) {
				int x = p.first + dx;
				int y = p.second + dy;
				if (bounds(x, y)) {
					if (grid[x][y] == '.') {
						ok = false;
						break;
					}
				}
			}

			if (ok) {
//				cout << dx << ", " << dy << endl;
				for (auto p : pieces) {
					int x = p.first + dx;
					int y = p.second + dy;
					if (bounds(x, y))
						marked[x][y] = true;
				}
				all.push_back(make_pair(dx, dy));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!marked[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < 2 * n - 1; ++j) {
			if (i == n - 1 && j == n - 1) {
				cout << "o";
			} else {

				bool ex = false;
				for (auto d : all) {
					if (i - d.first == j - d.second && i - d.first == n - 1) {
						ex = true;
						break;
					}
				}
				if (ex)
					cout << "x";
				else
					cout << ".";
			}

		}
		cout << "\n";
	}

	return 0;
}