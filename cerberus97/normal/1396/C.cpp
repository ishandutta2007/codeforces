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

const int N = 1e6 + 10;
const ll inf = 1e18 + 42;

ll dp[N][2];

int main() {
	fast_cin();
	int n; ll r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	dp[0][1] = inf;
	for (int i = 0; i < n; ++i) {
		dp[i + 1][0] = dp[i + 1][1] = inf;
		for (int cnt = 0; cnt < 2; ++cnt) {
			ll c1 = r1 * a[i] + r3;
			ll c2 = min(r2, r1 * a[i] + r1) + r1 + (cnt ? 0 : 2 * d);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][cnt] + c1);
			dp[i + 1][cnt ^ 1] = min(dp[i + 1][cnt ^ 1], dp[i][cnt] + c2);
			if (i == n - 1 and cnt % 2 == 1) {
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][cnt] + c1 - d);
			}
		}
	}
	cout << min(dp[n][0], dp[n][1]) + (n - 1) * d << '\n';
}