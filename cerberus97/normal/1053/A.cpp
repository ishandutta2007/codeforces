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
	ll n, m, k;
	cin >> n >> m >> k;
	if (2 * n * m % k) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << "0 0\n";
	ll x, y;
	if (k % 2 == 0) {
		k /= 2;
		ll k1 = __gcd(k, n);
		ll k2 = k / k1;
		x = n / k1;
		y = m / k2;
	} else {
		ll k1 = __gcd(k, n);
		ll k2 = k / k1;
		x = n / k1;
		y = m / k2;
		if (2 * x <= n) {
			x *= 2;
		} else {
			y *= 2;
		}
	}
	cout << x << ' ' << 0 << endl;
	cout << 0 << ' ' << y << endl;
}