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
		string s;
		cin >> n >> k >> s;
		vector<int> edges;
		int groups = 0, cur = 0;
		char prv = 'L';
		for (auto& c : s) {
			if (c == 'W' and prv == 'L') {
				if (groups) {
					edges.pb(cur);
				}
				++groups;
			}
			cur = (c == prv ? cur + 1 : 1);
			prv = c;
		}
		if (!groups and k) {
			s[0] = 'W';
			--k;
			groups = 1;
		}
		int ans = 2 * (count(s.begin(), s.end(), 'W') + min(int(count(s.begin(), s.end(), 'L')), k));
		sort(edges.begin(), edges.end());
		for (auto& i : edges) {
			if (k >= i) {
				k -= i;
				--groups;
			}
		}
		ans -= groups;
		cout << ans << '\n';
	}
}