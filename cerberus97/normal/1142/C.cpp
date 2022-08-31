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

struct PT {
	ll x, y;
	bool operator<(const PT &o) const {
		return tie(x, y) < tie(o.x, o.y);
	}
};

PT p[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].y -= p[i].x * p[i].x;
	}
	sort(p + 1, p + 1 + n);
	vector<PT> hull;
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		if (i < n and p[i].x == p[i + 1].x) {
			continue;
		}
		while (k >= 2) {
			PT p1 = hull[k - 1], p2 = hull[k - 2];
			if ((p[i].y - p2.y) * (p1.x - p2.x) >= (p1.y - p2.y) * (p[i].x - p2.x)) {
				hull.pop_back();
				--k;
			} else {
				break;
			}
		}
		hull.push_back(p[i]);
		++k;
	}
	cout << max(1, int(hull.size())) - 1 << endl;
}