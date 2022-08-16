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
	int n, p, k;
	cin >> n >> p >> k;
	map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		ll a; cin >> a;
		ll val = (a * a) % p;
		val = (val * val) % p;
		val -= (k * a) % p;
		val = (val + p) % p;
		++mp[val];
	}
	ll ans = 0;
	for (auto &i : mp) {
		ans += (i.second * (i.second - 1)) / 2;
	}
	cout << ans << endl;
}