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

const int N = 3e5 + 10, inf = 1e9 + 42;

int a[N], ans[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
		a[i + 2 * n] = a[i];
	}
	vector<pii> highly_bad = {{-1, inf}};
	ans[3 * n + 1] = inf;
	for (int i = 3 * n; i >= 1; --i) {
		auto it = upper_bound(highly_bad.begin(), highly_bad.end(), make_pair((a[i] - 1) / 2, inf));
		--it;
		ans[i] = min(it->second, ans[i + 1]);
		while (highly_bad.back().first >= a[i]) {
			highly_bad.pop_back();
		}
		highly_bad.pb({a[i], i});
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == inf) {
			cout << -1 << ' ';
		} else {
			cout << ans[i] - i << ' ';
		}
	}
	cout << endl;
}