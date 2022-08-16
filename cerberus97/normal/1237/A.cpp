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

int a[N], lo[N], hi[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] >= 0) {
			lo[i] = a[i] / 2;
		} else {
			lo[i] = a[i] / 2 - (a[i] % 2 ? 1 : 0);
		}
		hi[i] = lo[i] + (a[i] % 2 ? 1 : 0);
		sum += lo[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (sum < 0 and lo[i] < hi[i]) {
			lo[i] = hi[i];
			++sum;
		}
		cout << lo[i] << '\n';
	}
}