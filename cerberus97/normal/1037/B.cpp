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

ll a[N];

int main() {
	fast_cin();
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll ans = 0; int p = (n + 1) / 2;
	for (int i = 1; i < p; ++i) {
		ans += max(0ll, a[i] - s);
	}
	for (int i = p + 1; i <= n; ++i) {
		ans += max(0ll, s - a[i]);
	}
	ans += max(s - a[p], a[p] - s);
	cout << ans << endl;
}