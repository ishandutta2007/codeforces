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
		int n; cin >> n;
		vector<int> p(n), c(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i] >> c[i];
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			ok &= (c[i] <= p[i]);
			if (i < n - 1) {
				ok &= (p[i] <= p[i + 1]);
				ok &= (c[i] <= c[i + 1]);
				ok &= ((c[i + 1] - c[i]) <= (p[i + 1] - p[i]));
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}