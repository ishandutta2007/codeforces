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

const int N = 20;

ll a[N], b[N];

ll solve(int i, int n);

int main() {
	int n = 14;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, solve(i, n));
	}
	cout << ans;
}

ll solve(int i, int n) {
	if (a[i] == 0) {
		return 0;
	} else {
		for (int j = 0; j < n; ++j) {
			b[j] = a[j];
		}
		ll cyc = (b[i] / n), ext = (b[i] % n);
		b[i] = 0;
		for (int j = (i + 1) % n; ; j = (j + 1) % n) {
			b[j] += cyc;
			if (ext) {
				++b[j];
				--ext;
			}
			if (j == i) {
				break;
			}
		}
		ll ans = 0;
		for (int j = 0; j < n; ++j) {
			if (!(b[j] & 1)) {
				ans += b[j];
			}
		}
		return ans;
	}
}