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

const int N = 1e2 + 10;

int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll total = a[1], cur = a[1];
	vector<int> ans = {1};
	for (int i = 2; i <= n; ++i) {
		total += a[i];
		if (2 * a[i] <= a[1]) {
			ans.pb(i);
			cur += a[i];
		}
	}
	if (cur >= (total / 2) + 1) {
		cout << ans.size() << '\n';
		for (auto &i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	} else {
		cout << 0 << '\n';
	}
}