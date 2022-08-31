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
	vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	map<string, int> id;
	int sz = digits.size();
	vector<int> cnt(sz);
	for (int i = 0; i < sz; ++i) {
		id[digits[i]] = i;
		cnt[i] = count(digits[i].begin(), digits[i].end(), '1');
	}
	int n, k;
	cin >> n >> k;
	vector<string> num(n);
	for (auto& i : num) {
		cin >> i;
	}
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
	dp[n][0] = 0;
	for (int i = n - 1; i >= 0; --i) {
		vector<bool> valid(sz, true);
		for (int d = 0; d < sz; ++d) {
			for (int l = 0; l < digits[0].size(); ++l) {
				if (num[i][l] == '1' and digits[d][l] == '0') {
					valid[d] = false;
					break;
				}
			}
			// cout << i << ' ' << d << ' ' << valid[d] << endl;
		}
		int cur_cnt = count(num[i].begin(), num[i].end(), '1');
		for (int j = 0; j <= k; ++j) {
			for (int d = sz - 1; d >= 0; --d) {
				int diff = (cnt[d] - cur_cnt);
				if (valid[d] and diff >= 0 and diff <= j and dp[i + 1][j - diff] != -1) {
					dp[i][j] = d;
					break;
				}
			}
		}
	}
	if (dp[0][k] == -1) {
		cout << -1 << '\n';
	} else {
		int j = k;
		for (int i = 0; i < n; ++i) {
			int cur_cnt = count(num[i].begin(), num[i].end(), '1');
			cout << dp[i][j];
			j -= (cnt[dp[i][j]] - cur_cnt);
		}
	}
}