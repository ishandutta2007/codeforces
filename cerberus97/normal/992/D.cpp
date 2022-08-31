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

const int N = 2e5 + 10;
const ll inf = 2e18 + 42;

ll a[N], skip[N];

int main() {
	int n; ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] == 1) {
			skip[i] = skip[i + 1] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ll sum = 0, prod = 1;
		for (int j = i; j <= n; ++j) {
			if (double(prod) * a[j] > inf) {
				break;
			}
			prod *= a[j];
			sum += a[j];
			if (prod == sum * k) {
				++ans;
			}
			if (skip[j] > 1) {
				if (prod % k == 0) {
					ll temp = prod / k;
					if (sum < temp and temp <= sum + skip[j] - 1) {
						++ans;
					}
				}
				sum += skip[j] - 1;
				j += skip[j] - 1;
			}
		}
	}
	cout << ans;
}