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
		vector<int> p(n);
		for (auto& i : p) {
			cin >> i;
		}
		bool ok = true;
		vector<int> blocks = {n + 1};
		for (int i = 0; i < n; ++i) {
			if (p[i] < blocks.back()) {
				blocks.pb(p[i]);
			} else if (p[i] != blocks.back() + 1) {
				ok = false;
				break;
			} else {
				++blocks.back();
			}
		}
		if (ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}