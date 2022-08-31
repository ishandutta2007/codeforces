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

ll a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll sum = 0, xr = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
			xr ^= a[i];
		}
		if (sum == 2 * xr) {
			cout << 0 << '\n' << '\n';
			continue;
		}
		cout << 2 << '\n';
		cout << xr + sum << ' ' << xr << '\n';
	}
}