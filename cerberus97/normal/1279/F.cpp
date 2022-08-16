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

const int N = 1e6 + 10;

char s[N];

pll check(int n, int l, ll delta);
pll solve(int n, int l, ll delta);

int main() {
	fast_cin();
	int n, k, l;
	cin >> n >> k >> l >> (s + 1);
	if (ll(k) * l >= n) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		s[i] = bool(isupper(s[i]));
	}
	int lo = 0, hi = n;
	ll best = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		auto res = check(n, l, mid);
		res.second = -res.second;
		if (res.second <= k) {
			hi = mid - 1;
			best = res.first + ll(k) * mid;
		} else {
			lo = mid + 1;
		}
	}
	cout << n - best << endl;
}

pll check(int n, int l, ll delta) {
	pll ans = solve(n, l, delta);
	for (auto& i : s) {
		i ^= 1;
	}
	return max(ans, solve(n, l, delta));
}

pll solve(int n, int l, ll delta) {
	vector<pll> dp(n + 1);
	dp[0] = {0, 0};
	for (int i = 1; i <= n; ++i) {
		pll cand1 = {dp[i - 1].first + s[i], dp[i - 1].second};
		int len = min(i, l);
		pll cand2 = {dp[i - len].first + len - delta, dp[i - len].second - 1};
		dp[i] = max(cand1, cand2);
	}
	return dp[n];
}