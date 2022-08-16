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
	ll n; cin >> n;
	vector<ll> pfactors;
	ll sq = sqrt(n);
	for (ll i = 2; i <= sq; ++i) {
		if (n % i == 0) {
			pfactors.pb(i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		pfactors.pb(n);
	}
	if (pfactors.size() >= 2 or pfactors.empty()) {
		cout << 1 << '\n';
	} else {
		cout << pfactors[0] << '\n';
	}
}