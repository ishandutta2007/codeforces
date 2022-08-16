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
 
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; ll a, b; string s;
		cin >> n >> a >> b >> s;
		s += '0';
		vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
		dp[0][0] = b;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 2 * b + (1 - j) * a);
				if (s[i] == '0' and s[i + 1] == '0') {
					dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + b + j * a);
				}
			}
		}
		cout << dp[n][0] + a * n << '\n';
	}
}