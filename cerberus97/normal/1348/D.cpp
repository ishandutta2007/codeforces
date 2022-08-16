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
		int i = 1;
		n -= 1;
		vector<int> ans;
		while (n) {
			if (2 * i >= n) {
				ans.pb(n - i);
				n = 0;
			} else if (4 * i <= n) {
				ans.pb(i);
				i *= 2;
				n -= i;
			} else {
				int j = n / 2;
				ans.pb(j - i);
				i = j;
				n -= i;
			}
		}
		cout << ans.size() << '\n';
		for (auto& v : ans) {
			cout << v << ' ';
		}
		cout << '\n';
	}
}