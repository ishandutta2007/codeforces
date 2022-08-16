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
		ll r, b, k;
		cin >> r >> b >> k;
		if (r > b) {
			swap(r, b);
		}
		ll x = __gcd(b, r);
		ll check = (b - x + r - 1) / r;
		if (check >= k) {
			cout << "REBEL\n";
		} else {
			cout << "OBEY\n";
		}
	}
}