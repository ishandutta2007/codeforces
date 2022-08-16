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

const int N = 710;

int a[N];
bool dp[N][N][2], edge[N][N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			edge[i][j] = (__gcd(a[i], a[j]) > 1);
		}
	}
	for (int i = 1; i <= n + 1; ++i) {
		dp[i][i - 1][0] = true;
		dp[i][i - 1][1] = true;
	}
	for (int len = 1; len <= n; ++len) {
		for (int i = 1; i <= n; ++i) {
			int j = i + len - 1;
			if (j > n) {
				break;
			}
			for (int k = i; k <= j; ++k) {
				if (dp[i][k - 1][1] and dp[k + 1][j][0]) {
					if (edge[i - 1][k]) {
						dp[i][j][0] = true;
					}
					if (edge[j + 1][k]) {
						dp[i][j][1] = true;
					}
				}
			}
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = i; j <= n; ++j) {
	// 		cout << i << ' ' << j << ' ';
	// 		cout << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
	// 	}
	// }
	if (dp[1][n][0]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}