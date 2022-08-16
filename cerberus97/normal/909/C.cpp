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

const int N = 5e3 + 10, mod = 1e9 + 7;

char s[N];
ll dp[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	dp[0][0] = 1;
	s[0] = 's';
	for (int i = 1; i <= n; ++i) {
		for (int j = n; j >= 0; --j) {
			if (s[i - 1] == 'f') {
				if (j) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}

		if (s[i] == 's') {
			for (int j = n - 1; j >= 0; --j) {
				dp[i][j] += dp[i][j + 1];
				dp[i][j] %= mod; 
			}
		}
	}

	cout << dp[n][0] << endl;
}