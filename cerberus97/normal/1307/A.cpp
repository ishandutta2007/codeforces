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
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		int ans = a[0];
		for (int i = 1; i < n; ++i) {
			int take = min(a[i], d / i);
			d -= take * i;
			ans += take;
		}
		cout << ans << '\n';
	}
}