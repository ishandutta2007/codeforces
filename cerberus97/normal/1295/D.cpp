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
		ll a, m;
		cin >> a >> m;
		vector<ll> divisors;
		ll sq = sqrt(m);
		for (ll d = 1; d <= sq; ++d) {
			if (m % d == 0) {
				divisors.pb(d);
				if (d * d != m) {
					divisors.pb(m / d);
				}
			}
		}
		sort(divisors.begin(), divisors.end());
		int nd = divisors.size();
		map<ll, ll> mu;
		mu[1] = 1;
		for (int i = 0; i < nd; ++i) {
			for (int j = i + 1; j < nd; ++j) {
				if (divisors[j] % divisors[i] == 0) {
					mu[divisors[j]] -= mu[divisors[i]];
				}
			}
		}
		ll ans = 0, g = __gcd(a, m), lo = a - 1, hi = a + m - 1;
		for (int i = 0; i < nd; ++i) {
			ll d = divisors[i];
			if (d % g == 0) {
				ll temp = hi / d - lo / d;
				ans += mu[d / g] * temp;
			}
		}
		cout << ans << '\n';
	}
}