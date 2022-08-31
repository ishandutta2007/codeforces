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

const int N = 1e5 + 10, K = 50;
const ld inf = 1e15;

bool solve(ll a, ll b, int k, ll m);

int main() {
	fast_cin();
	int q; cin >> q;
	while (q--) {
		ll a, b, m;
		cin >> a >> b >> m;
		bool ok = false;
		for (int k = 1; k <= K; ++k) {
			if (solve(a, b, k, m)) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
		}
	}
}

bool solve(ll a, ll b, int k, ll m) {
	vector<ll> r(k + 1), x(k + 1), c(k + 1);
	ll sum = 0;
	for (int j = 1; j <= k; ++j) {
		c[j] = (1ll << max(0, k - j - 1));
		r[j] = ((j == 1) ? a : 1);
		if (ld(c[j]) * ld(r[j]) > inf) {
			return false;
		}
		sum += c[j] * r[j];
		if (sum > b) {
			return false;
		}
	}
	for (int j = 2; j <= k; ++j) {
		ll temp = ((b - sum) / c[j]);
		temp = min(temp, m - r[j]);
		r[j] += temp;
		sum += c[j] * temp;
	}
	if (sum != b) {
		return false;
	}
	x[1] = r[1];
	for (int j = 2; j <= k; ++j) {
		x[j] = 2 * x[j - 1] + r[j] - r[j - 1];
	}
	cout << k << ' ';
	for (int j = 1; j <= k; ++j) {
		cout << x[j] << ' ';
	}
	cout << '\n';
	return true;
}