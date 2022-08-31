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
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	int sq = sqrt(y);
	set<ll> factors;
	for (int i = 1; i <= sq; ++i) {
		if (y % i == 0) {
			factors.insert(i);
			factors.insert(y / i);
		}
	}
	int ans = 0;
	for (auto &a : factors) {
		if (l <= a and a <= r) {
			ll b = (x * y) / a;
			if (l <= b and b <= r and __gcd(a, b) == x) {
				++ans;
			}
		}
	}
	cout << ans;
}