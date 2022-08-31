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

const int N = 1e5 + 10, LOG = 60;

int main() {
	fast_cin();
	ll u, v;
	cin >> u >> v;
	if (u > v or (v - u) % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> a(3, 0);
	a[0] = u;
	v -= u;
	for (int b = LOG - 1; b >= 0; --b) {
		ll here = (1ll << (b + 1));
		if (here <= v) {
			v -= here;
			a[1] |= (1ll << b);
			if ((a[0] >> b) & 1) {
				a[2] |= (1ll << b);
			} else {
				a[0] |= (1ll << b);
			}
		}
	}
	while (a.back() == 0) {
		a.pop_back();
	}
	cout << a.size() << '\n';
	for (auto& i : a) {
		cout << i << ' ';
	}
}