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
		int n, m;
		cin >> n >> m;
		int sz = n * m;
		vector<int> a(sz);
		for (auto& i : a) {
			cin >> i;
		}
		map<int, queue<int>> grps;
		for (int i = 0; i < sz; ++i) {
			grps[a[i]].push(i);
		}
		vector<vector<int>> seats(n, vector<int>(m, -1));
		int r = 0, c = 0;
		for (auto& [k, ids] : grps) {
			while (!ids.empty()) {
				int lc = min(c + int(ids.size()) - 1, m - 1);
				for (int j = lc; j >= c; --j) {
					seats[r][j] = ids.front();
					ids.pop();
				}
				c = lc + 1;
				if (c == m) {
					++r; c = 0;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < j; ++k) {
					ans += (seats[i][j] > seats[i][k]);
				}
			}
		}
		cout << ans << '\n';
	}
}