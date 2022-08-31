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

const int N = 1e3 + 10;

vector<int> solve(int p1, int p2, vector<int> pts);
ll query(int t, int i, int j, int k);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> up, bel;
	for (int i = 3; i <= n; ++i) {
		if (query(2, 1, 2, i) == 1) {
			up.pb(i);
		} else {
			bel.pb(i);
		}
	}
	vector<int> l1 = solve(2, 1, bel);
	vector<int> l2 = solve(1, 2, up);
	cout << "0 1 ";
	for (auto &i : l1) {
		cout << i << ' ';
	}
	cout << "2 ";
	for (auto &i : l2) {
		cout << i << ' ';
	}
	cout << endl;
}

vector<int> solve(int p1, int p2, vector<int> pts) {
	if (pts.size() <= 1) {
		return pts;
	}
	int n = pts.size();
	map<int, ll> areas;
	for (int i = 0; i < n; ++i) {
		areas[pts[i]] = query(1, p1, p2, pts[i]);
	}
	sort(pts.begin(), pts.end(), [&] (int i, int j) {
		return areas[i] < areas[j];
	});
	int q = pts.back();
	vector<int> l1, l2;
	for (int i = 0; i < n - 1; ++i) {
		if (query(2, p1, q, pts[i]) == 1) {
			l2.pb(pts[i]);
		} else {
			l1.pb(pts[i]);
		}
	}
	reverse(l2.begin(), l2.end());
	vector<int> ans;
	for (auto &i : l1) {
		ans.pb(i);
	}
	ans.pb(q);
	for (auto &i : l2) {
		ans.pb(i);
	}
	return ans;
}

ll query(int t, int i, int j, int k) {
	cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
	ll res; cin >> res;
	return res;
}