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

const int N = 5e5 + 10, IT = 70;

int main() {
	srand(time(0));
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<vector<int>, ll>> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].second;
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			a[v].first.pb(u);
		}
		for (int i = 1; i <= n; ++i) {
			sort(a[i].first.begin(), a[i].first.end());
		}
		sort(a.begin() + 1, a.end());
		ll ans = 0, sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += a[i].second;
			if (i == n or a[i].first != a[i + 1].first) {
				if (!a[i].first.empty()) {
					ans = __gcd(ans, sum);
				}
				sum = 0;
			}
		}
		cout << ans << '\n';
	}
}