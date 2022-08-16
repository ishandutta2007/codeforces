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

const int N = 2e5 + 10, inf = 1e9 + 42;

int a[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		bool ok = false;
		for (int i = 1; i < n; ++i) {
			if (abs(a[i] - a[i + 1]) >= 2) {
				cout << "YES\n";
				cout << i << ' ' << i + 1 << '\n';
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "NO\n";
		}
	}
}