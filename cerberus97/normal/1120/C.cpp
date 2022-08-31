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

const int N = 5e3 + 10;

int dp[N], mx[N];

vector<int> compute_Z(string s);

int main() {
	fast_cin();
	int n, a, b; string s;
	cin >> n >> a >> b >> s;
	for (int i = 1; i <= n; ++i) {
		string temp = s.substr(i, n) + '$' + s.substr(0, i);
		vector<int> z = compute_Z(temp);
		int ctr = 0;
		for (int j = n - i + 1; j < n + 1; ++j) {
			ctr = max(ctr, z[j]);
		}
		mx[i] = i + ctr;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = a + dp[i - 1];
		for (int j = i - 1; j >= 1; --j) {
			if (mx[j] >= i) {
				dp[i] = min(dp[i], b + dp[j]);
			} else {
				break;
			}
		}
	}
	cout << dp[n] << endl;
}

vector<int> compute_Z(string s) {
	int n = s.length();
	vector<int> z(n, 0);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}