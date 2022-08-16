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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; ll l, r;
		cin >> n >> l >> r;
		ll cur = 0, sz;
		for (int i = 1; i <= (n - 1); ++i, cur += sz) {
			sz = 2 * (n - i);
			if (cur + sz < l or cur > r) {
				continue;
			} else {
				vector<int> tmp;
				tmp.reserve(sz);
				for (int j = i + 1; j <= n; ++j) {
					tmp.pb(i);
					tmp.pb(j);
				}
				for (int j = 1; j <= sz; ++j) {
					if (l <= cur + j and cur + j <= r) {
						cout << tmp[j - 1] << ' ';
					}
				}
			}
		}
		if (cur < r) {
			cout << 1;
		}
		cout << '\n';
	}
}