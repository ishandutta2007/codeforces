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
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll inf = 4e18 + 42;

int main() {
	fast_cin();
	int n, m; ll k;
	cin >> n >> m >> k;
	string s; cin >> s;
	vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			lcp[j][i] = lcp[i][j] = (s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0);
		}
	}
	vector<pii> substrings;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			substrings.pb({j, i});
		}
	}
	sort(substrings.begin(), substrings.end(), [&] (const pii& s1, const pii& s2) {
		int len1 = s1.second - s1.first + 1;
		int len2 = s2.second - s2.first + 1;
		int common = lcp[s1.first][s2.first];
		if (common >= min(len1, len2)) {
			return len1 < len2;
		} else {
			return s[s1.first + common] < s[s2.first + common];
		}
	});
	int sz = substrings.size();
	vector<vector<int>> id(n, vector<int>(n));
	for (int i = 0; i < sz; ++i) {
		id[substrings[i].first][substrings[i].second] = i;
	}
	int lo = 1, hi = sz;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		vector<ll> f(n + 1, n), dp(n + 1, 0), sum(n + 2, 0);
		for (int i = 0; i < n; ++i) {
			f[i] = i;
			while (f[i] < n and id[i][f[i]] < mid) {
				++f[i];
			}
		}
		dp[n] = 1;
		for (int j = 0; j < m; ++j) {
			for (int i = n; i >= 0; --i) {
				sum[i] = min(k, dp[i] + sum[i + 1]);
				dp[i] = sum[f[i] + 1];
			}
		}
		if (dp[0] >= k) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	int l = substrings[lo - 1].first, r = substrings[lo - 1].second;
	cout << s.substr(l, r - l + 1) << endl;
}