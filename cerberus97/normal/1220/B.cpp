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

const int N = 1e3 + 10;
const ll M = 1e9 + 10;

ll a[N][N], ans[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	ll temp = (a[1][2] * a[1][3]) / a[2][3];
	ll lo = 1, hi = M; 
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (mid * mid == temp) {
			ans[1] = mid;
			break;
		} else if (mid * mid < temp) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	for (int i = 2; i <= n; ++i) {
		ans[i] = a[1][i] / ans[1];
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}