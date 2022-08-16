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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<vector<int>> s(n);
	vector<int> mns, mxs;
	ll ans = 0, cnt = n;
	for (auto& a : s) {
		int sz; cin >> sz;
		a.resize(sz);
		int mn = inf, mx = -inf;
		bool here = 0;
		for (auto& i : a) {
			cin >> i;
			if (mn < i) {
				here = true;
			}
			mn = min(mn, i);
			mx = max(mx, i);
		}
		if (here) {
			ans += 2 * cnt - 1;
			--cnt;
		} else {
			mns.pb(mn);
			mxs.pb(mx);
		}
	}
	sort(mns.begin(), mns.end());
	sort(mxs.begin(), mxs.end());
	int p = 0;
	for (auto &mx : mxs) {
		while (p < mns.size() and mns[p] < mx) {
			++p;
		}
		ans += p;
	}
	cout << ans << '\n';
}