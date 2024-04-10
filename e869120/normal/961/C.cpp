#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int n, c[4][109][109], d[209][209], minx = (1 << 30);

int solve() {
	int s1 = 0;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (d[i][j] == (i + j) % 2) s1++;
		}
	}
	return min(4 * n*n - s1, s1);
}

int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				char cc; cin >> cc;
				if (cc == '0') c[i][j][k] = 0;
				else c[i][j][k] = 1;
			}
		}
	}
	int a[4] = { 0,1,2,3 };
	do {
		for (int i = 0; i < 4; i++) {
			int sx = i / 2, sy = i % 2; sx *= n; sy *= n;
			for (int j = sx; j < sx + n; j++) {
				for (int k = sy; k < sy + n; k++) {
					d[j][k] = c[a[i]][j - sx][k - sy];
				}
			}
		}
		minx = min(minx, solve());
	} while (next_permutation(a, a + 4));

	cout << minx << endl;
	return 0;
}