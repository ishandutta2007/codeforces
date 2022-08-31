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

const int N = 2e5 + 10;

ll a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		ll best = -1, best_dist = a[n];
		for (int l = 1, r = k + 1; r <= n; ++l, ++r) {
			if (a[r] - a[l] <= best_dist) {
				best_dist = a[r] - a[l];
				best = (a[r] + a[l]) / 2;
			}
		}
		cout << best << '\n';
	}
}