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

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	int rmin = n + 1, rmax = -1, cmin = m + 1, cmax = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			if (c == 'B') {
				rmin = min(rmin, i);
				rmax = max(rmax, i);
				cmin = min(cmin, j);
				cmax = max(cmax, j);
			}
		}
	}
	cout << (rmin + rmax) / 2 << ' ' << (cmin + cmax) / 2 << endl;
}