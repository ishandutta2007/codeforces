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

const int N = 4e5 + 10, LOG_N = log2(N) + 10;

int a[N];

int main() {
	fast_cin();
	int n, I;
	cin >> n >> I;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int max_k = min(LOG_N, (8 * I) / n);
	int max_K = (1 << max_k);
	int best = 0;
	sort(a + 1, a + 1 + n);
	int r = 1, ctr = 1;
	for (int l = 1; l <= n; ++l) {
		while (r < n and ctr + (a[r] != a[r + 1]) <= max_K) {
			ctr += (a[r] != a[r + 1]);
			++r;
		}
		best = max(best, r - l + 1);
		while (l < n and a[l + 1] == a[l]) {
			++l;
		}
		--ctr;
	}
	cout << n - best << endl;
}