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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> x(n), y(m);
		for (auto& i : x) {
			cin >> i;
		}
		for (auto& j : y) {
			cin >> j;
		}
		vector<vector<map<int, int>>> v(2, vector<map<int, int>>(max(n, m)));
		ll ans = 0;
		while (k--) {
			int px, py;
			cin >> px >> py;
			auto x_id = upper_bound(x.begin(), x.end(), px) - x.begin() - 1;
			auto y_id = upper_bound(y.begin(), y.end(), py) - y.begin() - 1;
			if (x[x_id] == px and y[y_id] == py) { // grid point
				continue;
			}
			if (x[x_id] == px) {
				++v[0][y_id][x_id];
			} else {
				++v[1][x_id][y_id];
			}
		}
		auto choose2 = [](ll val) {
			return (val * (val - 1)) / 2;
		};
		for (auto& v1 : v) {
			for (auto& mp : v1) {
				int tot = 0; ll sub = 0;
				for (auto& [key, val] : mp) {
					tot += val;
					sub += choose2(val);
				}
				ans += choose2(tot) - sub;
			}
		}
		cout << ans << '\n';
	}
}