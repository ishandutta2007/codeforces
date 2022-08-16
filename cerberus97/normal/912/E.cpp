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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NUll)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;

const int N = 20;
const ll inf = 1e18 + 20;

int a[N];
vector <ll> v1, v2;
vector <int> prime[2];

ll f(ll x);
void g(vector <int> &p, vector <ll> &v, int i, ll j, ll cur);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		prime[i % 2].pb(a[i]);
	}

	g(prime[0], v1, prime[0].size() - 1, inf, 1);
	g(prime[1], v2, prime[1].size() - 1, inf, 1);
	// v1.pb(1);
	// v2.pb(1);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	// for (auto &i : v1) {
	// 	cout << i << ' ';
	// }

	// cout << endl;

	// for (auto &i : v2) {
	// 	cout << i << ' ';
	// }

	// cout << endl;

	ll k;
	cin >> k;
	ll l = 1, r = inf;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (f(mid) >= k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << r + 1 << endl;
}

ll f(ll x) {
	int n = v1.size(), m = v2.size();
	int i = 0, j = m - 1;
	ll ans = 0;
	while (i < n) {
		while (j >= 0 and (ld(v1[i]) * v2[j] > inf or v1[i] * v2[j] > x)) {
			--j;
		}

		if (j < 0) {
			break;
		}

		ans += j + 1;
		++i;
	}

	return ans;
}

void g(vector <int> &p, vector <ll> &v, int i, ll j, ll cur) {
	if (i == -1) {
		v.pb(cur);
		return;
	}

	ll temp = 1;
    while (ld(temp) * ld(cur) <= ld(j)) {
    	g(p, v, i - 1, j, cur * temp);
		if (ld(temp) * p[i] > j) {
			break;
		}

		temp = temp * p[i];
    }
}