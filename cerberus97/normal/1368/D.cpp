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

const int LOG = 25;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> cnt(LOG);
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		for (int j = 0; j < LOG; ++j) {
			if ((a >> j) & 1) {
				++cnt[j];
			}
		}
	}
	vector<ll> a(n, 0);
	for (int b = LOG - 1; b >= 0; --b) {
		for (int i = 0; i < cnt[b]; ++i) {
			a[i] |= (1 << b);
		}
	}
	ll ans = 0;
	for (auto& i : a) {
		ans += i * i;
	}
	cout << ans << '\n';
}