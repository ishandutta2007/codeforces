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

const int N = 2e5 + 10;
const ll inf = 1e10 + 42;

int a[N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int median = (n + 1) / 2;
	ll lo = 1, hi = inf;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll cost = 0;
		for (int i = median; i <= n; ++i) {
			cost += max(mid - a[i], 0ll);
		}
		if (cost <= k) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << lo - 1 << '\n';
}