/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	ll a, b, f, k;
	cin >> a >> b >> f >> k;
	ll ans = 0, fuel = b, x = 0;
	while (k--) {
		ll y = a - x;
		if (abs(x - f) > fuel) {
			ans = -1;
			break;
		}
		fuel -= (abs(x - f));
		x = f;
		if (abs(y - f) > fuel or (k and 2 * abs(y - f) > fuel)) {
			++ans;
			fuel = b;
		}
		if (abs(y - f) > fuel) {
			ans = -1;
			break;
		}
		fuel -= abs(y - f);
		x = y;
	}
	cout << ans;
}