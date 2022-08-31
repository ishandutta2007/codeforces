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
const ll inf = 3e18 + 42;

ll a[N], b[N], x[N], good[N], bad[N];

void fail();

int main() {
	fast_cin();
	int n; ll t;
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i < n; ++i) {
		if (x[i] > x[i + 1] or x[i] < i) {
			fail();
		}
	}
	if (x[n] < n) {
		fail();
	}
	for (int i = 1; i <= n; ++i) {
		if (i + 1 <= x[i]) {
			good[i + 1]++;
			good[x[i] + 1]--;
		}
		bad[x[i] + 1] = true;
	}
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur += good[i];
		good[i] = cur;
		if (good[i] and bad[i]) {
			fail();
		}
	}
	b[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ll lo = max(a[i] + t, b[i - 1] + 1), hi = inf;
		if (i < n) {
			if (good[i + 1]) {
				lo = max(lo, a[i + 1] + t);
			} else if (bad[i + 1]) {
				hi = a[i + 1] + t - 1;
			}
		}
		if (lo > hi) {
			fail();
		} else {
			b[i] = lo;
		}
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << ' ';
	}
}

void fail() {
	cout << "No\n";
	exit(0);
}