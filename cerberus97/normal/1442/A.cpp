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
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		vector<int> b(n);
		b[0] = a[0];
		for (int i = 1; i < n; ++i) {
			b[i] = min(min(a[i], b[i - 1]), a[i] - a[i - 1] + b[i - 1]);
		}
		if (b[n - 1] >= 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}