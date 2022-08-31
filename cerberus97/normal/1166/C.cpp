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
	int n; cin >> n;
	vector<int> a;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a.pb(abs(x));
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	int p = 0;
	for (int i = 0; i < n; ++i) {
		while (2 * a[p] < a[i]) {
			++p;
		}
		ans += i - p;
	}
	cout << ans;
}