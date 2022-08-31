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

const int N = 2e5 + 10;

ll a[N], b[N];
map<pair<int, int>, int> mp;

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll use = 0;
	int q; cin >> q;
	while (q--) {
		int s, t, u;
		cin >> s >> t >> u;
		if (mp.find({s, t}) != mp.end()) {
			int v = mp[{s, t}];
			use -= min(a[v], b[v]);
			--b[v];
			use += min(a[v], b[v]);
		}
		mp[{s, t}] = u;
		use -= min(a[u], b[u]);
		++b[u];
		use += min(a[u], b[u]);
		cout << sum - use << '\n';
	}
}