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

const int N = 1e5 + 10, LOG = 35;

int main() {
	fast_cin();
	int t; cin >> t;
	int target = 11;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(LOG, 0);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			++cnt[__builtin_ctz(x)];
		}
		for (int i = 0; i < target; ++i) {
			cnt[i + 1] += cnt[i] / 2;
		}
		if (cnt[target]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}