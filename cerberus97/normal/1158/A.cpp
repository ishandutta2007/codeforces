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

ll a[N], b[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += m * a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	if (a[n] > b[1]) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 2; i <= m; ++i) {
		ans += (b[i] - a[n]);
	}
	if (a[n] != b[1]) {
		if (n == 1) {
			cout << -1 << endl;
			return 0;
		}
		ans += b[1] - a[n - 1];
	}
	cout << ans << endl;
}