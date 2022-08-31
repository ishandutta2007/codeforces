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
	int t; cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		bool ok = (2 * b - a) % 3 == 0 and 2 * b >= a;
		ok = ok and (2 * a - b) % 3 == 0 and 2 * a >= b;
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}