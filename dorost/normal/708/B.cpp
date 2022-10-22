/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;

int32_t main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b + c + d == 0) {
		cout << 0;
		return 0;
	}
	int x = -1, y = -1;
	int x2 = INT_MAX, y2 = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (i * abs(i - 1) / 2 == a && x != -1) {
			x2 = i;
		} else if (i * abs(i - 1) / 2 == a) {
			x = i;
		}
		if (i * abs(i - 1) / 2 == d && y != -1) {
			y2 = i;
		} else if (i * abs(i - 1) / 2 == d) {
			y = i;
		}
	}
	if (x == -1 || y == -1) {
		cout << "Impossible";
		return 0;
	}
	if (((x * y) != (b + c)) && ((x2 * y) != (b + c) || x2 == INT_MAX) && ((x * y2) != (b + c) || y2 == INT_MAX) && ((x2 * y2) != (b + c) || y2 == INT_MAX || x2 == INT_MAX)) {
		cout << "Impossible";
		return 0;
	}
	if (x2 * y == b + c && x2 != INT_MAX) {
		x = x2;
	}
	if (x * y2 == b + c && y2 != INT_MAX) {
		y = y2;
	}
	if (x2 * y2 == b + c && x2 + y2 < INT_MAX) {
		x = x2;
		y = y2;
	}
	int xx = 0;
	for (int i = 0; i < (x != 0 ? c / x : y - 1); i++) {
		cout << 1;
		xx++;
	}
	for (int i = 0; i < (x == 0 ? 0 : x - c % x); i++) {
		cout << 0;
	}
	if (xx != y) {
		cout << 1;
		xx++;
	}
	for (int i = 0; i < (x == 0 ? 0 : c % x); i++) {
		cout << 0;
	}
	for (int i = 0; i < y - xx; i++) {
		cout << 1;
	}
}