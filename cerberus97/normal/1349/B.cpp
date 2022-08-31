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
		bool have_k = false, all_k = true;
		for (auto& i : a) {
			cin >> i;
			have_k |= (i == k);
			all_k &= (i == k);
		}
		bool seg = false;
		for (int i = 0; i < n - 1; ++i) {
			seg |= (a[i] >= k and a[i + 1] >= k);
			if (i < n - 2) {
				seg |= (a[i] >= k and a[i + 2] >= k);
			}
		}
		if (all_k or (have_k and seg)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}