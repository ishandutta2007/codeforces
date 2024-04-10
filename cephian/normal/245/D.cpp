#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int m[n][n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i][j];

	for (int r = 0; r < n; ++r) {
		int original = 0;
		for (int c = 0; c < n; ++c) {
			if (c != r)
				original |= m[r][c];
		}
		cout << original;
		if (r == n - 1)
			cout << "\n";
		else
			cout << " ";
	}

	return 0;
}