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

struct rect_t {
	pii interval[4];
	int id, sort_type;
	bool operator<(const rect_t &o) const {
		return interval[sort_type] < o.interval[sort_type];
	}
};

bool solve(vector<rect_t> all_rect);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<rect_t> all_rect;
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		rect_t rect;
		rect.id = i;
		rect.interval[0] = {a, c};
		rect.interval[1] = {-c, -a};
		rect.interval[2] = {b, d};
		rect.interval[3] = {-d, -b};
		all_rect.pb(rect);
	}
	if (solve(all_rect)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

bool solve(vector<rect_t> all_rect) {
	int n = all_rect.size();
	if (n <= 1) {
		return true;
	}
	vector<vector<rect_t>> copies(4, all_rect);
	vector<vector<int>> nxt(4, vector<int>(n + 1));
	set<int> del;
	vector<int> rt(4), ptr(4);
	for (int j = 0; j < 4; ++j) {
		// copies[j] = all_rect;
		for (auto &r : copies[j]) {
			r.sort_type = j;
		}
		for (int i = 0; i <= n; ++i) {
			nxt[j][i] = i;
		}
		sort(copies[j].begin(), copies[j].end());
	}
	while (n - del.size() > 1) {
		for (int j = 0; j < 4; ++j) {
			ptr[j] = nxt[j][0];
			while (del.count(copies[j][ptr[j]].id)) {
				ptr[j] = nxt[j][ptr[j] + 1];
			}
			nxt[j][0] = ptr[j];
			rt[j] = copies[j][ptr[j]].interval[j].second;
		}
		int k = n - del.size();
		bool done = false;
		for (int i = 1; i < k; ++i) {
			for (int j = 0; j < 4; ++j) {
				int temp = nxt[j][ptr[j] + 1];
				while (del.count(copies[j][temp].id)) {
					temp = nxt[j][temp + 1];
				}
				nxt[j][ptr[j] + 1] = temp;
				if (copies[j][temp].interval[j].first >= rt[j]) {
					vector<rect_t> recurse;
					ptr[j] = nxt[j][0];
					while (ptr[j] != temp) {
						recurse.pb(copies[j][ptr[j]]);
						del.insert(copies[j][ptr[j]].id);
						ptr[j] = nxt[j][ptr[j] + 1];
					}
					if (!solve(recurse)) {
						return false;
					}
					done = true;
					break;
				} else {
					rt[j] = max(rt[j], copies[j][temp].interval[j].second);
					ptr[j] = temp;
				}
			}
			if (done) {
				break;
			}
		}
		if (!done) {
			return false;
		}
	}
	return true;
}