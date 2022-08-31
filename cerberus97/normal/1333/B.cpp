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
		vector<int> a(n), b(n);
		for (auto& i : a) {
			cin >> i;
		}
		for (auto& i : b) {
			cin >> i;
		}
		bool neg = false, pos = false, ans = true;
		for (int i = 0; i < n and ans; ++i) {
			if (a[i] < b[i] and !pos) {
				ans = false;
			} else if (a[i] > b[i] and !neg) {
				ans = false;
			}
			if (a[i] > 0) {
				pos = true;
			} else if (a[i] < 0) {
				neg = true;
			}
		}
		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}