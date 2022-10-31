#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	bool grid[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			grid[i][j] = false;
	int amt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (amt < k && (i + j) % 2 == 0) {
				++amt;
				grid[i][j] = true;
			}
		}
	}
	if (amt != k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j])
					cout << "L";
				else
					cout << "S";
			}
			cout << "\n";
		}
	}
	return 0;
}