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

const int N = 1e5 + 10, LOG = 32;

multiset<int> a[LOG];
ll sum[LOG];

int main() {
	fast_cin();
	int q; cin >> q;
	while (q--) {
		char t; int x;
		cin >> t >> x;
		int i = 0;
		while ((1 << i) <= x) {
			++i;
		}
		--i;
		if (t == '+') {
			a[i].insert(x);
			sum[i] += x;
		} else {
			a[i].erase(a[i].find(x));
			sum[i] -= x;
		}
		ll cur = 0, ans = 0;
		for (i = 0; i < LOG; ++i) {
			if (!a[i].empty() and 2 * cur < *a[i].begin()) {
				--ans;
			}
			ans += a[i].size();
			cur += sum[i];
		}
		cout << ans << '\n';
	}
}