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

const int N = 50;

ll pwr(ll x, ll e) {
	ll ans = 1;
	while (e--) {
		ans *= x;
	}
	return ans;
}

int main() {
	fast_cin();
	ll k; cin >> k;
	string s = "codeforces";
	int n = s.length();
	for (ll a = 1; a < N; ++a) {
		ll tmp = pwr(a + 1, n);
		if (tmp < k) {
			continue;
		}
		for (int i = 0; i <= n; ++i) {
			if (pwr(a + 1, i) * pwr(a, n - i) >= k) {
				for (int j = 0; j < n; ++j) {
					int times = (j < i ? a + 1 : a);
					cout << string(times, s[j]);
				}
				return 0;
			}
		}
	}
}