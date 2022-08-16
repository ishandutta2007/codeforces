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

const int N = 1e5 + 10, mod = 11;

int dp[N][mod];

int sum_till(int x);

int main() {
	fast_cin();
	// map<int, int> mp;
	// for (int i = 1; i <= 9; ++i) {
	// 	mp[i] = i;
	// 	cout << i << ' ' << i << endl;
	// }
	// int id = 10;
	// for (int i = 10; i < 500; ++i) {
	// 	if (mp.count(i / 10) and i % 10 < mp[i / 10] % 11) {
	// 		mp[i] = id;
	// 		cout << id << ' ' << id % 11 << ' ' << i << ' ';
	// 		cout << '\n';
	// 		++id;
	// 	}
	// }
	// s[0] = -1; s[1] = 0;
	// for (int i = 2; i < 500; ++i) {
	// 	s[i] = sum_till(s[i - 1]) - sum_till(s[i - 2] - 1);
	// }
	// for (int i = 0; i < 500; ++i) {
	// 	cout << i << ' ' << s[i] << endl;
	// }
	string s; cin >> s;
	int n = s.length();
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int id = 0; id < mod; ++id) {
			if (id <= (s[i] - '0')) {
				continue;
			}
			int n_id = (sum_till(id - 1) + (s[i] - '0') - 1 + mod) % mod;
			dp[i][id] = 1 + dp[i + 1][n_id];
		}
		if (s[i] != '0') {
			ans += dp[i][mod - 1];
		}
	}
	cout << ans << endl;
}

int sum_till(int x) {
	x %= mod;
	x += mod;
	int ans = (x * (x + 1)) / 2;
	return ans % mod;
}