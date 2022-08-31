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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	// 14x + 21 - {1, 2, 3, 4, 5, 6};
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		bool ok = false;
		for (ll i = 1; i <= 6; ++i) {
			ll check = (x + i - 21);
			if (check >= 0 and check % 14 == 0) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}