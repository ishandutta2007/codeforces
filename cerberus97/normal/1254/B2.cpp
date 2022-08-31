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

const int N = 1e6 + 10;
const ll inf = 2e18 + 42;

ll a[N];

ll solve(int n, ll p);

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll sq = sqrt(sum);
	vector<ll> pfactors;
	for (ll i = 2; i <= sq; ++i) {
		if (sum % i == 0) {
			pfactors.pb(i);
			while (sum % i == 0) {
				sum /= i;
			}
		}
	}
	if (sum > 1) {
		pfactors.pb(sum);
	}
	ll best = inf;
	for (auto &p : pfactors) {
		best = min(best, solve(n, p));
	}
	if (best == inf) {
		cout << -1 << '\n';
	} else {
		cout << best << endl;
	}
}

ll solve(int n, ll p) {
	ll ans = 0, cur = 0;
	vector<pll> blocks;
	for (int i = 1; i <= n; ++i) {
		ll here = a[i];
		ll take = min(here, p - cur);
		if (take) {
			blocks.pb({take, i});
			cur += take;
		}
		if (cur == p) {
			ll cnt = 0, median = 0;
			for (auto &temp : blocks) {
				cnt += temp.first;
				if (cnt >= (p + 1) / 2) {
					median = temp.second;
					break;
				}
			}
			for (auto &temp : blocks) {
				ans += abs(temp.second - median) * temp.first;
			}
			blocks.clear();
			cur = 0;
		}
		if (here > take) {
			blocks.pb({(here - take) % p, i});
			cur += (here - take) % p;
		}
	}
	return ans;
}