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

const int N = 5e5 + 10;
const ll inf = 1e18;

ll a[N], ans[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll absum = 0, smallest = inf, nctr = 0;
	for (int i = n; i >= 2; --i) {
		absum += max(a[i], -a[i]);
		if (a[i] < 0) {
			++nctr;
		} else {
			smallest = min(smallest, a[i]);
		}
		ans[i - 1] += absum;
		if (!nctr) {
			ans[i - 1] -= 2 * smallest;
		}
	}
	absum = nctr = 0;
	smallest = inf;
	for (int i = 1; i < n; ++i) {
		absum += max(a[i], -a[i]);
		if (a[i] < 0) {
			++nctr;
		} else {
			smallest = min(smallest, a[i]);
		}
		ans[i + 1] += absum;
		if (!nctr) {
			ans[i + 1] -= 2 * smallest;
		}
	}
	ll best = -inf;
	for (int i = 1; i <= n; ++i) {
		best = max(best, ans[i] + a[i]);
	}
	cout << best << endl;
}