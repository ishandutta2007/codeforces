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

int x[N], y[N], a[N], b[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n; ++i) {
		multiset<pii> have;
		for (int j = 1; j <= n; ++j) {
			if (j == i) {
				continue;
			}
			have.insert({a[j], b[j]});
		}
		int ax = x[1] + a[i], ay = y[1] + b[i];
		bool ok = true;
		for (int j = 2; j <= n; ++j) {
			int nx = ax - x[j];
			int ny = ay - y[j];
			if (!have.count({nx, ny})) {
				ok = false;
				break;
			} else {
				have.erase(have.find({nx, ny}));
			}
		}
		if (ok) {
			cout << ax << ' ' << ay << endl;
			return 0;
		}
	}
}