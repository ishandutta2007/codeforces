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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int m = 6;
	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
	}
	a.pb(inf);
	int n; cin >> n;
	vector<int> b(n);
	for (auto& i : b) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = inf;
	for (auto& i : b) {
		for (auto& j : a) {
			if (i < j) {
				continue;
			}
			int lo = i - j, hi = lo;
			if (b[0] < a[0] + lo) {
				continue;
			}
			for (int k = 0; k < m; ++k) {
				auto it = lower_bound(b.begin(), b.end(), a[k + 1] + lo);
				if (it != b.begin()) {
					int val = *prev(it);
					if (val >= a[k] + lo) {
						hi = max(hi, val - a[k]);
					}
				}
			}
			ans = min(ans, hi - lo);
		}
	}
	cout << ans << '\n';
}