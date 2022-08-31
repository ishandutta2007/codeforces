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
	ll n; int m;
	cin >> n >> m;
	ll ans = 0;
	for (ll i = 1; i <= m and i <= n; ++i) {
		for (ll j = 1; j <= m and j <= n; ++j) {
			if ((i * i + j * j) % m == 0) {
				// cout << i << ' ' << j << endl;
				ans += max(0ll, (((n - i) / m) + 1)) * max(0ll, (((n - j) / m) + 1));
			}
		}
	}
	cout << ans << endl;
}