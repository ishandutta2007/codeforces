/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<string> grid(n);
		vector<vector<vector<pii>>> groups(3, vector<vector<pii>>(2));
		for (auto& r : grid) {
			cin >> r;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int m = (i + j) % 3;
				if (grid[i][j] == 'X') {
					groups[m][0].pb({i, j});
				} else if (grid[i][j] == 'O') {
					groups[m][1].pb({i, j});
				}
			}
		}
		sort(groups.begin(), groups.end(), [&] (vector<vector<pii>>& v1, vector<vector<pii>>& v2) {
			int s1 = v1[0].size() + v1[1].size();
			int s2 = v2[0].size() + v2[1].size();
			return s1 < s2;
		});
		int c1 = groups[0][1].size() + groups[1][0].size();
		int c2 = groups[0][0].size() + groups[1][1].size();
		int pick = (c1 < c2 ? 1 : 0);
		for (int m = 0; m < 2; ++m) {
			for (int c = 0; c < 2; ++c) {
				if ((m + c) % 2 == pick) {
					for (auto& [i, j] : groups[m][c]) {
						grid[i][j] ^= 'X' ^ 'O';
					}
				}
			}
		}
		for (auto& r : grid) {
			cout << r << '\n';
		}
	}
}