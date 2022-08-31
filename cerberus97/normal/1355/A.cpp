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
#include <numeric>

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
		ll a, k;
		cin >> a >> k;
		--k;
		while (k--) {
			int mn = 9, mx = 0;
			ll tmp = a;
			while (tmp) {
				mn = min(mn, int(tmp % 10));
				mx = max(mx, int(tmp % 10));
				tmp /= 10;
			}
			if (!mn) {
				break;
			}
			a += mn * mx;
		}
		cout << a << '\n';
	}
}