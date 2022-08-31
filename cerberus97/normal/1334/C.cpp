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
const ll inf = 1e18 + 42;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		ll sum = 0, mn = inf;
		for (int i = 0; i < n; ++i) {
			ll tmp = max(0ll, a[i] - b[(i + n - 1) % n]);
			sum += tmp;
			mn = min(mn, a[i] - tmp);
		}
		cout << sum + mn << '\n';
	}
}