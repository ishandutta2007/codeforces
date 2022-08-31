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

const int N = 1e6 + 10, inf = 1e9;

bool seen[N][2];
int dp[N][2];
string a, b;

int solve(int n, char c);

int main() {
	fast_cin();
	int n;
	cin >> n >> a >> b;
	cout << solve(n - 1, a[n - 1]) << endl;
}

int solve(int n, char c) {
	if (n == 0) {
		return !(c == b[0]);
	} else if (seen[n][c - '0']) {
		return dp[n][c - '0'];
	} else {
		seen[n][c - '0'] = true;
		int ans = inf;
		ans = min(ans, !(c == b[n]) + solve(n - 1, a[n - 1]));
		ans = min(ans, 1 + !(a[n - 1] == b[n]) + solve(n - 1, c));
		dp[n][c - '0'] = ans;
		return ans;
	}
}