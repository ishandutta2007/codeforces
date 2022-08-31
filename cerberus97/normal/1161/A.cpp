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

const int N = 1e5 + 10;

int x[N], first[N], last[N];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; ++i) {
		first[i] = k + 1;
		last[i] = 0;
	}
	for (int i = k; i >= 1; --i) {
		first[x[i]] = i;
	}
	for (int i = 1; i <= k; ++i) {
		last[x[i]] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = max(1, i - 1); j <= min(n, i + 1); ++j) {
			if (last[j] < first[i]) {
				++ans;
			}
		}
	}
	cout << ans << endl;
}