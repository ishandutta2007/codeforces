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

const int N = 20, mod = 1e9 + 7;

map<pair<vector<int>, int>, int> mp;
int t[N], g[N];

ll solve(vector<int> &ctr, int last);

int main() {
	fast_cin();
	int n, T;
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> g[i];
		--g[i];
	}
	int subsets = (1 << n);
	ll ans = 0;
	for (int mask = 0; mask < subsets; ++mask) {
		int sum = 0;
		vector<int> ctr(3, 0);
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				sum += t[i];
				++ctr[g[i]];
			}
		}
		if (sum == T) {
			ans += solve(ctr, -1);
		}
	}
	cout << ans % mod << endl;
}

ll solve(vector<int> &ctr, int last) {
	if (mp.count({ctr, last})) {
		return mp[{ctr, last}];
	} else {
		ll ans = 0;
		if (ctr[0] + ctr[1] + ctr[2] == 0) {
			ans = 1;
		} else {
			for (int i = 0; i < 3; ++i) {
				if (i == last) {
					continue;
				}
				ll temp = ctr[i];
				--ctr[i];
				temp *= solve(ctr, i);
				temp %= mod;
				++ctr[i];
				ans += temp;
			}
			ans %= mod;
		}
		mp[{ctr, last}] = ans;
		return ans;
	}
}