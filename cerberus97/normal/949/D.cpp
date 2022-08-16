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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

ll n, d, c;
ll a[N], b[N];

bool check(ll x);

int main() {
	cin >> n >> d >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	// cout << check(0) << endl;
	int l = 0, r = (n + 1) / 2 - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << r + 1;
}

bool check(ll x) {
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i];
	}
	ll f = (n + 1) / 2;
	ll l = x + 1, r = f, t = l, p = 1;
	for (int i = l; i <= r; ++i, ++t) {
		// cout << i << ' ' << t << ' ' << p << ' ' << b[p] << endl;
		ll temp = c;
		while (temp) {
			if (p > n) {
				return false;
			} else if (!b[p]) {
				++p;
			} else if (p - d * t > i or p + d * t < i) {
				return false;
			} else if (b[p] >= temp) {
				b[p] -= temp;
				temp = 0;
			} else {
				temp -= b[p];
				b[p] = 0;
			}
		}
	}
	l = f + 1; r = n - x; t = n - r + 1; p = n;
	for (int i = r; i >= l; --i, ++t) {
		ll temp = c;
		while (temp) {
			if (p < 1) {
				return false;
			} else if (!b[p]) {
				--p;
			} else if (p - d * t > i or p + d * t < i) {
				return false;
			} else if (b[p] >= temp) {
				b[p] -= temp;
				temp = 0;
			} else {
				temp -= b[p];
				b[p] = 0;
			}
		}
	}
	return true;
}