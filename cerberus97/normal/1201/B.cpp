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
	int n; cin >> n;
	ll sum = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		ll a; cin >> a;
		sum += a;
		mx = max(mx, a);
	}
	if (sum % 2 == 0 and 2 * mx <= sum) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}