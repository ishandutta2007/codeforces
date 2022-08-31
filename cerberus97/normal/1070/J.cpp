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

const int N = 3e4 + 10, K = 2e5 + 10, ALPH = 26, S = 30, inf = 1e9;

int ctr[S];
bool dp[K];

void subset_sum(int *a, int n, int mx_sum);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		string s; cin >> s;
		memset(ctr, 0, sizeof(ctr));
		for (auto &i : s) {
			++ctr[i - 'A' + 1];
		}
		int best = inf;
		for (int i = 1; i <= ALPH; ++i) {
			int total = k - ctr[i];
			swap(ctr[i], ctr[ALPH]);
			subset_sum(ctr, ALPH - 1, total);
			for (int j = 0; j <= total; ++j) {
				if (dp[j]) {
					int c1 = max(0, n - j);
					int d1 = max(0, m - (total - j));
					if (c1 + d1 <= ctr[ALPH]) {
						best = min(best, c1 * d1);
					}
				}
			}
			swap(ctr[i], ctr[ALPH]);
		}
		cout << best << '\n';
	}
}

void subset_sum(int *a, int n, int mx_sum) {
	for (int j = 0; j <= mx_sum; ++j) {
		dp[j] = 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = mx_sum; j - a[i] >= 0; --j) {
			dp[j] |= dp[j - a[i]];
		}
	}
}