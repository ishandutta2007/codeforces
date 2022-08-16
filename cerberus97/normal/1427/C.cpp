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

struct PT {
	int t, x, y, val, mx;
};

int main() {
	fast_cin();
	int r, n;
	cin >> r >> n;
	vector<PT> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		auto& p = a[i];
		cin >> p.t >> p.x >> p.y;
		p.val = p.mx = 0;
	}
	a[0] = {0, 1, 1, 0, 0};
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[i].t - a[j].t >= 2 * r) {
				a[i].val = max(a[i].val, a[j].mx + 1);
				break;
			} else if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t and (!j or a[j].val)) {
				a[i].val = max(a[i].val, a[j].val + 1);
			}
		}
		a[i].mx = max(a[i].val, a[i - 1].mx);
	}
	cout << a[n].mx;
}