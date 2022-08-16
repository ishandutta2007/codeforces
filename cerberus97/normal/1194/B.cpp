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
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		for (auto &row : grid) {
			cin >> row;
		}
		vector<int> rctr(n, 0), cctr(m, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				rctr[i] += grid[i][j] == '*';
			}
		}
		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				cctr[j] += grid[i][j] == '*';
			}
		}
		int ans = n + m - 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int cand = (n + m - 1) - (rctr[i] + cctr[j] - (grid[i][j] == '*'));
				ans = min(ans, cand);
			}
		}
		cout << ans << '\n';
	}
}