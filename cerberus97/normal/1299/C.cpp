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

const int N = 1e6 + 10;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<pll> groups = {{0, 0}};
	for (int i = n - 1; i >= 0; --i) {
		ll sum = a[i], sz = 1;
		while (!groups.empty()) {
			auto g = groups.back();
			if ((sum + g.first) * sz < sum * (sz + g.second)) {
				sum += g.first;
				sz += g.second;
				groups.pop_back();
			} else {
				break;
			}
		}
		groups.pb({sum, sz});
	}
	cout << fixed << setprecision(15);
	reverse(groups.begin(), groups.end());
	for (auto& g : groups) {
		if (g.second == 0) {
			continue;
		}
		ld val = ld(g.first) / g.second;
		for (int i = 0; i < g.second; ++i) {
			cout << val << '\n';
		}
	}
}