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
#include <cassert>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

ll f(ll n, ll k);

int main() {
	ll n; cin >> n;
	ll lo = 1, hi = n;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (2 * f(n, mid) >= n) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << hi + 1;
}

ll f(ll n, ll k) {
	ll ans = 0;
	while (n) {
		ans += min(n, k);
		n -= min(k, n);
		n -= n / 10;
	}
	return ans;
}