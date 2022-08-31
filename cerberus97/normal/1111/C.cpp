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

ll arr[N];
ll a, b;

ll solve(int i, int j, int l, int r);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k >> a >> b;
	for (int i = 1; i <= k; ++i) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + k);
	cout << solve(1, k, 1, (1 << n)) << endl;
}

ll solve(int i, int j, int l, int r) {
	if (i > j) {
		return a;
	} else if (l == r) {
		return b * ll(j - i + 1);
	}
	int p = (l + r) / 2;
	int lo = i, hi = j;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] <= p) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	int s = lo - 1;
	ll best = solve(i, s, l, p) + solve(s + 1, j, p + 1, r);
	best = min(best, b * ll(j - i + 1) * ll(r - l + 1));
	return best;
}