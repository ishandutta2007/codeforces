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
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	mp[0] = 1;
	int pref_xor = 0, largest = (1 << k) - 1;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		pref_xor ^= a;
		++mp[min(pref_xor, largest - pref_xor)];
	}
	ll ans = 0;
	for (auto &m : mp) {
		int ctr = m.second;
		ll x = ctr / 2, y = ctr - x;
		ans += ((x * (x - 1)) / 2) + ((y * (y - 1)) / 2);
	}
	cout << (ll(n) * (n + 1)) / 2 - ans << endl;
}