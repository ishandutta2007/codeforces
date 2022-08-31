/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, inf = 1e9;

char s[N];
int dp[N][2];

int main() {
	int n;
	cin >> n >> (s + 1);
	dp[1][0] = 1;
	dp[1][1] = inf;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
		if (s[i] != s[i - 1]) {
			dp[i][1] = 1 + min(dp[i - 2][0], dp[i - 2][1]);
		} else {
			dp[i][1] = inf;
		}
	}
	cout << min(dp[n][0], dp[n][1]);
}