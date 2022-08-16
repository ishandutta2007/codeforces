/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
#define sqr(x) (x) * (x)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	ll R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	ll k2 = sqr(x1 - x2) + sqr(y1 - y2);
	ll R2 = R * R;
	if (k2 >= R2) {
		cout << x1 << ' ' << y1 << ' ' << R;
	} else {
		ld x, y, k = sqrt(k2);
		if (k2 == 0) {
			x = x1 - R;
			y = y1;
		} else {
			x = x1 - (R * (x2 - x1)) / k;
			y = y1 - (R * (y2 - y1)) / k;
		}
		x = (x2 + x) / 2;
		y = (y2 + y) / 2;
		cout << fixed << setprecision(10);
		cout << x << ' ' << y << ' ' << (R + k) / 2;
	}
}