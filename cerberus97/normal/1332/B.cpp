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
		vector<int> col(n, 0);
		map<int, int> mp;
		int m = 0;
		for (int i = 0; i < n; ++i) {
			int p = -1;
			for (int j = 2; j <= a[i]; ++j) {
				if (a[i] % j == 0) {
					p = j;
					break;
				}
			}
			if (!mp.count(p)) {
				mp[p] = ++m;
			}
			col[i] = mp[p];
		}
		cout << m << '\n';
		for (auto& c : col) {
			cout << c << ' ';
		}
		cout << '\n';
	}
}