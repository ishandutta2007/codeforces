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

vector<pii> get_groups(vector<int>& c);
void add(vector<pii>& groups, int l, int r, vector<int>& op);
void do_op(vector<int>& c, vector<int> op);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> c(n);
	for (auto& i : c) {
		cin >> i;
	}
	vector<vector<int>> ops;
	while (true) {
		auto groups = get_groups(c);
		int sz = groups.size();
		if (sz == 1) {
			break;
		}
		int x = -1, y = -1;
		for (int i = 0; i < sz; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				if (groups[i].first == groups[j].second + 1) {
					x = i;
					y = j;
				}
			}
		}
		vector<int> op;
		add(groups, 0, x - 1, op);
		add(groups, x, x, op);
		add(groups, x + 1, y, op);
		add(groups, y + 1, sz - 1, op);
		do_op(c, op);
		ops.pb(op);
	}
	cout << ops.size() << '\n';
	for (auto& op : ops) {
		cout << op.size() << ' ';
		for (auto& i : op) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

vector<pii> get_groups(vector<int>& c) {
	vector<pii> ans;
	int n = c.size();
	for (int l = 0; l < n; ) {
		int sz = 1;
		for (int r = l + 1; r < n; ++r) {
			if (c[r] == c[r - 1] + 1) {
				++sz;
			} else {
				break;
			}
		}
		ans.pb({c[l], c[l] + sz - 1});
		l += sz;
	}
	return ans;
}

void add(vector<pii>& groups, int l, int r, vector<int>& op) {
	if (l <= r) {
		int sz = 0;
		for (int i = l; i <= r; ++i) {
			sz += groups[i].second - groups[i].first + 1;
		}
		op.pb(sz);
	}
}

void do_op(vector<int>& c, vector<int> op) {
	vector<int> ans;
	int n = c.size();
	reverse(op.begin(), op.end());
	for (auto& sz : op) {
		for (int j = n - sz; j < n; ++j) {
			ans.pb(c[j]);
		}
		n -= sz;
	}
	c = ans;
}