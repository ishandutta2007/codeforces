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

const int N = 100 + 10, B = 30;

int a[N], use[N];

map<vector<int>, int> solve(int b, int n);

int main() {
	fast_cin();
	int n; cin >> n;
	int half = B / 2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		use[i] = (a[i] & ((1 << half) - 1));
	}
	auto m1 = solve(half, n);
	for (int i = 0; i < n; ++i) {
		use[i] = (a[i] >> half);
	}
	auto m2 = solve(B - half, n);
	for (auto &s1 : m1) {
		auto d = s1.first;
		for (auto &i : d) {
			i = -i;
		}
		if (m2.count(d)) {
			cout << ((s1.second) | (m2[d] << half)) << '\n';
			return 0;
		}
	}
	cout << -1 << endl;
}

map<vector<int>, int> solve(int b, int n) {
	map<vector<int>, int> ans;
	int tot = (1 << b);
	for (int mask = 0; mask < tot; ++mask) {
		vector<int> diff(n);
		int base = __builtin_popcount(use[0] ^ mask);
		for (int i = 0; i < n; ++i) {
			diff[i] = __builtin_popcount(use[i] ^ mask) - base;
		}
		if (!ans.count(diff)) {
			ans[diff] = mask;
		}
	}
	return ans;
}