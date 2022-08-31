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

bool check(ll a, ll b);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (check(a, b)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

bool check(ll a, ll b) {
	if (a - b > 1) {
		return false;
	}
	ll num = a + b, sq = sqrt(num);
	for (int i = 2; i <= sq; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}