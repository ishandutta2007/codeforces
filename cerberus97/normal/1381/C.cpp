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
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> b(n);
		vector<vector<int>> where(n + 2);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			where[b[i]].pb(i);
		}
		int extra = 1;
		while (!where[extra].empty()) {
			++extra;
		}
		vector<int> a(n, extra);
		priority_queue<pii> q;
		for (int i = 1; i <= n + 1; ++i) {
			q.push({where[i].size(), i});
		}
		for (int i = 0; i < x; ++i) {
			auto cur = q.top();
			q.pop();
			int val = cur.second;
			a[where[val].back()] = val;
			where[val].pop_back();
			q.push({where[val].size(), val});
		}
		int sum = 0;
		for (int i = 1; i <= n + 1; ++i) {
			sum += min(where[i].size(), (n - x) - where[i].size());
		}
		if (sum < y - x) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<pii> left;
		while (!q.empty()) {
			int val = q.top().second;
			q.pop();
			for (auto& id : where[val]) {
				left.pb({val, id});
			}
		}
		int p = 0, sz = left.size(), cnt_left = y - x;
		while (p < sz and left[0].first == left[p].first) {
			++p;
		}
		for (int i = 0; i < sz and cnt_left; ++i) {
			if (left[i].first != left[p].first) {
				a[left[p].second] = left[i].first;
				--cnt_left;
				p = (p + 1) % sz;
			}
		}
		for (auto& i : a) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}