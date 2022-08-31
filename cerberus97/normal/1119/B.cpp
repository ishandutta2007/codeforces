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

int a[N];

int main() {
	fast_cin();
	int n, h;
	cin >> n >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int k = n; k >= 1; --k) {
		vector<int> b;
		for (int i = 1; i <= k; ++i) {
			b.pb(a[i]);
		}
		sort(b.begin(), b.end());
		int s = b.size();
		ll sum = 0;
		for (int i = s - 1; i >= 0; i -= 2) {
			sum += b[i];
		}
		if (sum <= h) {
			cout << k << endl;
			return 0;
		}
	}
}