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
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = (x / z) + (y / z);
	x %= z; y %= z;
	ll transfer = 0;
	if (x + y >= z) {
		ans += (x + y >= z);
		transfer = min(z - y, z - x);
	}
	cout << ans << ' ' << transfer << endl;
}