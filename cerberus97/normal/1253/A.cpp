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

int a[N], b[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
		}
		int l = n + 1, r = -1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				l = min(l, i);
				r = i;
			}
		}
		bool ok = (l > r) or (b[l] > a[l]);
		for (int i = l; i < r; ++i) {
			if (b[i] - a[i] != b[i + 1] - a[i + 1]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}