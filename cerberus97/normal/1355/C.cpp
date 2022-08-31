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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<ll> mark(d + 2, 0);
	for (int z = c; z <= d; ++z) {
		int lo = z - c, hi = z - b;
		++mark[lo];
		--mark[hi + 1];
	}
	ll sum = 0;
	for (auto& i : mark) {
		sum += i;
		i = sum;
	}
	sum = 0;
	for (auto& i : mark) {
		sum += i;
		i = sum;
	}
	ll ans = 0;
	for (int x = a; x <= b; ++x) {
		ans += mark[x - 1];
	}
	cout << ans << '\n';
}