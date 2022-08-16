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

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 2e18;

ll a[2 * N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + 2 * n);
	ll best = inf;
	for (int i = 1; i + n - 1 <= 2 * n; ++i) {
		ll x = a[i + n - 1] - a[i];
		ll y = 0;
		if (i + n - 1 == 2 * n) {
			y = a[i - 1];
		} else {
			y = a[2 * n];
		}
		if (i == 1) {
			y -= a[i + n];
		} else {
			y -= a[1];
		}
		best = min(best, x * y);
	}
	cout << best;
}