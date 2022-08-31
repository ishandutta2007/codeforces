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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		int gaps = 0;
		for (int i = 1; i < n; ++i) {
			gaps += (a[i] != a[i - 1]);
		}
		if (a[n - 1] == 0) {
			cout << 0 << '\n';
		} else if (gaps and k == 1) {
			cout << -1 << '\n';
		} else if (k == 1) {
			cout << 1 << '\n';
		} else {
			cout << max(1, (gaps + k - 2) / (k - 1)) << '\n';
		}
	}
}