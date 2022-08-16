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
const ll inf = 1e15;

int main() {
	fast_cin();
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<ll> s_vals = {a, k - a};
	ll x = inf, y = -inf;
	for (auto &s : s_vals) {
		ll l = (b - s + k) % k;
		for (int i = 0; i < n; ++i) {
			x = min(x, (n * k) / __gcd(n * k, l));
			y = max(y, (n * k) / __gcd(n * k, l));
			l += k;
		}
		l = (s - b + k) % k;
		for (int i = 0; i < n; ++i) {
			x = min(x, (n * k) / __gcd(n * k, l));
			y = max(y, (n * k) / __gcd(n * k, l));
			l += k;
		}
	}
	cout << x << ' ' << y << endl;
}