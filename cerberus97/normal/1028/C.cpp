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

const int N = 2e5 + 10;

struct rectangle {
	int x1, y1, x2, y2;
} r[N];

vector<pii> v1, v2;

vector<int> get_cand(vector<pii> &v, int n);
bool in_range(int x, int x1, int x2);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
		v1.pb({r[i].x1, 1});
		v1.pb({r[i].x2 + 1, -1});
		v2.pb({r[i].y1, 1});
		v2.pb({r[i].y2 + 1, -1});
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int> x_cand = get_cand(v1, n);
	vector<int> y_cand = get_cand(v2, n);
	for (auto &x : x_cand) {
		for (auto &y : y_cand) {
			int ctr = 0;
			for (int i = 1; i <= n; ++i) {
				if (in_range(x, r[i].x1, r[i].x2) and in_range(y, r[i].y1, r[i].y2)) {
					++ctr;
				}
			}
			// cout << x << ' ' << y << ' ' << ctr << endl;
			if (ctr >= n - 1) {
				cout << x << ' ' << y << endl;
				return 0;
			}
		}
	}
}

vector<int> get_cand(vector<pii> &v, int n) {
	int ctr = 0;
	vector<int> ans;
	for (auto &i : v) {
		ctr += i.second;
		if (i.second == 1 and ctr >= n - 1) {
			ans.pb(i.first);
		}
	}
	return ans;
}

bool in_range(int x, int x1, int x2) {
	return x1 <= x and x <= x2;
}