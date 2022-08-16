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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<int> dp(n + 1, inf), at(n + 1, inf);
	dp[0] = 0;
	at[0] = 0;
	int mn = 0, offset = 0;
	set<pii> s = {{0, 0}};
	for (int i = 1; i < n; ++i) {
		int tmp = inf;
		for (auto& [val, id] : s) {
			if (id != a[i]) {
				tmp = val;
				break;
			}
		}
		dp[i] = min(tmp + offset, at[a[i]] + 1 + offset);
		offset += (a[i - 1] == a[i]);
		dp[i] -= offset;
		mn = min(mn, dp[i]);
		if (dp[i] < at[a[i - 1]]) {
			s.erase({at[a[i - 1]], a[i - 1]});
			at[a[i - 1]] = dp[i];
			s.insert({at[a[i - 1]], a[i - 1]});
		}
	}
	cout << n - (mn + offset) << '\n';
}