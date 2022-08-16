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
	int n, m;
	cin >> n >> m;
	vector<pii> robbers(n), lights(m);
	for (auto& i : robbers) {
		cin >> i.first >> i.second;
	}
	for (auto& i : lights) {
		cin >> i.first >> i.second;
	}
	vector<pii> constraints;
	for (auto& [a, b] : robbers) {
		for (auto& [c, d] : lights) {
			if (a <= c and b <= d) {
				constraints.pb({c - a, d - b});
			}
		}
	}
	if (constraints.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	constraints.pb({-1, inf});
	constraints.pb({inf, -1});
	sort(constraints.begin(), constraints.end());
	reverse(constraints.begin(), constraints.end());
	int mx = -1;
	for (auto& [x, y] : constraints) {
		mx = max(mx, y);
		y = mx;
	}
	reverse(constraints.begin(), constraints.end());
	int ans = inf, sz = constraints.size();
	for (int i = 0; i < sz - 1; ++i) {
		ans = min(ans, constraints[i].first + 1 + constraints[i + 1].second + 1);
	}
	cout << ans << '\n';
}