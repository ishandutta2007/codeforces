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

void fail();

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<pii> ans;
	vector<vector<pii>> stk(4);
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {
			continue;
		} else if (a[i] == 1) {
			ans.pb({i + 1, i + 1});
			stk[1].pb({i + 1, i + 1});
		} else if (a[i] == 2) {
			if (stk[1].empty()) {
				fail();
			}
			int r = stk[1].back().first;
			stk[1].pop_back();
			ans.pb({r, i + 1});
			stk[2].pb({r, i + 1});
		} else {
			bool ok = false;
			for (int j = 3; j >= 1; --j) {
				if (!stk[j].empty()) {
					ok = true;
					int r, c;
					tie(r, c) = stk[j].back();
					stk[j].pop_back();
					ans.pb({i + 1, i + 1});
					ans.pb({i + 1, c});
					stk[3].pb({i + 1, i + 1});
					break;
				}
			}
			if (!ok) {
				fail();
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto& [r, c] : ans) {
		cout << r << ' ' << c << '\n';
	}
}

void fail() {
	cout << -1 << '\n';
	exit(0);
}