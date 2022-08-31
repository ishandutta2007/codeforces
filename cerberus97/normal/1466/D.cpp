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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> w(n);
		ll sum = 0;
		for (auto& i : w) {
			cin >> i;
			sum += i;
		}
		vector<int> deg(n, 0);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			++deg[u]; ++deg[v];
		}
		vector<int> have;
		for (int u = 0; u < n; ++u) {
			for (int j = 0; j < deg[u] - 1; ++j) {
				have.pb(w[u]);
			}
		}
		have.pb(0);
		sort(have.begin(), have.end(), greater<int>());
		for (auto& i : have) {
			cout << sum << ' ';
			sum += i;
		}
		cout << '\n';
	}
}