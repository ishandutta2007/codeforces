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
		int n; ll W;
		cin >> n >> W;
		vector<ll> w(n);
		for (auto& i : w) {
			cin >> i;
		}
		ll lo = (W + 1) / 2, sum = 0;
		vector<int> ids;
		for (int i = 0; i < n; ++i) {
			if (w[i] > W) {
				continue;
			} else if (w[i] >= lo) {
				sum = w[i];
				ids = {i + 1};
				break;
			} else if (sum < lo) {
				sum += w[i];
				ids.pb(i + 1);
			}
		}
		if (sum >= lo) {
			cout << ids.size() << '\n';
			for (auto& i : ids) {
				cout << i << ' ';
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}