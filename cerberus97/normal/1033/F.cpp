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

const int W = 12, C = 300, P3 = 531441 + 10;

int ctr[1 << W], ternary[1 << W];
int dp[P3];
vector<int> digits[C];
string s;

void pre();
int solve(int j, int w, int mask);

int main() {
	pre();
	fast_cin();
	int w, n, m;
	cin >> w >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		++ctr[x];
	}
	int tot = (1 << w);
	for (int i = 0; i < tot; ++i) {
		for (int j = 0; j < w; ++j) {
			ternary[i] *= 3;
			ternary[i] += ((i >> j) & 1);
		}
	}
	for (int i = 0; i < tot; ++i) {
		for (int j = 0; j < tot; ++j) {
			dp[ternary[i] + ternary[j]] += ctr[i] * ctr[j];
		}
	}
	while (m--) {
		cin >> s; reverse(s.begin(), s.end());
		cout << solve(0, w, 0) << '\n';
	}
}

int solve(int j, int w, int mask) {
	if (j == w) {
		return dp[mask];
	} else {
		int ans = 0;
		for (auto &d : digits[s[j]]) {
			ans += solve(j + 1, w, mask * 3 + d);
		}
		return ans;
	}
}

void pre() {
	digits['A'] = {0, 1};
	digits['a'] = {2};
	digits['O'] = {0};
	digits['o'] = {1, 2};
	digits['X'] = {0, 2};
	digits['x'] = {1};
}