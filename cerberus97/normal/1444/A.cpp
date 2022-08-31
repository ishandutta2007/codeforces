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
		ll p, q;
		cin >> p >> q;
		ll ans = 1, bak_q = q, sq = sqrt(q);
		vector<ll> primes;
		for (ll i = 2; i <= sq; ++i) {
			if (q % i == 0) {
				primes.pb(i);
				while (q % i == 0) {
					q /= i;
				}
			}
		}
		if (q > 1) {
			primes.pb(q);
		}
		q = bak_q;
		for (auto& i : primes) {
			ll cand = p;
			while (cand % q == 0) {
				cand /= i;
			}
			ans = max(ans, cand);
		}
		cout << ans << '\n';
	}
}