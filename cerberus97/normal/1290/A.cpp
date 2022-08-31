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

const int N = 3500 + 10, inf = 1e9 + 42;

int dp[N][N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> vals = a;
		k = min(k, m - 1);
		int ans = 0, len = n - m + 1;
		for (int l = 0; l <= k; ++l) {
			int r = k - l;
			int cand = inf;
			for (int j = l; j + len - 1 <= n - 1 - r; ++j) {
				cand = min(cand, max(a[j], a[j + len - 1]));
			}
			ans = max(ans, cand);
		}
		cout << ans << '\n';
	}
}