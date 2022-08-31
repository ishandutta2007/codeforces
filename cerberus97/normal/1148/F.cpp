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

const int N = 3e5 + 10;

ll val[N], mask[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i] >> mask[i];
		sum += val[i];
	}
	if (sum > 0) {
		for (int i = 1; i <= n; ++i) {
			val[i] = -val[i];
		}
	}
	ll s = 0, one = 1;
	for (int bit = 61; bit >= 0; --bit) {
		ll temp = 0;
		for (int i = 1; i <= n; ++i) {
			if ((mask[i] & (one << bit)) and ((mask[i] >> bit) << bit) == mask[i]) {
				temp += val[i];
			}
		}
		if (temp < 0) {
			s |= (one << bit);
			for (int i = 1; i <= n; ++i) {
				if (mask[i] & (one << bit)) {
					val[i] = -val[i];
				}
			}
		}
	}
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += val[i];
	}
	assert(sum > 0);
	cout << s << endl;
}