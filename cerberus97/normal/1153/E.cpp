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

int search_row(int x, int n);
int search_col(int y, int n);
bool query(int x1, int y1, int x2, int y2);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> rows, cols;
	for (int i = 1; i <= n; ++i) {
		if (query(i, 1, i, n)) {
			rows.pb(i);
		}
		if (query(1, i, n, i)) {
			cols.pb(i);
		}
	}
	int x1, x2, y1, y2;
	if (rows.empty()) {
		y1 = cols[0];
		y2 = cols[1];
		x1 = search_col(y1, n);
		x2 = x1;
	} else {
		x1 = rows[0];
		x2 = rows[1];
		y1 = search_row(x1, n);
		y2 = y1;
		if (int(cols.size()) == 2) {
			y2 = y1 ^ cols[0] ^ cols[1];
		}
	}
	cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}

int search_row(int x, int n) {
	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (query(x, lo, x, mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int search_col(int y, int n) {
	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (query(lo, y, mid, y)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

bool query(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int ans; cin >> ans;
	return ans % 2;
}