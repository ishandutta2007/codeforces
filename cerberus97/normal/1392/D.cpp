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
		int n; string a;
		cin >> n >> a;
		vector<int> groups;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (cur == 0 or a[i] == a[i - 1]) {
				++cur;
			} else {
				groups.pb(cur);
				cur = 1;
			}
		}
		groups.pb(cur);
		if (a[0] == a[n - 1] and groups.size() > 1) {
			groups[0] += groups.back();
			groups.pop_back();
		}
		int ans = 0;
		if (groups.size() == 1) {
			++ans;
			groups.pb(1);
			groups[0]--;
		}
		for (auto& i : groups) {
			ans += i / 3;
		}
		cout << ans << '\n';
	}
}