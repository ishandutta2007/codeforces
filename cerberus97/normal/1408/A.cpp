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
		vector<vector<int>> a(3, vector<int>(n));
		for (auto& i : a) {
			for (auto& j : i) {
				cin >> j;
			}
		}
		vector<int> p(n, -1);
		for (int i = 0; i < n; ++i) {
			int prv = p[(i + n - 1) % n];
			int nxt = p[(i + 1) % n];
			for (int j = 0; j < 3; ++j) {
				p[i] = a[j][i];
				if (!(p[i] == -1 or p[i] == prv or p[i] == nxt)) {
					break;
				}
			}
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
}