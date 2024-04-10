/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int x[3], y[3];

int dis(int x1, int x2, int i) {
	return max(0, abs(x1 - x[i]) + abs(x2 - y[i]));
}

bool is(int x1, int y1) {
	for (int i = 0; i < 3; i++)
		if (x1 == x[i] && y1 == y[i])
			return true;
	return false;
}

int32_t main() {
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	int mn = INT_MAX;
	int x1 = -1, y1 = -1;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (mn > dis(i, j, 0) + dis(i, j, 1) + dis(i, j, 2) - 2) {
				mn = dis(i, j, 0) + dis(i, j, 1) + dis(i, j, 2) - 2;
				x1 = i;
				y1 = j;
			}
		}
	}
	cout << mn + 3 << '\n';
	bool f = false;
	for (int i = 0; i < 3; i++) {
		cout << x[i] << ' ' << y[i] << '\n';
	}
	if (!is(x1, y1))
		cout << x1 << ' ' << y1 << '\n';
	for (int i = 0; i < 3; i++) {
		if (x[i] > x1) {
			for (int j = x1 + 1; j < x[i]; j++) {
				cout << j << ' ' << y1 << '\n';
			}
		} else if (x[i] < x1) {
			for (int j = x1 - 1; j > x[i]; j--) {
				cout << j << ' ' << y1 << '\n';
			}
		} else {
			if (y[i] > y1) {
				for (int j = y1 + 1; j < y[i]; j++) {
					cout << x[i] << ' ' << j << '\n';
				}
			} else if (y1 > y[i]) {
				for (int j = y1 - 1; j > y[i]; j--) {
					cout << x[i] << ' ' << j << '\n';
				}
			}
			continue;
		}
		if (y[i] > y1) {
			for (int j = y1; j < y[i]; j++) {
				cout << x[i] << ' ' << j << '\n';
			}
		} else if (y1 > y[i]) {
			for (int j = y1; j > y[i]; j--) {
				cout << x[i] << ' ' << j << '\n';
			}
		}
	}
}