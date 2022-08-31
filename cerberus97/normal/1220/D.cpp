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

const int N = 2e5 + 10, LOG = 64;

vector<ll> elems[LOG];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		ll b; cin >> b;
		ll p2 = 1;
		int lg = 0;
		while (b % (2 * p2) == 0) {
			p2 *= 2;
			++lg;
		}
		elems[lg].pb(b);
	}
	int mx = 0;
	for (int lg = 0; lg < LOG; ++lg) {
		if (elems[lg].size() > elems[mx].size()) {
			mx = lg;
		}
	}
	cout << n - elems[mx].size() << '\n';
	for (int lg = 0; lg < LOG; ++lg) {
		if (lg != mx) {
			for (auto &b : elems[lg]) {
				cout << b << ' ';
			}
		}
	}
	cout << endl;
}