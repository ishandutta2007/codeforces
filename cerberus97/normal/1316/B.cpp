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
	int tc; cin >> tc;
	while (tc--) {
		int n; string s;
		cin >> n >> s;
		string best = s;
		int ans = 1;
		for (int k = 2; k <= n; ++k) {
			string t = s.substr(k - 1, n);
			string tmp = s.substr(0, k - 1);
			t += (((n + k) % 2) ? tmp : string(tmp.rbegin(), tmp.rend()));
			if (t < best) {
				best = t;
				ans = k;
			}
		}
		cout << best << '\n' << ans << '\n';
	}
}