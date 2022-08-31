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
	int n; cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll x, y;
		cin >> x >> y;
		ans += n * y - x;
		a[i] = x - y;
	}
	sort(a + 1, a + 1 + n, greater<ll>());
	for (int i = 1; i <= n; ++i) {
		ans += i * a[i];
	}
	cout << ans;
}