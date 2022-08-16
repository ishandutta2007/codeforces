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

const int N = 110;

int a[N], target[N];
ld dp[N];

int main() {
	fast_cin();
	int n = 10;
	for (int i = n - 1; i >= 0; --i) {
		for (int j_ = 0; j_ < n; ++j_) {
			int j = (i % 2 == 0 ? j_ : 9 - j_);
			int id = i * n + j;
			cin >> a[id];
			if (a[id] != 0) {
				target[id] = id + n * a[id];
				if (a[id] % 2 == 1) {
					target[id] += (n - 1) - 2 * (target[id] % n);
				}
			} else {
				target[id] = id;
			}
			// cout << id << ' ' << target[id] << endl;
		}
	}
	int t = n * n - 1;
	dp[t] = 0;
	for (int i = t - 1; i >= 0; --i) {
		int bad = 0;
		dp[i] = 1;
		for (int j = 1; j <= 6; ++j) {
			if (i + j > t) {
				++bad;
			} else {
				dp[i] += min(dp[i + j], dp[target[i + j]]) / 6;
			}
		}
		dp[i] /= (1 - bad / 6.0);
	}
	cout << fixed << setprecision(12) << dp[0] << '\n';
}