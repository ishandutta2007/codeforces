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
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		++mp[a];
	}
	vector<pii> vals;
	vals.reserve(mp.size());
	for (auto& p : mp) {
		vals.pb({p.second, p.first});
	}
	sort(vals.begin(), vals.end());
	int br = 0, bc = 0, p = 0, sz = vals.size(), sum = 0;
	for (int r = 1; r <= sz; ++r) {
		while (p < sz and vals[p].first <= r) {
			sum += vals[p++].first;
		}
		int c = (sum + r * (sz - p)) / r;
		if (c >= r and r * c > br * bc) {
			br = r; bc = c;
		}
	}
	reverse(vals.begin(), vals.end());
	vector<int> use;
	use.reserve(n);
	for (auto& v : vals) {
		v.first = min(v.first, br);
		for (int i = 0; i < v.first; ++i) {
			use.pb(v.second);
		}
	}
	p = 0;
	vector<vector<int>> ans(br, vector<int>(bc, 0));
	for (int d = 0; d < bc; ++d) {
		for (int r = 0; r < br; ++r) {
			int c = (r + d) % bc;
			ans[r][c] = use[p++];
		}
	}
	cout << br * bc << '\n' << br << ' ' << bc << '\n';
	for (int r = 0; r < br; ++r) {
		for (int c = 0; c < bc; ++c) {
			cout << ans[r][c] << ' ';
		}
		cout << '\n';
	}
}