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

const int N = 2e3 + 10;
const int inf = 1e9;

ll a[N];

ll gcd(ll a, ll b);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	// for (int i = 1; i <= n; ++i) {
	// 	ll temp = a[i];
	// 	g[i][i] = a[i];
	// 	for (int j = i + 1; j <= n; ++j) {
	// 		temp = gcd(temp, a[i]);
	// 		g[i][j] = temp;
	// 	}
	// }

	// if (g[1][n] > 1) {
	// 	cout << -1;
	// 	return 0;
	// }

	int ans = inf;
	for (int i = 1; i <= n; ++i) {
		// int l = 0, r = n - 2;
		// while (l <= r) {
		// 	int mid = (l + r) / 2;
		// 	for (int s = max(i - mid, 1); s <= i; ++s) {
		// 		int t = s + mid;
		// 		if (t > n) {
		// 			l = mid + 1;
		// 			break;
		// 		}
		// 		if (g[s][t] > 1) {
		// 			l = mid + 1;
		// 			break;
		// 		}
		// 		int temp = mid;
		int g = a[i];
		for (int j = i; j <= n; ++j) {
			g = gcd(g, a[j]);
			if (g == 1) {
				int temp = j - i;
				for (int k = 1; k < i; ++k) {
					if (a[k] != 1) {
						++temp;
					}
				}
				for (int k = i + 1; k <= n; ++k) {
					if (a[k] != 1) {
						++temp;
					}
				}
				ans = min(ans, temp);
				break;
			}
		}
	}

	if (ans == inf) {
		cout << -1;
	} else {
		cout << ans;
	}
}

ll gcd(ll x, ll b) {
	if (!b) {
		return x;
	} else {
		return gcd(b, x % b);
	}
}