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
const ll inf = 1e15 + 42;

ll a[N], b[N];

int main() {
	fast_cin();
	int n, m, k; ll t_a, t_b;
	cin >> n >> m >> t_a >> t_b >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	ll ans = 0;
	int p = 1;
	a[n + 1] = inf;
	b[m + 1] = inf;
	for (int i = 0; i <= min(n, k); ++i) {
		ll t = a[i + 1] + t_a;
		while (p <= m and b[p] < t) {
			++p;
		}
		int left = k - i;
		ans = max(ans, b[min(m + 1, p + left)] + t_b);
	}
	if (ans >= inf) {
		ans = -1;
	}
	cout << ans << '\n';
}