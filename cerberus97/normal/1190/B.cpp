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

ll a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ll num_moves = sum - ((n * (n - 1)) / 2);
	sort(a + 1, a + 1 + n);
	bool ok = true;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1]) {
			if (!a[i]) {
				ok = false;
			} else {
				--a[i];
			}
			break;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1]) {
			ok = false;
			break;
		}
	}
	if (!ok or num_moves % 2 == 0) {
		cout << "cslnb\n";
	} else {
		cout << "sjfnb\n";
	}
}