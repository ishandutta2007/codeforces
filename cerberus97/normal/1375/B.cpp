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
		vector<vector<int>> a(n, vector<int>(m));
		for (auto& r : a) {
			for (auto& i : r) {
				cin >> i;
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int nb = 4 - (i == 0 or i == (n - 1)) - (j == 0 or j == (m - 1));
				if (a[i][j] > nb) {
					ok = false;
				} else {
					a[i][j] = nb;
				}
			}
		}
		if (ok) {
			cout << "YES\n";
			for (auto& r : a) {
				for (auto& i : r) {
					cout << i << ' ';
				}
				cout << '\n';
			}
		} else {
			cout << "NO\n";
		}
	}
}