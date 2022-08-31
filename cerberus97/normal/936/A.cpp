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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	ll k, d, t;
	cin >> k >> d >> t;
	ll temp = (k / d) + !!(k % d);
	d = temp * d;

	ll i = (2 * t) / (d + k);
	ld dist = i * (k + d);
	ld ans = i * d;
	if (dist < 2 * t) {
		ld j = min(ld(k), (2 * t - dist) / 2.0);
		dist += 2 * j;
		ans += j;
	}
	if (dist < 2 * t) {
		ans += 2 * t - dist;
	}
	cout << fixed << setprecision(12) << ans;
}