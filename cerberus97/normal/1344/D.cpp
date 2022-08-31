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
const ll inf = 4e18 + 42;

ll get(ll a, ll mx);

int main() {
	fast_cin();
	int n; ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	ll lo = -inf, hi = inf;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
		for (auto& i : a) {
			sum += get(i - mid, i);
		}
		if (sum >= k) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	ll val = (lo - 1);
	vector<ll> b(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		b[i] = get(a[i] - val, a[i]);
		sum += b[i];
	}
	for (int i = 0; i < n and sum > k; ++i) {
		if (b[i] and get(a[i] - val, a[i]) != get(a[i] - (val + 1), a[i])) {
			--b[i];
			--sum;
		}
	}
	for (auto& i : b) {
		cout << i << ' ';
	}
	cout << endl;
}

ll get(ll a, ll mx) {
	ll lo = 1, hi = mx;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll val = 3 * mid * mid - 3 * mid + 1;
		if (val <= a) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return lo - 1;
}