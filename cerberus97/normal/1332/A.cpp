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

bool check(int s, int l, int r, int a, int b);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (check(x, x1, x2, a, b) and check(y, y1, y2, c, d)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

bool check(int s, int l, int r, int a, int b) {
	int t = s + b - a;
	if (t < l or t > r) {
		return false;
	}
	if (l == r and (a or b)) {
		return false;
	}
	return true;
}