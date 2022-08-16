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
	ll x; cin >> x;
	ll best = x, sq = sqrt(x);
	ll a1 = 1, a2 = x;
	for (ll i = 1; i <= sq; ++i) {
		if (x % i == 0 and x / __gcd(i, x / i) == x) {
			ll val = max(i, x / i);
			if (val < best) {
				best = val;
				a1 = i;
				a2 = x / i;
			}
		}
	}
	cout << a1 << ' ' << a2 << endl;
}